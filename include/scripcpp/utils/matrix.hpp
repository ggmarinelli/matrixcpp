#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<float> >;

namespace scrip {

	namespace utils {

		class MatrixUtils {

		public:
			static Matrix multiplyMatrices(Matrix& m1, Matrix& m2);
			static Matrix multiplyMatrices(vector<float>& m1, Matrix& m2);
			static Matrix multiplyMatrices(Matrix& m1, vector<float>& m2);
			static Matrix empty2DMatrix(int nRows, int nCols);
		};

	}

}