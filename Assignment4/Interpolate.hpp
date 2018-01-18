
#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

#include <iostream>
#include <string>
#include <type_traits>
#include <tuple>
#include <iomanip>

namespace cs540
{

	struct WrongNumberOfArgs : public std::exception { };

	auto ffr(std::ostream&(*funcPtr)(std::ostream&))
	{
		return funcPtr;
	}

	template<typename...Rest>
	struct MyFormatter
	{
	
		const char* fmtSpec;
		std::tuple<const Rest&...> args;

		MyFormatter(const char *fmt, const Rest&...argsT) : fmtSpec(fmt), args(argsT...) { }

		template<typename CharT, typename Traits>
		friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& out, const MyFormatter &myFormatter)
		{
			myFormatter.toStream(out, myFormatter.fmtSpec, std::make_index_sequence<std::tuple_size<decltype(myFormatter.args)>::value>{});
			return out;
		}

		template <typename CharT, typename Traits, std::size_t... indices>	
		void toStream(std::basic_ostream<CharT, Traits>& out, const char *fmt, std::index_sequence<indices...>) const
    		{
			myFormat(out, fmt, std::get<indices>(this -> args)...);
    		}	
		
		template <typename CharT, typename Traits>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt) 
		{
			const char *p = fmt;
			while(*p) 
			{
				if(*p == '%')
				{
					if(*(p - 1) == '\\')
					{
						// Backspace doesn't work properly why ?
						long cursorPos = out.tellp();
						out.seekp(cursorPos - 1);
						out << *p++;
						continue;
					}
					throw WrongNumberOfArgs();	
				}
				else
				{
					out << *p++;
				}
			}
		}


		template <typename CharT, typename Traits, typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, std::ios_base&(*fp)(std::ios_base&), const RestA&... args) 
		{
			out << fp;
			myFormat(out, fmt, args...);
			return;
		}


		template <typename CharT, typename Traits, typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, std::basic_ostream<CharT, Traits>&(*fp)(std::basic_ostream<CharT, Traits>&),
					const RestA&... args)
		{
			std::ostream& (*funcPtr)(std::ostream&) = std::flush;
			bool valueUsed = false;
                        const char *p = fmt;
			if(funcPtr == fp)
			{
				out << fp;
				myFormat(out, p, args...);
				return;
			}
                        while(*p)
                        {
                                if(*p == '%')
                                {
                                        p++;
                                        out << fp;
                                        valueUsed = true;
                                        myFormat(out, p, args...);
                                        return;
                                }
                                else
                                {
                                        if(*p == '\\')
                                        {
                                                ++p;
                                                out << *p++;
                                        }
                                        else
                                                out << *p++;
                                }
                        }
                        if(!valueUsed)
                                throw WrongNumberOfArgs();
		}


		template <typename CharT, typename Traits, typename T, 
			typename std::enable_if<std::is_same<decltype(std::setbase(std::declval<int>())), typename std::decay<T>::type>::value, int>::type = 0, 
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }
		
		template <typename CharT, typename Traits, typename T,
			typename std::enable_if<std::is_same<decltype(std::setprecision(std::declval<int>())), typename std::decay<T>::type>::value, int>::type = 0,
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }

		template <typename CharT, typename Traits, typename T,
			typename std::enable_if<std::is_same<decltype(std::setw(std::declval<int>())), typename std::decay<T>::type>::value, int>::type = 0,
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }

		template <typename CharT, typename Traits, typename T,
			typename std::enable_if<std::is_same<decltype(std::setfill(std::declval<char>())), typename std::decay<T>::type>::value, int>::type = 0,
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }


		template <typename CharT, typename Traits, typename T,
			typename std::enable_if<std::is_same<decltype(std::setiosflags(std::ios_base::hex)), typename std::decay<T>::type>::value, int>::type = 0,
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }

		template <typename CharT, typename Traits, typename T,
			typename std::enable_if<std::is_same<decltype(std::resetiosflags(std::ios_base::hex)), typename std::decay<T>::type>::value, int>::type = 0,
			typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args)
                {
                        out << value;
                        myFormat(out, fmt, args...);
			return;
                }

		

		template <typename CharT, typename Traits, typename T, typename... RestA>
		static void myFormat(std::basic_ostream<CharT, Traits>& out, const char* fmt, const T& value, const RestA&... args) 
		{
			bool valueUsed = false;
			const char *p = fmt;
			while(*p)
                        {
                                if(*p == '%')
                                {
                                        p++;
                                        out << value;
					valueUsed = true;
                                        myFormat(out, p, args...);
					return;
                                }
                                else
                                {
					if(*p == '\\')
					{
						++p;
                                        	out << *p++;
					}
					else
						out << *p++;
                                }
                        }
			if(!valueUsed)
				throw WrongNumberOfArgs();
		}	
	};

	template <typename... Rest>
		auto Interpolate(const char* fmtSpec, Rest&&...args)
		{
			return MyFormatter<Rest...>(fmtSpec, args...);
		}	
}


#endif
