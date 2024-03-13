#include <assert.h>
#include <iostream>
#include <vector>
#include <scripcpp/utils/matrix.hpp>

using namespace std;
using namespace scrip::utils;

bool testEmpty2DMatrix_create() {
	Matrix m = MatrixUtils::empty2DMatrix(2, 2);
	return (m.size() == 2) && (m[0].size() == 2);
}

bool testMatrixMultiplication_wrongSize() {
	Matrix m1 = MatrixUtils::empty2DMatrix(3,2);
	Matrix m2 = MatrixUtils::empty2DMatrix(4,2);
	
	try {
		MatrixUtils::multiplyMatrices(m1, m2);
		return false;
	}
	catch (invalid_argument exception) {
		return true;
	}

}

int main() {
	assert(testEmpty2DMatrix_create());
	assert(testMatrixMultiplication_wrongSize());

	cout << "All tests passed!\n";
	return 0;
}