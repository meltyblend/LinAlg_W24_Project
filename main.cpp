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
float Dot_Product(vector<float> v1, vector<float> v2);
vector<float> Scalar_Vec(vector<float> v1, float scalar);


int main() {

    vector<float> v1 = {1,2,3,4,5,6,7,8,9};
    vector<float> v2 = {1,2,3,4,5,6,7,8,9};
    float scalar = 10;
    float dot_prod_sum = 0;

    cout << "adding vector 1 and vector 2 :" << endl;
    vector<float> v3 = Vec_Add(v1, v2);             // adding two vectors of same sizes

    cout << endl;

    cout << "subtracting vector 1 and vector 2 :" << endl;
    vector<float> v4 = Vec_Sub(v1, v2);            // subtracting two vectors

    cout << endl;

    cout << "the dot product of vectors 1 and vectors 2:" << endl;
    dot_prod_sum = Dot_Product(v1, v2);               // performing the dot product

    cout << endl;

    cout << "scalar product of vectors 1 and a single scalar:" << endl;
    vector<float> v5 =  Scalar_Vec(v1, scalar);             // performing scalar multiplication on vector 1

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

// function for the subtraction of two vectors
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

//function that performs the dot product of two vectors
float Dot_Product(vector<float> v1, vector<float> v2) {
    if (v1.size() != v2.size()) {
        cerr << "Dot_Product Error" << endl;                    // checking to make sure that the sizes of both vectors
    }                                                           // match

    float total = 0;                                             // initializing sum to 0
    float multi = 0;                                             // initializing the multiplication to 0

    for (auto i = 0; i < v1.size(); i++) {                      // for loop that calculates the dot product of the
        multi = v1[i] * v2[i];                                  // two vectors
        total = total + multi;
    }

    cout << total << endl;

    return total;
}

// function to perform scalar multiplication on a vector
vector<float> Scalar_Vec(vector<float> v1, float scalar) {
    vector<float> total;

    for (auto i = 0; i < v1.size(); i++) {
        total.push_back(v1[i] * scalar);                // to perform scalar multiplication on a vector
    }

    for(auto val: total) {                          // printing the scaled vector
        cout << val << " ";
    }
}






