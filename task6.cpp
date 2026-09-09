#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// return mode of an array
vector<int> getMode(vector<int> arr) {

    if (arr.empty()) return {};

// empty array checp, returns empty

    map<int, int> counts;
    for (int x : arr) {
        counts[x]++; }

    int maxFreq = 0;
    for (auto const& [val, freq] : counts) {
        if (freq > maxFreq) {
            maxFreq = freq;}}

    vector<int> modes;
    for (auto const& [val, freq]  : counts) {
        if (freq == maxFreq) {
            modes.push_back(val);}}
    return modes;
}

// Test case

int main() {
    cout << "Histogram Mode "<<endl;

    auto m1 = getMode({ 4, 1, 2, 2, 3 });
    cout << "Unique mode test: "; for (int x : m1) cout << x << " ";
    cout << endl;

    auto m2 = getMode({ 1, 1, 2, 2, 3 });


    cout << "Multiple modes test: "; for (int x : m2) cout << x << " ";
    cout << endl;

    auto m3 = getMode({});

    cout << "Empty array size: " << m3.size() << endl;

    return 0;
}