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
    //����һ���򵥵��ַ���ƥ�����⣬���ص���haystack�е�һ�γ���needle��index�����û���򷵻�-1
    //���뵽��򵥵ķ�����ɨ�跨����0 ~ haystack.length() - needle.length()
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;
        if (needle.length() == 0) return 0;
        for (int i = 0; i <= haystack.length() - needle.length(); i ++) {
            if (haystack[i] == needle[0]) {
                bool ok = true;
                for (int j = 1; j < needle.length(); j ++) {
                    if (haystack[i + j] != needle[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return i;
                }
            }
        }
        return -1;
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
    cout << s.strStr("a", "") << endl;
    return 0;
}
