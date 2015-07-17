//我要很直接的表达我不喜欢做这样的题的心情，因为自己很难写测试数据
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (! root) return true;
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);

    }
    int depth(TreeNode *node) {
        if (! node) return 0;
        return max(depth(node->left) + 1, depth(node->right) + 1);
    }
};

int main() {
    Solution s;
    TreeNode *tn = new TreeNode(1);
    TreeNode *tl = new TreeNode(2);
    tn->left = tl;
    TreeNode *tr = new TreeNode(3);
    tn->right = tr;
    TreeNode *ttt = new TreeNode(4);
    tr->left = ttt;
    TreeNode *www = new TreeNode(5);
    tl->left = www;
    cout << s.minDepth(tn) << endl;

    return 0;
}
