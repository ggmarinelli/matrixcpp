#ifndef BASEFUNCTION_H
#define BASEFUNCTION_H

#include <iostream>
#include <vector> 

using namespace std;

namespace scrip {

    namespace riskfuncs {

        class BaseFunction{
            protected:
                vector<vector<float> > covMatrix;
                vector<float> budget;
                int nAssets;

                bool validateParams();

            public:
                BaseFunction(vector<vector<float> > &covMatrix, vector<float> &budget);
                virtual vector<float> evaluate(vector<float> weights);
                virtual vector<float> jacobian(vector<float> weights);
            
        
        };

    }

}

#endif