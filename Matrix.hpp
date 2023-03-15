#include <iostream>
#include <vector>
namespace numpp 
{
	template <typename T> class Matrix
	{
		private: 
		
		std::vector<std::vector<T> > matrix;
		int row_length, col_length;
		void swap(T &a, T &b);
		
		public: 
		
		//TODO:
		//Matrix(Array<T> a[]);
		
		Matrix(std::vector<std::vector<T> > &a);
		
		Matrix(int rows, int columns, T num);
		
		//TODO:
		//Matrix(vector<T> a[]);
		
		void transpose();
		
		void display();
	};
	
	template <typename T> Matrix<T>::Matrix(std::vector<std::vector<T> > &a)
	{
		matrix = a;
		row_length = a.size();
		col_length = a[0].size();
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		} 
	}
	
	template <typename T> Matrix<T>::Matrix(int rows, int columns, T num)
	{
		row_length = rows;
		col_length = columns;
		for (int i = 0; i < rows; i++)
		{
			std::vector<T> temp_vec;
			for (int j = 0; j < columns; j++)
			{
				temp_vec.push_back(num);
			}
			matrix.push_back(temp_vec);
		} 
	}
	
	template <typename T>void Matrix<T>::transpose()
	{
		std::vector<std::vector<T> > temp_mat;
		for(int i = 0; i < col_length; i++)
		{
			std::vector<T> temp_vec;
			for(int j = 0; j < row_length; j++)
			{
				temp_vec.push_back(matrix[j][i]);
			}
			temp_mat.push_back(temp_vec);
		}
		
		matrix = temp_mat;
		row_length = matrix.size();
		col_length = matrix[0].size();
	}
	
	template <typename T> void Matrix<T>::swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
	
	template <typename T> void Matrix<T>::display()
	{
		std::cout << "[";
		for (int i = 0; i < matrix.size(); i++)
		{
			std::cout << "[";
			for (int j = 0; j < matrix[i].size(); j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "]";
			if(i == matrix.size() - 1)
				std::cout << "]";
			else
				std::cout << std::endl;
		}
	}
}
