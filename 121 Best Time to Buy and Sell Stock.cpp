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
    //Say you have an array for which the ith element is the price of a given stock on day i.=
    //If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
    //思路：利润最大就是卖出价-买入价最大，而卖出价一定是在时间上后于买入价，想一想只用在O(n)时间复杂度下就能完成。
    //买入价肯定是在前面，所以直接记录最低价格，和后面的数字到与前面最小的差价。
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i ++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            else {
                int tempProfit = prices[i] - minPrice;
                if (tempProfit > maxProfit) maxProfit = tempProfit;
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution s;
    return 0;
}
