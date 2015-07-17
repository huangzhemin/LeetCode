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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        else if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
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
