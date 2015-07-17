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
//    bool containsDuplicate(vector<int>& nums) {
//        set<int> numSet;
//        for (int i = 0; i < nums.size(); i ++) {
//            if (numSet.find(nums[i]) == numSet.end()) {
//                numSet.insert(nums[i]);
//            } else {
//                return true;
//            }
//        }
//        return false;
//    }
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        return numSet.size() != nums.size();
    }
};

int main() {
    Solution s;

    cout << s.reverse(-2147483648) << endl;
    return 0;
}
