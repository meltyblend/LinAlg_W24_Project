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

    vector<int> v = {1,2,3,4,5,6,7,8,9};

    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }

    return 0;
}