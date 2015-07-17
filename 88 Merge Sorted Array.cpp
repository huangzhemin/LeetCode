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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergeNums;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                mergeNums.push_back(nums1[i ++]);
            } else {
                mergeNums.push_back(nums2[j ++]);
            }
        }
        while (i < m) {
            mergeNums.push_back(nums1[i ++]);
        }
        while (j < n) {
            mergeNums.push_back(nums2[j ++]);
        }
        nums1 = mergeNums;
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
