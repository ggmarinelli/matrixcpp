#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;
using Double2DArr = vector<vector<double>>;
using Float2DArr = vector<vector<float>>;
using Int2DArr = vector<vector<int>>;

namespace scrip {

	namespace utils {

		template <typename T>
		class Matrix2D {
		private:
			vector<vector<T>> m_vec;
			unsigned int m_nRows;
			unsigned int m_nCols;
		public:
			// Constructors
			Matrix2D();
			Matrix2D(int nRows, int nCols);
			Matrix2D(vector<vector<T>>& vec);
			Matrix2D(vector<T>& vec);

			// Read private variables
			int getNRows();
			int getNCols();
			vector<vector<T>> toVector();
			T** toArray();

			// Operations methods
			Matrix2D<T> operator+(Matrix2D<T>& m);
			Matrix2D<T> operator-(Matrix2D<T>& m);
			Matrix2D<T> add(Matrix2D<T>& m);


			Matrix2D<T> operator*(Matrix2D<T>& m);
			Matrix2D<T> multiply(Matrix2D<T>& m);

			Matrix2D<T> operator*(double scalar);
			Matrix2D<T> operator/(double scalar);
			Matrix2D<T> operator-();
			Matrix2D<T> multiply(double scalar);

			bool operator==(Matrix2D<T>& m);
			bool equals(Matrix2D<T>& m);

			Matrix2D<T> operator!();
			Matrix2D<T> transpose();

			vector<T> operator[](int idx);
		};

	}

}

#endif