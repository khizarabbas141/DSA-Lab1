#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<int>> addMat(vector<vector<int>> A,vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            C[i][j] = A[i][j] + B[i][j];}}

     return C;
}


vector<vector<int>>  subMat(vector<vector<int>> A,  vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            C[i][j] = A[i][j] - B[i][j];}}
    return C;
}
vector<vector<int>> strassen(vector<vector<int>> A,  vector<vector<int>> B) {
    int n = A.size();
    if (n == 1) {
        return { {A[0][0] * B[0][0]} };
    }

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));

    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];


            A21[i][j]= A[i + k][j];
            A22[i][j] =A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] =  B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    auto M1 = strassen(addMat(A11, A22), addMat(B11, B22));
    auto M2= strassen(addMat(A21, A22), B11);

    auto M3 = strassen(A11, subMat(B12, B22));
    auto M4 = strassen(A22, subMat(B21, B11));

    auto M5 =strassen(addMat(A11, A12), B22);
    auto M6 = strassen(subMat(A21, A11),  addMat(B11, B12));

    auto M7 = strassen(subMat(A12,  A22),addMat(B21, B22));

    auto C11 =addMat(subMat(addMat(M1, M4), M5), M7);
    auto C12 = addMat(M3, M5);
    auto C21 = addMat(M2, M4);

    auto C22 = addMat(subMat(addMat(M1, M3), M2), M6);

    vector<vector<int>> res(n, vector<int>(n));


    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] =   C11[i][j];
            res[i][j + k]= C12[i][j];

            res[i + k][j] =C21[i][j];
            res[i + k][j + k]= C22[i][j];  } }
    return res;
        }
// standard matrix mult
vector<vector<int>> standardMult(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j];
            } } }
    return res;
}
// Test case

int main(){

    cout << "Strassen's vs Naive "<<endl;

    //2x2 test

    vector<vector<int>> A2 = { {1, 2}, {3, 4} };
    vector<vector<int>> B2 = { {5, 6}, {7, 8} };

    auto r2 = strassen(A2, B2);

    cout << "Strassen 2x2 [0][0] = " << r2[0][0] << endl;

    vector<vector<int>> A4 = { {1, 2, 3, 4}, {5, 6, 7, 8},{9, 1, 2, 3}, {4, 3, 2, 1}
    };


    vector<vector<int>> B4 = {
        {8, 7, 6, 5}, {4, 3, 2, 1}, {1, 2, 3, 4},  {5, 6, 7, 8} };
    auto s4 = strassen(A4, B4);

    auto n4 = standardMult(A4, B4);

    bool matches = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s4[i][j] !=  n4[i][j]) matches = false;}}

    cout << "4x4 matrices match standard mult?" <<    (matches ? "YES haha" : "NO nah") << endl;

    return 0;
}