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
    // Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
    // For example:
    // Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
    // Follow up:
    // Could you do it without any loop/recursion in O(1) runtime?
    // 思路：如果说只是简单的加到一位为止的话，还是很容易做的，但是要达到O(1)的时间复杂度就没那么容易了
//    int addDigits(int num) {
//        int temp = 0;
//        do {
//            while (num) {
//                temp += num % 10;
//                num /= 10;
//            }
//            num = temp;
//            temp = 0;
//        } while (num / 10 != 0);
//        return num;
//    }
    // 如果是O(1)复杂度，只可能用数学公式一步出结果
    // 假设num = 100a + 10b + c，则(100a + 10b + c) % 9 = (a + b + c + 99a + 9b) % 9 = (a + b + c) % 9
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main() {
    Solution s;
    cout << s.addDigits(5948) << endl;
    return 0;
}
