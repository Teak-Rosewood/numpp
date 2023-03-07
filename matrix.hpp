#include <iostream>
#include <vector>
namespace numpp 
{
	template <typename T> class Matrix
	{
		private: 
		
		std::vector<std::vector<T> > matrix;
		row_length, col_length;
		
		public: 
		
		//Matrix(Array<T> a[]);
		Matrix(std::vector<std::vector<T> > &a);
		//Matrix(vector<T> a[]);
	};
	template <typename T> Matrix<T>::Matrix(std::vector<std::vector<T> > &a)
	{
		matrix = a;
		row_len = a.size();
		col_len = a[0].size();
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		} 
	}
}



/*
template <typename T> float Matrix<T>::mean()
{
		int row_length = size;
		int col_length = matrix[0].size();
		int temp_sum = 0;
		for(int i = 0; i < row_length; i++)
		{
			for(int j = 0 j < col_length; j++)
			{
				sum = matrix[0].
			}
		}
		
		return sum / (row_length * col_length);
}
*/
/*
numpp::Matrix<int> A
A.mean() -- returns mean
mean(A) -- returns mean 
*/ 
