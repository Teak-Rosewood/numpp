#include <iostream>
#include <vector>
namespace numpp 
{
	template <typename T> class Matrix
	{
		private: 
		
		std::vector<std::vector<T> > matrix;
		row_length, col_length;
		swap(T &a, T &b);
		
		public: 
		
		//TODO:
		//Matrix(Array<T> a[]);
		
		Matrix(std::vector<std::vector<T> > &a);
		
		//TODO:
		//Matrix(vector<T> a[]);
		
		transpose();
		
		display();
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
	
	template <typename T> Matrix<T>::transpose()
	{
		std::vector<std::vector<T> > temp_mat;
		for(int i = 0; i < matrix[0].size(); i++)
		{
			std::vector<T> temp_vec = {};
			for(int j = 0; j < matrix.size(); j++)
			{
				temp_vec.push_back(matrix[j][i]);
			}
			temp_mat.push_back(temp_vec);
		}
		
		matrix = temp_mat;
	}
	
	template <template T> Matrix<T>::swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
}

