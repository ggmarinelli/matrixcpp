#ifndef VOLRISKFUNCTION_H
#define VOLRISKFUNCTION_H

#include <scripcpp/risk_functions/base_function.hpp>
#include <iostream>

namespace scrip {
	
	namespace riskfuncs {

		class VolRiskFunction : BaseFunction {

		public:
			VolRiskFunction(vector<vector<float> >& covMatrix, vector<float>& budget) : BaseFunction(covMatrix, budget) {};
			virtual vector<float> evaluate(vector<float> weights);
			virtual vector<float> jacobian(vector<float> weights);
		};

	}

}

#endif