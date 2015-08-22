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
    // Write a program to check whether a given number is an ugly number.
    // Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
    // Note that 1 is typically treated as an ugly number.
    // 思路：最传统的思想就是看分解完是否为素数

    bool isUgly(int num) {
        if (num) {
            if (num == 1) return true;
            while (num % 2 == 0) num /= 2;
            while (num % 3 == 0) num /= 3;
            while (num % 5 == 0) num /= 5;
            if (num != 1) return false;
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isUgly(14) << endl;
    return 0;
}
