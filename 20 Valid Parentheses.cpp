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
    //˼·��
    //�����Ҫ���õ�ջ��˼��
    //������ߵľ�ѹջ�������ұ߷��ž���ջ
    //���ջ��Ԫ�ز�����ջԪ�ص�����ţ���ֱ�ӷ���false
    //���ɨ����ϣ����ջ�Ĵ�СΪ0���򷵻�true
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
