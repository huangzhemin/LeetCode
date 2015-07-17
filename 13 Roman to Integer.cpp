#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <map>
#include <set>
using namespace std;

 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;

 typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

class Solution {
public:
    //思路：
    //罗马数字变阿拉伯数字
    int getTranslateNum(char s) {
        switch(s) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        if (s.empty()) return 0;
        int result = 0;
        for(int i = 0; i < s.size() - 1; i ++) {
            if(getTranslateNum(s[i]) < getTranslateNum(s[i + 1])) {
                result -= getTranslateNum(s[i]);
            } else {
                result += getTranslateNum(s[i]);
            }
        }
        result += getTranslateNum(s[s.size() - 1]);
        return result;
    }
};

int main() {
    Solution s;
    vector<string> str;

    cout << s.romanToInt("MCMXCVI") << endl;
    return 0;
}
