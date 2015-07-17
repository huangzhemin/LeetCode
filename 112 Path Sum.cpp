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
private:
    bool hasPathInner(TreeNode *root, int sum){
        int currentVal = sum - root->val;
        if(!root->left && !root->right) {
            if( currentVal == 0) return true;
            return false;
        }
        bool flag = false;
        if(root->left) flag = flag | hasPathInner(root->left, currentVal);
        if(root->right) flag = flag | hasPathInner(root->right, currentVal);
        return flag;
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        return hasPathInner(root, sum);
    }
};

int main() {
    Solution s;
    TreeNode *tn = NULL;
    cout << s.hasPathSum(tn, 1) << endl;;

    return 0;
}
