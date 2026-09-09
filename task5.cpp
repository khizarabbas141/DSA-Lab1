#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Pascal Triangle function

vector <vector<int>> pascalTri(int n) {

    vector<vector<int>> tri;
    if (n <= 0) return tri;


    for (int  i = 0; i < n; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = tri[i - 1][j - 1] + tri[i - 1][j];}
        tri.push_back(row);}
    return tri;
}

// Test case
int main() {

    cout << "Pascal's Triangle"<<endl;
    cout << "n = 0 size: " << pascalTri(0).size() <<endl;


    cout << "n = 1 size: " << pascalTri(1).size() <<  endl;
    cout << "n = 5 size: " << pascalTri(5).size() << endl;

    auto p5 = pascalTri(5);
    cout << "Row 5 elements: ";
    for (int x : p5[4]) {
        cout << x << " ";}

    cout << "Expected: 1 4 6 4 1"<<endl;
    return 0;
}