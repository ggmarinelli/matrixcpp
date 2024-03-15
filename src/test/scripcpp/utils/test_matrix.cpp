#include <assert.h>
#include <iostream>
#include <vector>
#include <scripcpp/utils/matrix.hpp>

using namespace std;
using namespace scrip::utils;

bool testEmpty2DMatrix_create() {
	Matrix2D<double> m(2, 2);
	return m.getNRows() == 2 && m.getNCols() == 2;
}

bool testMatrixMultiplication_wrongSize() {
	Matrix2D<double> m1(3, 2);
	Matrix2D<double> m2(4, 2);

	try {
		m1.multiply(m2);
		return false;
	}
	catch (invalid_argument exception) {
		return true;
	}

}

bool testMatrixMultiplication_squareMatrix() {

	Matrix2D<double> m1(Double2DArr({ {1,2}, {3,4} }));
	Matrix2D<double> m2(Double2DArr({ {1,1}, {1,1} }));

	try {
		Matrix2D<double> res = m1 * m2;
		Matrix2D<double> tgtRes(Double2DArr({ {3, 3}, {7, 7} }));
		return res == tgtRes;
	}
	catch (exception) {
		return false;
	}
}

bool testMatrixMultiplication_scalar() {
	Matrix2D<double> m1(Double2DArr({ {1,1}, {1,1} }));
	Matrix2D<double> res = m1 * 2;
	Matrix2D<double> tgtRes(Double2DArr({ {2,2}, {2,2} }));

	return res == tgtRes;
}

bool testMatrixTransposition() {
	Matrix2D<double> m(Double2DArr({ {1,2}, {3,4} }));
	Matrix2D<double> res = m.transpose();
	Matrix2D<double> tgtRes(Double2DArr({ {1, 3}, {2, 4} }));

	return res == tgtRes;
}

int main() {
	assert(testEmpty2DMatrix_create());
	assert(testMatrixMultiplication_wrongSize());
	assert(testMatrixMultiplication_squareMatrix());
	assert(testMatrixMultiplication_scalar());
	assert(testMatrixTransposition());

	cout << "All tests passed!\n";
	return 0;
}