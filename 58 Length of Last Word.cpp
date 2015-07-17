#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
    //直接从后往前扫描，遇到空格停止
    int lengthOfLastWord(string s) {
        int lastWordLength = 0;
        bool firstNotSpace = false;
        for (int i = s.length() - 1; i >= 0; i --) {
            if (s[i] != ' ') {
                firstNotSpace = true;
                lastWordLength ++;
            } else {
                if (firstNotSpace)
                    break;
            }
        }
        return lastWordLength;
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
    cout << s.lengthOfLastWord("Hello World") << endl;
    return 0;
}
