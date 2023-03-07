#include <vector>
#include <iostream>

namespace numpp
{
	template <typename T> void print(Array<T> val);
	template <typename T> void printRef(Array<T> val);
	template<class T, int N> Array<T> toArray(T (&r)[N]);
	template<class T, int N> int size(T (&r)[N]);
	
	template <typename T> class Array{
		public:
			std::vector<T> value;
			
			Array();
			Array(T input[],int len);
			Array(T input);
	};
	
	// Constructors
	template <typename T> Array<T>::Array()
	{
		//does nothing
	}
	
	template <typename T> Array<T>::Array(T input[],int len)
	{	
		for(int i=0;i<len;i++)
		{
			value.push_back(input[i]);
		}
	}
	
	template <typename T> Array<T>::Array(T input)
	{
		value.push_back(input);
	}
	
	/*
	Prints value of each element.
	Throws a compile time error if data cannot be binded to std::ostream
	Use void printRef(Array<T>) for such data types.
	
	PARAMS:
		Array<T> val : input of numpp::Array object.
	RETURN:
		void : prints values to console.
	*/
	
	template <typename T> void print(Array<T> val)
	{
		for(T i:val.value)
		{
				std::cout<<i<<" ";
		}
	}
	
	/*
	Print reference to objects, can be a security hazard (USE WITH CAUTION)
	
	PARAMS:
		Array<T> val : input of numpp::Array object.
	RETURN:
		void : prints address to console.
	*/
	
	template <typename T> void printRef(Array<T> val)
	{
		for(T i:val.value)
		{
				std::cout<<&i<<" ";
		}
	}
	
	/*
	Allows conversion of arrays to Array object without information about size.
	
	PARAMS:
		T (&r)[N] : input of array of type T(template)
	RETURN:
		Array<T> : numpp::Array object
	*/
	
	template<class T, int N> Array<T> toArray(T (&r)[N])
	{
		Array<T> array;
		for(int i=0;i<N;i++)
		{
			array.value.push_back(*(r+i));
		}
		return array;
	}
	
	/*
	returns size of any array.
	
	PARAMS:
		T (&r)[N] : input of array of type T(template)
	RETURN:
		int : size of array
	*/
	template<class T, int N> int size(T (&r)[N])
	{
		return N;
	}	
}
