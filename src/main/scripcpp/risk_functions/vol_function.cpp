#include <scripcpp/risk_functions/vol_function.hpp>
#include <scripcpp/utils/matrix.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace scrip::utils;
using Matrix = vector<vector<float> >;

namespace scrip {

	namespace riskfuncs {

		vector<float> VolRiskFunction::evaluate(vector<float> weights) {
			vector<float> g(nAssets);
			
			Matrix portfolioVariance = MatrixUtils::multiplyMatrices(MatrixUtils::multiplyMatrices(weights, covMatrix), weights);
			float portfolioVol = sqrt(portfolioVariance[0][0]);

			for (int i = 0; i < nAssets; i++) {
				vector<vector<float> > Mi(nAssets, vector<float>(nAssets));
				Mi[i] = covMatrix[i];
			}
		}

	}

}

