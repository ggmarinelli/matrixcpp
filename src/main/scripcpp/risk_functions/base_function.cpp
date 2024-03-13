#include <scripcpp/risk_functions/base_function.hpp>
#include <iostream>
#include <vector>

using namespace std;

namespace scrip {

	namespace riskfuncs {

		BaseFunction::BaseFunction(vector<vector<float> >& covMatrix, vector<float>& budget) {
			this->covMatrix = covMatrix;
			this->budget = budget;

			validateParams();

			this->nAssets = budget.size();

		}

		bool BaseFunction::validateParams() {
			int budgetSize = budget.size();
			int covMatrixRows = covMatrix.size();

			// Check if the number of elements in budget is equal
			// the number of cov matrix rows
			if (budgetSize != covMatrixRows) {
				throw invalid_argument("The number of rows in covMatrix must match the number of elements in budget!");
			}

			// Check if the number of columns in each cov matrix array
			// is equal the number of budget elements
			for (int i = 0; i < covMatrixRows; i++) {
				vector<float> row = covMatrix[i];

				if (row.size() != budgetSize) {
					throw invalid_argument("The number of columns in covMatrix must match the number of elements in budget!");
				}
			}

		}


	}

}