#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
    //将二叉树对称转换，从根节点开始，直接向下将左右互换
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode *temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        } else {
            return NULL;
        }
    }
};

int main() {
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
