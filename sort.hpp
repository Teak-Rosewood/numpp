#include <vector>
#include <iostream>
#include <string>

namespace numpp
{
	/*
	bubble sort for various data types(arrays and vectors)

	PARAMS:

	RETURN:

	*/

	template<class T,int N> void bubble_sort(T (&r)[N],bool ascending=true)
	{
		if(ascending)
		{
			for(int i=0;i<N-1;i++)
			{
				for(int j=0;j<N-1-i;j++)
				{
					if(*(r+j)>*(r+j+1))
					{
						T temp;
						temp = *(r+j);
						*(r+j) = *(r+j+1);
						*(r+j+1) = temp;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<N-1;i++)
			{
				for(int j=0;j<N-1-i;j++)
				{
					if(*(r+j)<*(r+j+1))
					{
						T temp;
						temp = *(r+j);
						*(r+j) = *(r+j+1);
						*(r+j+1) = temp;
					}
				}
			}
		}
	}

//not working
	template <typename T> void bubble_sort(std::vector<T> value,bool ascending=true)
	{
		if(ascending)
		{
			for(int i=0;i<value.size()-1;i++)
			{
				for(int j=0;j<value.size()-1-i;j++)
				{
					if(value[j] > value[j+1])
					{
						T temp;
						temp = value[j];
						value[j] = value[j+1];
						value[j+1] = temp;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<value.size()-1;i++)
			{
				for(int j=0;j<value.size()-1-i;j++)
				{
					if(value[j] < value[j+1])
					{
						T temp;
						temp = value[j];
						value[j] = value[j+1];
						value[j+1] = temp;
					}
				}
			}
		}
	}


    template<class T,int N> void selection_sort(T (&r)[N],bool ascending=true)
    {
		if(ascending)
		{
			for(int i=0;i<N;i++)
			{
				T min = *(r+i);
				int min_index = i;
				for(int j=i;j<N;j++)
				{
					if(*(r+j)<min)
					{
						min_index = j;
						min = *(r+j);
					}
				}
				T temp = *(r+i);
				*(r+i) = *(r+min_index);
				*(r+min_index) = temp;
			}
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				T max = *(r+i);
				int max_index = i;
				for(int j=i;j<N;j++)
				{
					if(*(r+j)>max)
					{
						max_index = j;
						max = *(r+j);
					}
				}
				T temp = *(r+i);
				*(r+i) = *(r+max_index);
				*(r+max_index) = temp;
			}
		}
    }
//not working
	template<class T> void selection_sort(std::vector<T> value,bool ascending=true)
    {
		if(ascending)
		{
			for(int i=0;i<value.size();i++)
			{
				T min = value[i];
				int min_index = i;
				for(int j=i;j<value.size();j++)
				{
					if(value[j]<min)
					{
						min_index = j;
						min = value[j];
					}
				}
				T temp = value[i];
				value[i] = value[min_index];
				value[min_index] = temp;
			}
		}
		else
		{
			for(int i=0;i<value.size();i++)
			{
				T max = value[i];
				int max_index = i;
				for(int j=i;j<value.size();j++)
				{
					if(value[j]>max)
					{
						max_index = j;
						max = value[j];
					}
				}
				T temp = value[i];
				value[i] = value[max_index];
				value[max_index] = temp;
			}
		}
    }

}
