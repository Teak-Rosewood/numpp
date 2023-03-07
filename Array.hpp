#include <vector>
#include <iostream>

namespace numpp
{
	template<class T, int N> int size(T (&r)[N]){
		return N;
	}
	
	template <typename T> class Array{
		public:
			std::vector<T> value;
			
			Array(T input[],int len);
			Array(T input);
	};
	
	// Function definitions of class Array
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
	
	
	
	template <typename T> static void print(Array<T> val)
	{
		try{
			for(auto i:val.value)
			{
				std::cout<<i<<" ";
			}
		}
		catch(...)
		{
			return;
		}
	}
	
}
