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

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
public:
    //思路：
    //找最长的回文子串，这种题目必须要扫描了，而且复杂度将会达到0(n2)
    //先看看字符串s的长度，从中点位置开始作为中心点，向两边边界走。
    //在写一个函数，判断是否为回文字符串
    //先用一个简单的一次扫描
    string longestPalindrome(string s) {
        string result;
        int maxLength = 0;
        //奇数
        for (int i = 0; i < s.length(); i ++) {
            //以i的位置作为中心位置，向两边扫描，判断是否为回文
//            cout << "i:" << i << endl;
            int startPos = i - 1, endPos = i + 1;

            while (startPos >= 0 && endPos < s.length()) {
                if (s[startPos] == s[endPos]) {
                    startPos --;
                    endPos ++;
                } else {
                    startPos ++;
                    endPos --;
                    break;
                }
            }
            if (startPos < 0 || endPos >= s.length()) {
                startPos ++;
                endPos --;
            }
//            cout << "starpos:" << startPos << endl;
//            cout << "endPos:" << endPos << endl;
            if (startPos >= 0 && endPos <= s.length() && endPos - startPos + 1 > maxLength) {
//                cout << startPos << endl;
//                cout << endPos << endl;
                maxLength = endPos - startPos + 1;
                result = s.substr(startPos, endPos - startPos + 1);
//                cout << "result:" << result << endl;
            }
        }
        //偶数
        for (float i = 0.5; i < s.length(); i ++) {
            //以i的位置作为中心位置，向两边扫描，判断是否为回文
//            cout << "i:" << i << endl;
            int startPos = i - 0.5, endPos = i + 0.5;

            while (startPos >= 0 && endPos < s.length()) {
                if (s[startPos] == s[endPos]) {
                    startPos --;
                    endPos ++;
                } else {
                    startPos ++;
                    endPos --;
                    break;
                }
            }
            if (startPos < 0 || endPos >= s.length()) {
                startPos ++;
                endPos --;
            }
//            cout << "starpos:" << startPos << endl;
//            cout << "endPos:" << endPos << endl;
            if (startPos >= 0 && endPos <= s.length() && endPos - startPos + 1 > maxLength) {
                maxLength = endPos - startPos + 1;
//                cout << "1:" << startPos << endl;
//                cout << "2:" << endPos << endl;
                result = s.substr(startPos, endPos - startPos + 1);
//                cout << "result:" << result << endl;
//                cout << "resultLength:" << result.length() << endl;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("asadgfsdafabcddcbadsafsdaf") << endl;
    return 0;
}
