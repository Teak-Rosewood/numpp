#include "Array.hpp"
#include "sort.hpp"

#ifndef _PRIM_ARR_
#define _PRIM_ARR_

namespace numpp
{
	template<class T, int N> Array<T> toArray(T (&r)[N]);
	template<class T, int N> int size(T (&r)[N]);
	template<class T, int N> void reverse(T (&r)[N]);

	/**
	* Allows conversion of arrays to Array object without information about size.
	*
	* PARAMS:
	* 	 T (&r)[N] : input of array of type T(template)
	* RETURN:
	*	 Array<T> : numpp::Array object
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
	
	/**
	* returns size of any array.
	*
	* PARAMS:
	*	 T (&r)[N] : input of array of type T(template)
	* RETURN:
	*	 int : size of array
	*/
	template<class T, int N> int size(T (&r)[N])
	{
		return N;
	}

	template<class T, int N> void reverse(T (&r)[N])
	{
		for(int i=0;i<N/2;i++)
		{
			swap(*(r+i),*(r+N-1-i));
		}
	}

}

#endif
