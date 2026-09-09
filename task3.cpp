#include <iostream>
#include <vector>

using namespace std;

vector<int> findingindex( vector<int>& arr1,  int key) {
    vector<int> ind;
    for (size_t a = 0; a < arr1.size(); ++a) {
        if (arr1[a] == key) {
            ind.push_back(a);
        }
    }
    return ind;
}

void printVector(vector<int>& vt) {

    if (vt.empty()) {
        cout << "not found" << endl;
        return;
    }

    for (int i : vt) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr2 = { 1,2, 3,4, 5,6 };
    cout << "Key not present test: ";
    printVector(findingindex(arr2, 99));

    vector<int> arr1 = { 10, 20, 30, 30, 40, 30 };
    cout << "Multiple occurrences test: ";
    printVector(findingindex(arr1, 30));


    vector<int> arr3 = {};
    cout << "Empty array test: ";
    printVector(findingindex(arr3, 5));

    return 0;
}