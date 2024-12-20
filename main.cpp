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

vector<float> Vec_Add(vector<float> v1, vector<float> v2);
vector<float> Vec_Sub(vector<float> v1, vector<float> v2);


int main() {

    vector<float> v1 = {1,2,3,4,5,6,7,8,9};
    vector<float> v2 = {1,2,3,4,5,6,7,8,9};

    cout << "adding vector 1 and vector 2 :" << endl;
    vector<float> v3 = Vec_Add(v1, v2); // adding two vectors of same sizes

    cout << endl;

    cout << "subtracting vector 1 and vector 2 :" << endl;
    vector<float> v4 = Vec_Sub(v1, v2);

    cout << endl;

    return 0;
}

// function to add two vectors
vector<float> Vec_Add(vector<float> v1, vector<float> v2) {
    if (v1.size() != v2.size()) {
        cerr << "Vector_Add Error" << endl;                  // checking to make sure vectors are same size
    }
    vector<float> total;
    for (auto i = 0; i < v1.size(); i++) {                  // summing vectors
        total.push_back(v1[i] + v2[i]);
    }

    for(auto val: total) {                                 // printing vector sum
        cout << val << " ";
    }

    cout <<  endl;

    return total;
}

vector<float> Vec_Sub(vector<float> v1, vector<float> v2) {
    if (v1.size() != v2.size()) {
        cerr << "Vector_Add Error" << endl;                  // checking to make sure vectors are same size
    }
    vector<float> total;
    for (auto i = 0; i < v1.size(); i++) {
        total.push_back(v1[i] - v2[i]);                      // subtracting vectors
    }

    for(auto val: total) {                                // printing vector sum
        cout << val << " ";
    }

    cout <<  endl;

    return total;
}

/*  working on dot products of the code
 *
vector<float> Dot_Product(vector<float> v1, vector<float> v2) {
    if (v1.size() != v2.size()) {
        cerr << "Dot_Product Error" << endl;
    }

    int total = 0;
    int multi = 0;
    int add = 0;

    for (auto i = 0; i < v1.size(); i++) {
        for (auto j = 0; j < v2.size(); j++) {
            multi = v1[i] * v2[j];
            add = multi + multi;
        }
    }



}
*/



