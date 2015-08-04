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
    //Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
    //However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    //思路：区别与1，允许多次交易，每次交易必须是先买再卖，而且同一时间只能持有一手。这下就有意思了，如何才能达到最大的收益率？
    //第一次扫描的时候记录波峰，何为波峰，前后的值都比这个值小，创立一个数组记录波峰点，在波峰点前面的波谷点买入，计算总的最大收益。
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1) return 0;
        if (prices.size() == 2) {
            if (prices[1] > prices[0]) return prices[1] - prices[0];
            else return 0;
        }

        int maxProfit = 0;
        //找波峰
        int *maxPrices = new int[prices.size()];
        for (int i = 0; i < prices.size(); i ++) {
            maxPrices[i] = 0;
        }
        //开始找波峰
        for (int i = 0; i < prices.size() - 2; i ++) {
            if (prices[i + 1] > prices[i] && prices[i + 1] >= prices[i + 2]) maxPrices[i + 1] = 1;
        }

//        for (int i = 0; i < prices.size(); i ++) {
//            cout << maxPrices[i] << endl;
//        }
        //当maxPrices为1时，计算前面为0的最小值
        int startIndex = 0;
        int endIndex = 0;
        int tempMaxPrice;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i ++) {
            if (maxPrices[i] == 1) {
                endIndex = i - 1;
                tempMaxPrice = prices[i] - minPrice;
                maxProfit += tempMaxPrice;
                startIndex = i;
                endIndex = i;
                minPrice = INT_MAX;
            } else {
                if (prices[i] < minPrice) minPrice = prices[i];
            }
        }
        int lastProfit = prices[prices.size() - 1] - minPrice;
        if (lastProfit > 0) maxProfit += lastProfit;

        delete []maxPrices;
        return maxProfit;
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
