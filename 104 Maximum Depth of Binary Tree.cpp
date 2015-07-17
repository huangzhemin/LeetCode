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
    int maxDepth(TreeNode* root) {
        if (! root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    TreeNode *tn = new TreeNode(1);
    TreeNode *tl = new TreeNode(2);
    tn->left = tl;
    TreeNode *tr = new TreeNode(20);
    tn->right = tr;
    TreeNode *ttt = new TreeNode(15);
    tr->left = ttt;
    TreeNode *www = new TreeNode(7);
    ttt->right = www;

    cout << s.maxDepth(tn) << endl;
    return 0;
}
