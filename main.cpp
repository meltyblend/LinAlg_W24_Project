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

vector<float> Vec_Add(vector<float> v1, vector<float> v2);      // Vector Addition
vector<float> Vec_Sub(vector<float> v1, vector<float> v2);      // Vector Subtraction
float Dot_Product(vector<float> v1, vector<float> v2);          // Dot Product
vector<float> Scalar_Vec(vector<float> v1, float scalar);       // Scaling a vector
vector<vector<float>> Mat_Add(vector<vector<float>> A, vector<vector<float>> B);          // Matrix Addition
vector<vector<float>> Mat_Sub(vector<vector<float>> A, vector<vector<float>> B);            // Matrix subtraction
vector<vector<float>> Mat_Multi(vector<vector<float>> A, vector<vector<float>> B);          // Matrix Multiplication
bool REF(vector<vector<float>> A);                                          // checks if matrix is of Row Echelon Form

int main() {


    vector<vector<float>> A = { {1,4,5},            // matrix A
                                {2,5,7},
                                {3,6,9}};

    vector<vector<float>> B = { {1,2,3},            // matrix B
                                {2,3,1},
                                {3,1,2}};

    vector<vector<float>> A_1 = { {1,4,5},            // matrix A
                                {0,0,0},
                                {3,6,9}};

    vector<vector<float>> I = { {1,0,0},            // Identity Matrix
                                {0,1,0},
                                {0,0,1}};

    vector<vector<float>> zero_matrix = {{0,0,0},           // zero Matrix
                                        {0,0,0},
                                        {0,0,0}};



    vector<float> v1 = {1,2,3,4,5,6,7,8,9};                // defining vector v1
    vector<float> v2 = {1,2,3,4,5,6,7,8,9};                // defining vector v2
    vector<float> zero_vector = {0,0,0,0,0,0,0,0,0};                 // zero vector

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
    cout << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "adding Matrix A and Matrix B:" << endl;
    vector<vector<float>> C = Mat_Add(A, B);            // performing the addition of matrix A and B
    cout << endl;

    cout << "subtracting Matrix A and Matrix B:" << endl;
    vector<vector<float>> D = Mat_Sub(A, B);            // performing the subtraction of matrix A and B
    cout << endl;

    cout << "the product of Matrix A and Matrix B:" << endl;
    vector<vector<float>> E = Mat_Multi(A, B);
    cout << endl;

    cout << "Is your matrix in row echelon form?:" << endl;
    // naming convention is poor here, but we are doing this to test different matrices to make sure our function
    // works properly
    bool is_row_echelon = REF(I);
    bool is_not_row_echelon = REF(A);
    bool is_not_row_echelon_1 = REF(A_1);
    cout << endl;



    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// function to add two vectors
vector<float> Vec_Add(vector<float> v1, vector<float> v2) {
    if (v1.size() != v2.size() || v2.size() != v1.size()) {
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
    if (v1.size() != v2.size() || v2.size() != v1.size()) {
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
    if (v1.size() != v2.size() || v2.size() != v1.size()) {
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
    cout << endl;

    return total;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// function to perform Matrix addition
vector<vector<float>> Mat_Add(vector<vector<float>> A, vector<vector<float>> B) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {           // checking for same dimension matrices
        cerr << "Matrix addition not possible" << endl;
        return {};
    }

    vector<vector<float>> C(A.size(), vector<float>(A[0].size()));          // initializing C
                                                                                    // to be of the same size

    for (auto i = 0; i < A.size(); i++) {                                    // adding each component iteratively
        for (auto j = 0; j < A[i].size(); j++) {                            // iterating through cols/rows of A
            C[i][j] = A[i][j] + B[i][j];                          // this part is doing the addition
        }
    }

    for (auto i = 0; i < C.size(); i++) {                      // for printing out the C matrix
        for (auto j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return C;
}

// function to perform Matrix subtraction
vector<vector<float>> Mat_Sub(vector<vector<float>> A, vector<vector<float>> B) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {           // checking for same dimension matrices
        cerr << "Matrix addition not possible" << endl;
        return {};
    }

    vector<vector<float>> C(A.size(), vector<float>(A[0].size()));          // initializing C
                                                                                    // to be of the same size

    for (auto i = 0; i < A.size(); i++) {                                    // subtracting each component iteratively
        for (auto j = 0; j < A[i].size(); j++) {                            // iterating through cols/rows of A
            C[i][j] = A[i][j] - B[i][j];                          // this part is doing the subtraction
        }
    }

    for (auto i = 0; i < C.size(); i++) {                      // for printing out the C matrix
        for (auto j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return C;
}

// function to perform Matrix Multiplication the very basic text book O(n^3) way
vector<vector<float>> Mat_Multi(vector<vector<float>> A, vector<vector<float>> B) {
    if (A[0].size() != B.size()) {                                                 // ensuring that the columns of A
        cerr << "Matrix multiplication not possible" << endl;                      // Match the amount of rows in B
        return {};
    }

    vector<vector<float>> C(A.size(), vector<float>(B[0].size()));   // initializing C to be a matrix
                                                                        // with the rows of A and the columns of B

    for (auto i = 0; i < A.size(); i++) {                              // iterating through the rows of A
        for (auto j = 0; j < B[0].size(); j++) {                      // iterating through the col's of B
            for (auto k = 0; k < B[i].size(); k++) {                 // performing "dot products" between A row and B col
                C[i][j] += A[i][k] * B[k][j];                       // performing the actual calculations here
            }
        }
    }

                                                // for printing out the C matrix
    for (auto i = 0; i < C.size(); i++) {
        for (auto j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return C;
}

// function for determining if a matrix is in Row Echelon Form
bool REF(vector<vector<float>> A) {
    // for clarity purposes I initialized what it means to be a row and col in this scope
    int row = A.size();
    int col = A[0].size();
    int previousPivotIndex = -1;      // allows uis to keep track of our pivots in the previous nonzero rows
    bool isZeroRow = false;

    if (row == 0 || col == 0) {
        cout << "matrix is empty" << endl;              // by default a matrix of 0 dimension is an empty matrix
        return true;
    }

    for (int i = 0; i < row; i++) {               // going through each row to check if the row is entirely zero
        bool allZeroRow = true;                   // if the row is zero set allZeroRow to true
        for (int j = 0; j < col; j++) {           // iterating through the columns
            if (A[i][j] != 0) {                   // comparing the value at A[i][j] if it is != 0 then allZeroRow = false
                allZeroRow = false;
                break;
            }
        }

        if (allZeroRow) {                         // if allZeroRow is set to true then isZeroRow must also be true
            isZeroRow = true;

            // now we will check the following rows if we find a nonzero element in that row REF = false
            for (int k = i + 1; k < row; k++) {
                for (int m = 0; m < col; m++) {
                    if (A[k][m] != 0) {
                        cout << "matrix is not in row echelon form" << endl;
                        return false;
                    }
                }
            }
            // after checking if the value at A[k][m] is == 0  we can determine that the all rows are zero
            cout << "matrix is in row echelon form" << endl;
            return true;

        } else {

            // here we are finding the pivot or the leading non-zero coefficient
            int pivotIndex = -1;
            for (int j = 0; j < col; j++) {
                if (A[i][j] != 0) {
                    pivotIndex = j;
                    break;
                }
            }

            // our pivot index must be >=0
            if (pivotIndex <= previousPivotIndex) {
                cout << "matrix is not in row echelon form" << endl;
                return false;                               // new pivot must be to the right of the previous pivot
            }

            // here we check if all elements below the current pivot are == 0
            for (int below = i + 1; below < row; below++) {
                if (A[below][pivotIndex] != 0) {
                    cout << "matrix is not in row echelon form" << endl;
                    return false;
                }
            }

            previousPivotIndex = pivotIndex;

        }
    }

    cout << "matrix is in row echelon form" << endl;
    return true;                                    // the matrix is in REF
}




