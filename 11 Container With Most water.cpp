#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <vector>

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
	//第一次在linux下写leetcode代码，这个要纪念一下
	//不知道这个会不会在其他环境中乱码，反正之前在windows下的代码中文出现了乱码。
	//现在还搞不清楚要干什么的情况下，先做一道leetcode题目让自己安静下来，希望不要浪费太多时间
	//这道题目是之前阿里算法笔试的最后一道题，求储水量
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1, ans = 0;
		while (j > i) {
			ans = max(min(height[i], height[j]) * (j - i), ans);
			if (height[i] > height[j])
				j--;
			else
				i++;
		}
		return ans;
	}
};

int main() {
    Solution s;

    cout << s.maxArea() << endl;
    return 0;
}
