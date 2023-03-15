#include <vector>
#include <iostream>
#include <string>

#ifndef _SORT__
#define _SORT__

namespace numpp
{
	template<class T,int N> void bubble_sort(T (&r)[N],bool=true);
	template <typename T> void bubble_sort(std::vector<T> value,bool=true);
	template<class T,int N> void selection_sort(T (&r)[N],bool=true);
	template<class T> void selection_sort(std::vector<T> value,bool=true);
	template<class T,int N> void insertionSort(T (&r)[N],bool =true);
	template<typename T> void swap(T& , T& );
	template <typename T> T partition(T* ,int , int , int );
	template<typename T> void quickSortinner(T* , T , T ,int);
	template<typename T,int N> void quickSort(T (&r)[N],bool = true);

	/*
	bubble sort for various data types(arrays and vectors)

	PARAMS:

	RETURN:

	*/

	template<class T,int N> void bubble_sort(T (&r)[N],bool ascending)
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


    template<class T,int N> void selection_sort(T (&r)[N],bool ascending)
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

	template<class T,int N> void insertionSort(T (&r)[N],bool ascending)
	{
		if(ascending)
		{
			int i, key, j;
			for (i = 1; i < N; i++)
			{
				key = *(r+i);
				j = i - 1;
				while (j >= 0 && *(r+j) > key)
				{
					*(r+j + 1) = *(r+j);
					j = j - 1;
				}
				*(r+j + 1) = key;
			}
		}
		else
		{
			int i, key, j;
			for (i = 1; i < N; i++)
			{
				key = *(r+i);
				j = i - 1;
				while (j >= 0 && *(r+j) < key)
				{
					*(r+j + 1) = *(r+j);
					j = j - 1;
				}
				*(r+j + 1) = key;
			}
		}
	}

	template<typename T> void swap(T& a, T& b)
	{
		T t = a;
		a = b;
		b = t;
	}

	template <typename T> T partition(T* r,int N, int l, int h)
	{
		T x = *(r+h);
		T i = (l - 1);

		for (T j = l; j <= h - 1; j++) {
			if (*(r+j) <= x) {
				i++;
				swap(*(r+i), *(r+j));
			}
		}
		swap(*(r+i + 1), *(r+h));
		return (i + 1);
	}

	template<typename T> void quickSortinner(T* r, T l, T h,int N)
	{
		T stack[h - l + 1];
		int top = -1;

		stack[++top] = l;
		stack[++top] = h;

		while (top >= 0) {
			h = stack[top--];
			l = stack[top--];

			T p = partition(r,N, l, h);
	
			if (p - 1 > l) {
				stack[++top] = l;
				stack[++top] = p - 1;
			}

			if (p + 1 < h) {
				stack[++top] = p + 1;
				stack[++top] = h;
			}
		}
	}

    template<typename T,int N> void quickSort(T (&r)[N],bool ascending)
    {
        quickSortinner(r,0,N-1,N);
		if(!ascending)
		{
			for(int i=0;i<N/2;i++)
			{
				swap(*(r+i),*(r+N-1-i));
			}
		}
    }
}

#endif
