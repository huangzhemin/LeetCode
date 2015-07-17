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
    //这道题要运用到栈的思想
    //遇到左边的就压栈，遇到右边符号就退栈
    //如果栈顶元素不是退栈元素的左符号，就直接返回false
    //如果扫描完毕，最后栈的大小为0，则返回true
    bool isValid(string s) {
        stack<char> punctutionStack;
        if (s.length() == 1) return false;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                punctutionStack.push(s[i]);
            } else if (s[i] == ')') {
                if (! punctutionStack.empty() && punctutionStack.top() == '(') {
                    punctutionStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (! punctutionStack.empty() && punctutionStack.top() == '[') {
                    punctutionStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (! punctutionStack.empty() && punctutionStack.top() == '{') {
                    punctutionStack.pop();
                } else {
                    return false;
                }
            }
        }
        if (punctutionStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
//    TreeNode *tn = new TreeNode(1);
//    TreeNode *tl = new TreeNode(2);
//    tn->left = tl;
//    TreeNode *tr = new TreeNode(20);
//    tn->right = tr;
//    TreeNode *ttt = new TreeNode(15);
//    tr->left = ttt;
//    TreeNode *www = new TreeNode(7);
//    ttt->right = www;
//    cout << s.countAndSay(11) << endl;
    cout << s.isValid("[])") << endl;
    return 0;
}
