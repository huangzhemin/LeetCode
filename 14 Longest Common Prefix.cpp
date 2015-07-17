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
    //找到一组字符串的最长公共子串
    //扫描所有的字符串，每次只取一个字，如果都一样，则进入下一次循环
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int length = 0;
        string result = "";

        while (1) {
            for (int i = 0; i < strs.size(); i ++) {
                if (length == 0 && strs[i].empty()) return "";
                else {
                    if (strs[i][length] != strs[0][length] || strs[i][length] == '\0') return result;
                }
            }
            result += strs[0][length];
            length ++;
        }
    }
};

int main() {
    Solution s;
    vector<string> str;

    cout << s.longestCommonPrefix(str) << endl;
    return 0;
}
