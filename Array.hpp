#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "sort.hpp"

#ifndef _ARR_H_
#define _ARR_H_



namespace numpp
{
	enum sort_type
	{
		BUBBLE,SELECTION
	};

	template <typename T> class Array{
		public:
			std::vector<T> value;
			
			Array();
			Array(T[],int);
			Array(int,int=0,int=1);
			
			int shape();
			void sort(sort_type = BUBBLE,bool = true);
			T max();
			T min();
			T mean();
			T sum();
	};
	
	
	template <typename T> void print(Array<T> val);

	
	// Constructors
	template <typename T> Array<T>::Array()
	{
		//does nothing
	}
	
	/**
	* Constructor for an Array object given a primitive array and length of array.
	*
	* PARAMS:
	* 	T input[]: The primitive array required to be converted to Array object.
	* 	int len: length of primitive array.
	*/
	
	template <typename T> Array<T>::Array(T input[],int len)
	{	
		for(int i=0;i<len;i++)
		{
			value.push_back(input[i]);
		}
	}
	
	/**
	* Constructor for an Array object with given length, each element initialised to random values.
	*
	* PARAMS:
	* 	int length: length of Array objects values.
	* 	int min: min value for randomizer. Defaults to 0.
	* 	int max: max value for randomizer. Defaults to 1.
	*
	* NOTE: min and max are used only when T is float/int. Unaffected in other template classes
	*/
	
	template<typename T> Array<T>::Array(int length,int min,int max)
	{
		std::vector<T> temp(length);
		value = temp;
		if(min!=0 || max!=1)
		{
			std::cerr<<"Cannot randomize.";
		}
	}
	
	/**
	* Return an array of floating point values ranging from min to max.
	*/
	
	template <> Array<float>::Array(int length,int min,int max)
	{
		time_t nTime;
		srand((unsigned) time(&nTime));
		for(int i=0;i<length;i++)
		{
			value.push_back((float(rand()%1000)/1000)*(float(max)-min)+float(min));
		}
	}
	
	/**
	* Return an array of integer values ranging from min to max.
	* In the default case return between 0 and 100.
	*/
	
	template <> Array<int>::Array(int length,int min,int max)
	{
		if(max-min<=1)
		{
			min = 0;
			max = 100;
		}
		time_t nTime;
		srand((unsigned) time(&nTime));
		for(int i=0;i<length;i++)
		{
			value.push_back(int((float(rand()%1000)/1000)*(float(max)-min)+float(min)));
		}
	}

	/**
	* Returns the size(length) of an Array object.
	* PARAMS:
	*
	* RETURN:
	* 	 int: length of Array
	*/
	
	template <typename T> int Array<T>::shape()
	{
		return value.size();
	}
	
	/**
	* Sorts the Array
	* PARAMS
	* RETURN
	*/
	template <typename T> void Array<T>::sort(sort_type type,bool ascending)
	{

	}

	/**
	* Prints value of each element.
	* If data cannot be printed, prints reference to data.
	*
	* PARAMS:
	*	 Array<T> val : input of numpp::Array object.
	* RETURN:
	*	 void : prints values to console.
	*/
	
	template <typename T> void print(Array<T> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<&(val.value[i]);
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<int> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}

	template <> void print(Array<char> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<float> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<double> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<long> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<short> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}
	
	template <> void print(Array<std::string> val)
	{
		std::cout<<"[";
		for(int i=0;i<val.value.size();i++)
		{
			std::cout<<val.value[i];
			if(i!=val.value.size()-1)
				std::cout<<",";
		}
		std::cout<<"]"<<std::endl;
	}

	template <typename T>T Array<T>::max()
	{
		T max = value[0];
		for(int i=0;i<value.size();i++)
		{
			if(value[i]>max)
				max = value[i];
		}
		return max;
	}

	template <typename T>T Array<T>::min()
	{
		T min = value[0];
		for(int i=0;i<value.size();i++)
		{
			if(value[i]<min)
				min = value[i];
		}
		return min;
	}

	template <typename T>T Array<T>::mean()
	{
		T sum = 0;
		for(int i=0;i<value.size();i++)
		{
			sum += value[i];
		}
		return sum/value.size();
	}

	template <typename T>T Array<T>::sum()
	{
		T sum = 0;
		for(int i=0;i<value.size();i++)
		{
			sum += value[i];
		}
		return sum;
	}

}

#endif
