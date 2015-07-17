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
    //思路：
    //简单的数字翻转问题，秒解
    int reverse(int x) {
        long long res = 0;
        while (x){
            res = res * 10 + x % 10;
            x = x / 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;
        return res;
    }
};

int main() {
    Solution s;

    cout << s.reverse(-2147483648) << endl;
    return 0;
}
