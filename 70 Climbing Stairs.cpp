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

 typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        int i;
        dp[0] = 0;

        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;

        dp[1] = 1;
        dp[2] = 2;
        for(i=3; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
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
    cout << s.climbStairs(44) << endl;
    return 0;
}
