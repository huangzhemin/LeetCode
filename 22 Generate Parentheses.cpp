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
     vector<string> generateParenthesis(int n) {
         if (n == 1)
         {
             vector<string> res;
             res.push_back("()");
             return res;
         }
         else
         {
             vector<string> tmp = generateParenthesis(n - 1);
             vector<string> resN;
             for (int i = 0; i < tmp.size(); i++)
             {
                 int j = 0;
                 for (int k = 0; j < tmp[i].length() && k < n - 1; j++)
                 {
                     if (tmp[i][j] == '(') k++;
                 }
                 for (int m = j; m <= tmp[i].length(); m++)
                 {
                     string tp = tmp[i];
                     tp.insert(m, "()");
                     resN.push_back(tp);
                 }
             }
             return resN;
         }
     }
 };

int main() {
    Solution s;
    vector<string> result;
    result = s.generateParenthesis(3);
    for (int i = 0; i < result.size(); i ++) {
    	cout << result[i] << endl;
    }

    return 0;
}

