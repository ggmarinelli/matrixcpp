#include <iostream>
#include <vector>
#include <scripcpp/utils/matrix.hpp>

using namespace std;
namespace scrip {

	namespace utils {
		// Add classes definitions based on template Matrix2D
		template class Matrix2D<double>;
		template class Matrix2D<float>;
		template class Matrix2D<int>;

		/*
		 * Getters
		 */
		template <typename T>
		int Matrix2D<T>::getNRows() {
			return m_nRows;
		}

		template <typename T>
		int Matrix2D<T>::getNCols() {
			return m_nCols;
		}

		template <typename T>
		vector<vector<T>> Matrix2D<T>::toVector() {
			return m_vec;
		}

		template <typename T>
		T** Matrix2D<T>::toArray() {
			// Each element is a pointer to an array of T
			T** arr = new T * [m_nRows];

			for (unsigned int i = 0; i < m_nRows; i++) {
				// Initialize cols
				arr[i] = new T[m_nCols];

				// Set array elements
				for (unsigned int j = 0; j < m_nCols; j++) {
					arr[i][j] = m_vec[i][j];
				}
			}

			return arr;
		}

		/*
		 * Constructors
		 */
		template <typename T>
		Matrix2D<T>::Matrix2D() {
			vector<vector<T>> vec(0, vector<T>(0));
			m_vec = vec;
			m_nRows = 0;
			m_nCols = 0;
		}

		template <typename T>
		Matrix2D<T>::Matrix2D(int nRows, int nCols) {
			vector<vector<T>> vec(nRows, vector<T>(nCols));
			m_vec = vec;
			m_nRows = nRows;
			m_nCols = nCols;
		}

		template <typename T>
		Matrix2D<T>::Matrix2D(vector<vector<T>>& vec) {
			m_vec = vec;
			m_nRows = vec.size();
			m_nCols = vec[0].size();
		}

		template <typename T>
		Matrix2D<T>::Matrix2D(vector<T>& vec) {
			m_vec = { vec };
			m_nRows = 1;
			m_nCols = vec.size();
		}

		/*
		 * Operators
		 */
		template <typename T>
		bool Matrix2D<T>::equals(Matrix2D<T>& m) {
			return m.toVector() == m_vec;
		}

		template <typename T>
		bool Matrix2D<T>::operator==(Matrix2D<T>& m) {
			return this->equals(m);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::add(Matrix2D<T>& m) {
			// Validate the number of dimensions for addition
			if ((m_nRows != m.getNRows()) || (m_nCols != m.getNCols())) {
				throw invalid_argument("The dimension of the matrices for addition must match!");
			}

			// Perform vector addition
			vector<vector<T>> resVec(m_nRows, vector<T>(m_nCols));
			vector<vector<T>> mVec = m.toVector();

			for (unsigned int i = 0; i < m_nRows; i++) {
				for (unsigned int j = 0; j < m_nCols; j++) {
					resVec[i][j] = mVec[i][j] + m_vec[i][j];
				}
			}

			return Matrix2D<T>(resVec);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator+(Matrix2D<T>& m) {
			return this->add(m);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator-(Matrix2D<T>& m) {
			return this->add(-m);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::multiply(double scalar) {
			vector<vector<T>> resVec(m_nRows, vector<T>(m_nCols));

			for (unsigned int i = 0; i < m_nRows; i++) {
				for (unsigned int j = 0; j < m_nCols; j++) {
					resVec[i][j] = scalar * m_vec[i][j];
				}
			}

			return Matrix2D<T>(resVec);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator*(double scalar) {
			return this->multiply(scalar);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator/(double scalar) {
			return this->multiply(1 / scalar);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator-() {
			return this->multiply(-1.0);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::multiply(Matrix2D<T>& m) {
			// Validate if the matrix dimensions match
			if (m_nCols != m.getNRows()) {
				throw invalid_argument("The number of rows of the given matrix must match this number of columns!");
			}

			vector<vector<T>> res(m_nRows, vector<T>(m.getNCols()));
			vector<vector<T>> mVec = m.toVector();

			for (unsigned int i = 0; i < m_nRows; i++) {
				for (unsigned int j = 0; j < m.getNCols(); j++) {
					for (unsigned int k = 0; k < m_nCols; k++) {
						res[i][j] += m_vec[i][k] * mVec[k][j];
					}
				}
			}

			return Matrix2D<T>(res);

		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator*(Matrix2D<T>& m) {
			return this->multiply(m);
		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::transpose() {
			// Transpose the current matrix
			vector<vector<T>> res(m_nRows, vector<T>(m_nCols));

			for (unsigned int i = 0; i < m_nRows; i++) {
				for (unsigned int j = 0; j < m_nCols; j++) {
					res[j][i] = m_vec[i][j];
				}
			}

			return Matrix2D<T>(res);

		}

		template <typename T>
		Matrix2D<T> Matrix2D<T>::operator!() {
			return this->transpose();
		}

		template <typename T>
		vector<T> Matrix2D<T>::operator[](int idx) {
			return m_vec[idx];
		}


	}

}