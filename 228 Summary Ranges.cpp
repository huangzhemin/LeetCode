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
    // Given a sorted integer array without duplicates, return the summary of its ranges.
    // For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
    //思路：因为数组是有序的，所以直接对数组进行扫描，时间复杂度为O(n)
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }
        stringstream ss;
        int firstNum, lastNum;
        firstNum = nums[0];
        lastNum = firstNum;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != lastNum + 1) {
                if (firstNum == lastNum) {
                    ss << firstNum;
                } else {
                    ss << firstNum;
                    ss << "->";
                    ss << lastNum;
                }
                result.push_back(ss.str());
                ss.str("");
                firstNum = nums[i];
                lastNum = firstNum;
            } else {
                lastNum = nums[i];
            }
        }
        if (firstNum == lastNum) {
            ss << firstNum;
        } else {
            ss << firstNum;
            ss << "->";
            ss << lastNum;
        }
        result.push_back(ss.str());
        ss.str("");
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(10);
    vector<string> result = s.summaryRanges(nums);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << endl;
    }
    return 0;
}
