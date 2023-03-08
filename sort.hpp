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

	template<typename T,int N> void bubble_sort(std::string (&r)[N],bool ascending=true)
	{
		if(ascending)
		{
			for(int i=0;i<N-1;i++)
			{
				for(int j=0;j<N-1-i;j++)
				{
					if(*(r+j).compare(*(r+j+1))>0)
					{
						std::string temp;
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
					if(*(r+j).compare(*(r+j+1))<0)
					{
						std::string temp;
						temp = *(r+j);
						*(r+j) = *(r+j+1);
						*(r+j+1) = temp;
					}
				}
			}
		}
	}

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

	template <typename T> void bubble_sort(std::vector<std::string> value,bool ascending=true)
	{
		if(ascending)
		{
			for(int i=0;i<value.size()-1;i++)
			{
				for(int j=0;j<value.size()-1-i;j++)
				{
					if(value[j].compare(value[j+1])>0)
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
					if(value[j].compare(value[j+1])<0)
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
        for(int i=0;i<N;i++)
        {
            int min = *(r+i),min_index = i;
            for(int j=i;j<N;j++)
            {
                if()
            }
        }
    }

}
