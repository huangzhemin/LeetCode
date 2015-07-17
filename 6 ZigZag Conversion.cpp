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

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "") return s;
        vector<string> vecstr(numRows);
        string res;
        int bounce = 0, direct = 1;
        for (int i = 0; i<=s.size()-1; ++i) {
            vecstr[bounce].push_back(s[i]);
            if (numRows == 1) continue;
            else if (bounce == numRows-1) direct = -1;
            else if (bounce == 0) direct = 1;
            bounce += direct;
        }
        for (int i = 0; i<=numRows-1; ++i) res += vecstr[i];
        return res;
    }
};

int main() {
    Solution s;

    cout << s.reverse(-2147483648) << endl;
    return 0;
}
