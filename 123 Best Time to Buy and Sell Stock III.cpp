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
    //Say you have an array for which the ith element is the price of a given stock on day i.
    //Design an algorithm to find the maximum profit. You may complete at most two transactions.
    //思路：区别与2，允许多次交易，每次交易必须是先买再卖，而且同一时间只能持有一手，而且最多交易两次。
    //直接使用动态规划的方法。
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size==0 || size ==1) return 0;
        int profit1[size];
        int profit2[size];
        int local_min=prices[0];
        int local_max = prices[size-1];
        int j = size-2;
        int result=0;
        profit1[0]=0;
        profit2[size-1] = 0;
        for(int i = 1;i<size+1 && j >=0;i++,j--)
        {
            profit1[i] = max(profit1[i-1],prices[i]-local_min);
            local_min= min(local_min,prices[i]);
            profit2[j] = max(profit2[j+1],local_max-prices[j]);
            local_max = max(local_max,prices[j]);
        }
        for(int i = 1; i<size; i++)
        {
            result = max(result,profit1[i]+profit2[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> price;
    price.push_back(1);
    price.push_back(2);
    price.push_back(4);
//    price.push_back(2);
//    price.push_back(6);
//    price.push_back(6);
//    price.push_back(2);
//    price.push_back(9);
//    price.push_back(1);
//    price.push_back(0);
//    price.push_back(7);
//    price.push_back(4);
//    price.push_back(5);
//    price.push_back(0);

    cout << endl << s.maxProfit(price) << endl;
    return 0;
}
