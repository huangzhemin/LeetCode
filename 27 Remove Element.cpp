#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <map>
#include <set>
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
    int removeElement(vector<int>& nums, int val) {
        vector<int> newNums;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != val) {
                newNums.push_back(nums[i]);
            }
        }
        nums.clear();
        nums = newNums;
        return nums.size();
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
//    cout << s.countAndSay(11) << endl;
    cout << s.strStr("a", "") << endl;
    return 0;
}
