//我要很直接的表达我不喜欢做这样的题的心情，因为自己很难写测试数据
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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (! root) return true;
        return like(root->left, root->right);
    }
    bool like(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return left == right;
        } else if (left->val != right->val) {
            return false;
        } else {
            return like(left->left, right->right) && like(left->right, right->left);
        }
    }
};

int main() {
    Solution s;
    TreeNode *tn = new TreeNode(1);
//    TreeNode *tl = new TreeNode(2);
//    tn->left = tl;
//    TreeNode *tr = new TreeNode(20);
//    tn->right = tr;
//    TreeNode *ttt = new TreeNode(15);
//    tr->left = ttt;
//    TreeNode *www = new TreeNode(7);
//    ttt->right = www;

    cout << s.isSymmetric(tn) << endl;
    return 0;
}
