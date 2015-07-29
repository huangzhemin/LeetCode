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
    //Given an integer, write a function to determine if it is a power of two.
    //简单的想一下，只需要看看，每次能否被2整除就可以了，时间复杂度是O(lgn)，采用递归书写起来会更简单，直接启用了系统栈
    //但是会增加调用时间
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        else return n % 2 ? false : isPowerOfTwo(n / 2);
    }
    //循环的话就不会碰到这种情况
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n > 1) {
            while (n != 1) {
                if (n % 2) return false;
                else n >>= 1;
            }
            return true;
        }
//        if (n < 1) {
//            while (n != 1) {
//                if (n % 2) return false;
//                else n >>= 1;file:///home/huangzm/Downloads/Algorithm_code/LEETCODE/232%20Implement%20Queue%20using%20Stacks.cpp

//            }
//            return true;
//        }

    }
};

int main() {
    Solution s;
    cout << s.isPowerOfTwo(8) << endl;
    return 0;
}
