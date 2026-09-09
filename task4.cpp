#include <string>
#include <iostream>

#include <string>

using namespace std;

int naivePatternMatch(const string &text,const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return 0;

    if (m > n) return -1;

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;}
        if (j == m) return i;}
    return -1;
}


void runPatternTest(const string &text,const string &pattern,const string &testName) {
    cout << testName << " have Index: " << naivePatternMatch(text, pattern) << endl;

}

int main(){

    runPatternTest("my name is khizar", "my ", "Pattern at the beginning");

    runPatternTest("all might", "might","Pattern at the end");

    runPatternTest("i am ", "test", "Pattern not present");
    runPatternTest("what khizar", "", "Empty pattern");

    return 0;
}