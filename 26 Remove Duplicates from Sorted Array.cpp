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
    //思路：
    //这道题 思路就是让出现的元素保持在一个
    //不让申请额外的数组空间，只能增加时间来多次扫描
    //每次扫描的时候记录下来具体的个数，删除第一个后面出现的多余元素
    //犯了一个大忌，没理解题目意思，只需要返回最终的长度即可
    //而且数组是已经排过序的，我操
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int currPtr = 0;
        for(int i = 1; i<nums.size(); i++) {
           if(nums[currPtr] != nums[i]) {
               nums[++currPtr] = nums[i];
           }
        }
        return ++currPtr;
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
