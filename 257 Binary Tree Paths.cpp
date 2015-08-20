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
    // Given a binary tree, return all root-to-leaf paths.
    // For example, given the following binary tree:
    //    1
    //  /   \
    // 2     3
    //  \
    //   5
    // All root-to-leaf paths are:
    // ["1->2->5", "1->3"]
    // 思路：还是用递归比较容易，可以用深度遍历
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (! root) return result;
        string path;
        this->binaryTreePaths(root, path, result);
        return result;
    }

    void binaryTreePaths(TreeNode* root, string s, vector<string>& result) {
        if (! root) return;
        stringstream ss;
        ss << root->val;
        if (! root->left && ! root->right) {
            result.push_back(s.empty() ? (s + ss.str()) : (s + "->" + ss.str()));
            return;
        }
        binaryTreePaths(root->left, s.empty() ? (s + ss.str()) : (s + "->" + ss.str()), result);
        binaryTreePaths(root->right, s.empty() ? (s + ss.str()) : (s + "->" + ss.str()), result);
    }
};

int main() {
    Solution s;

    return 0;
}
