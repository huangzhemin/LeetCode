#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //S 和 T 是相同的长度
        map<char, char> charMap1;
        map<char, char> charMap2;
        for (int i = 0; i < s.size(); i ++) {
            if (charMap1.find(s[i]) != charMap1.end()) {
                if (charMap1[s[i]] != t[i]) {
                    return false;
                }
            } else {
                charMap1[s[i]] = t[i];
            }
            if (charMap2.find(t[i]) != charMap2.end()) {
                if (charMap2[t[i]] != s[i]) {
                    return false;
                }
            } else {
                charMap2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string a = "ab";
    string b = "aa";
    cout << s.isIsomorphic(a, b) << endl;

    return 0;
}
