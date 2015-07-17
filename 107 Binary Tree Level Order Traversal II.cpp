//我要很直接的表达我不喜欢做这样的题的心情，因为自己很难写测试数据
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > levels;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        if (! root) return levels;
        q1.push(root);
        while (! q1.empty() || ! q2.empty()) {
            vector<int> tempLevel;
            while (! q1.empty()) {
                root = q1.front();
                tempLevel.push_back(root->val);
                q1.pop();
                if (root->left != NULL) {
                    q2.push(root->left);
                }
                if (root->right != NULL) {
                    q2.push(root->right);
                }
            }
            levels.push_back(tempLevel);
            tempLevel.clear();

            while (! q2.empty()) {
                root = q2.front();
                tempLevel.push_back(root->val);
                q2.pop();
                if (root->left != NULL) {
                    q1.push(root->left);
                }
                if (root->right != NULL) {
                    q1.push(root->right);
                }
            }
            levels.push_back(tempLevel);
            tempLevel.clear();
        }
        if (levels.back().empty()) levels.pop_back();
        reverse(levels.begin(), levels.end());

        return levels;
    }
};

int main() {
    Solution s;
    TreeNode *tn = new TreeNode(1);
    TreeNode *tl = new TreeNode(2);
    tn->left = tl;
//    TreeNode *tr = new TreeNode(20);
//    tn->right = tr;
//    TreeNode *ttt = new TreeNode(15);
//    tr->left = ttt;
//    TreeNode *www = new TreeNode(7);
//    tr->right = www;

    vector<vector<int> > result = s.levelOrderBottom(tn);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
