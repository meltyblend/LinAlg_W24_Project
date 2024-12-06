// c++ libraries
#include <iostream>
#include <vector> // for working with vectors of course
#include <algorithm>
#include <stdexcept> // exception handeling
#include <cmath>
#include <algorithm>
#include <complex> // for complex numbers

// file input and output
#include<fstream>
#include<sstream>

#include<cassert> // for runtime checks

#include <memory>
#include <cstdlib>

using namespace std;
int main() {

    vector<int> v1 = {1,2,3,4,5,6,7,8,9};  //declaring vecotr 1
    vector<int> v2 = {9,8,7,6,5,4,3,2,1};  // declaring vector 2
    vector<int> v3;                        // creating a new space for the sum of v1 + v2
    v3.reserve(v1.size());

    for (size_t i = 0; i < v1.size(); i++) {   // vector addition process
        v3.push_back(v1[i] + v2[i]);
    }

    for (auto i : v3) {                    // printing out v3 after being summed
        cout << i << " ";
    }


    return 0;
}