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
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> result;
        int flag;
        for (int i = 0; i < digits.size(); i ++) {
            if (i == 0) {
                if (digits[0] + 1 == 10) {
                    result.push_back(0);
                    flag = 1;
                } else {
                    result.push_back(digits[0] + 1);
                    flag = 0;
                }
            }

            if (i > 0) {
                if (digits[i] + flag == 10) {
                    result.push_back(0);
                    flag = 1;
                } else {
                    result.push_back(digits[i] + flag);
                    flag = 0;
                }
            }
        }
        if (flag) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
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
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    vector<int> result = s.plusOne(a);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << endl;
    }
    return 0;
}
