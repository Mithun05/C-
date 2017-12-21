#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "MyInt.hpp"
#include <time.h>

/**
 * Array Class
 */

namespace cs540
{
	class Array
	{
		private:
			// Class Member
			MyInt **myIntObj;
			size_t length;
		public:
			// Uniform Initializer List : Constructor
			Array(const std::initializer_list<size_t>& myIntObjList)
			{
				length = myIntObjList.size();
				myIntObj = new MyInt*[length];
				size_t i = 0;
				for(auto x : myIntObjList)
					myIntObj[i++] = new MyInt(x);
			}
			// Copy Constructor
			Array(const Array &other)
			{
				length = other.length;
				myIntObj = new MyInt*[length];
				size_t k = 0;
				for(size_t j = 0; j < other.length; j++) 
					myIntObj[k++] = new MyInt(*other.myIntObj[j]);
			}
			// Move Construtor
			Array(Array&& other)
			{
				length = other.length;
				myIntObj = new MyInt*[length];
				size_t k = 0;
				for(size_t j = 0; j < length; j++)
				{
					myIntObj[k++] = other.myIntObj[j];
					other.myIntObj[j] = nullptr;
				}
			}
			// Copy Assignment
			Array& operator=(const Array& other)
			{
				for(size_t i = 0; i < length; i++)
					delete myIntObj[i];

				delete [] myIntObj;

				length = other.length;
				myIntObj = new MyInt*[length];
				size_t k = 0;
				for(size_t j = 0; j < length; j++)
					myIntObj[k++] = new MyInt(*other.myIntObj[j]);
				return *this;				
			}
			// Move Assignment
			Array& operator=(Array&& other)
			{
				for(size_t i = 0; i < length; i++)
					delete myIntObj[i];

				delete [] myIntObj;

				length = other.length;
				myIntObj = new MyInt*[length];
				size_t k = 0;
				for(size_t j = 0; j < other.length; j++)
				{
					myIntObj[k++] = other.myIntObj[j];
					other.myIntObj[j] = nullptr;
				}
				return *this;
			}		
			// Destructor	
			~Array()
			{
				for(size_t i = 0; i < length; i++)
					delete myIntObj[i];

				delete [] myIntObj;
			}
			// Overloading ostream << operator
			friend std::ostream &operator<<(std::ostream &os, const Array &a) 
			{
				for(size_t i = 0; i < a.length; i++)
					os << *a.myIntObj[i] << " ";

				return os;
			}

			// Checking performance between Copy and Move Constructor and Assignment respectively
			static void move_performance_test()
			{
				std::cout << "\n";
				std::cout << "For 100000 iterations" << std::endl;	
				{
					{
						const size_t c = 100000;
						float cConstTotal = 0;
						float cAssigTotal = 0;
						clock_t t;
						for(size_t i = 0; i < c; i++)
						{
							Array a_i{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
							t = clock();
							Array a_i_c{a_i};
							t = clock() - t;
							cConstTotal += (((float)t)/CLOCKS_PER_SEC);
							Array a_c{1};
							t = clock();
							a_c = a_i_c;
							t = clock() - t;
							cAssigTotal += (((float)t)/CLOCKS_PER_SEC);
						}
						std::cout << "Copy constructor took " << cConstTotal << " seconds." << std::endl;
						std::cout << "Copy assignment  took " << cAssigTotal << " seconds." << std::endl;
					}	
					{
						const size_t c = 100000;
						float mCopyTotal = 0;
						float mAssigTotal = 0;
						clock_t t;
						for(size_t i = 0; i < c; i++)
						{
							Array a_i{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
							t = clock();
							Array a_m_i{std::move(a_i)};
							t = clock() - t;
							mCopyTotal += (((float)t)/CLOCKS_PER_SEC);
							Array a_ma_i{1};
							t = clock();
							a_ma_i = std::move(a_m_i);
							t = clock() - t;
							mAssigTotal += (((float)t)/CLOCKS_PER_SEC);	
						}
						std::cout << "Move constructor took " << mCopyTotal <<  " seconds." << std::endl;
						std::cout << "Move assignment  took " << mAssigTotal << " seconds." << std::endl;	
					}  
				}
			}
	};
}
#endif
