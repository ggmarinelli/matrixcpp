#include <iostream>
#include <vector>
#include <scripcpp/utils/matrix.hpp>

using namespace std;
namespace scrip {

	namespace utils {

		Matrix MatrixUtils::empty2DMatrix(int nRows, int nCols) {
			Matrix v(nRows, vector<float>(nCols));
			return v;
		}

		Matrix MatrixUtils::multiplyMatrices(Matrix& m1, Matrix& m2) {
			// Validate the matrix dims to perform multiplication
			int m1Rows = m1.size();
			int m1Cols = m1[0].size();
			int m2Rows = m2.size();
			int m2Cols = m2[0].size();

			if (m1Cols != m2Rows) {
				throw invalid_argument("m1 number of cols must match m2 number of rows!");
			}

			// Create response matrix and perform multiplication
			Matrix res(m1Rows, vector<float>(m2Cols));

			for (int i = 0; i < m1Rows; i++) {
				for (int j = 0; j < m2Cols; j++) {
					for (int k = 0; k < m1Cols; k++) {
						res[i][j] += m1[i][k] * m2[k][j];
					}
				}
			}

			return res;

		}

		Matrix MatrixUtils::multiplyMatrices(vector<float>& m1, Matrix& m2) {
			Matrix m1Mat(1, vector<float>(m1.size()));
			m1Mat[0] = m1;
			return MatrixUtils::multiplyMatrices(m1Mat, m2);
		}

		Matrix MatrixUtils::multiplyMatrices(Matrix& m1, vector<float>& m2) {
			Matrix m2Mat(1, vector<float>(m2.size()));
			m2Mat[0] = m2;
			return MatrixUtils::multiplyMatrices(m1, m2Mat);
			return MatrixUtils::multiplyMatrices(m1, m2Mat);
		}

		

	}

}