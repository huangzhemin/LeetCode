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
    //回文，如果是申请了空间的话，这道题目很容易，但是题目要求是控制在O(n)的时间复杂度和O(1)的空间复杂度
    //所以解决这个问题的方法就是求启用两个指针，分别指向两边，然后判断两个指针指的值是否相等
    //该方法超时
    bool isPalindrome(ListNode* head) {
        if (! head || !(head->next)) return true;
        ListNode *leftElement = head;
        ListNode *rightElement = head;
        //移动右指针到结束位置
        while (rightElement->next) rightElement = rightElement->next;
        //比较左右指针的值
        while (leftElement != rightElement && leftElement->next != rightElement && leftElement->val == rightElement->val) {
            leftElement = leftElement->next;
            ListNode *tempElement = leftElement;
            while (tempElement->next != rightElement) tempElement = tempElement->next;
            rightElement = tempElement;
        }
        if (leftElement->val == rightElement->val) return true;
        else return false;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *second = reverseList(fast);
        while (second && second->val == head->val) {
            second = second->next;
            head = head->next;
        }
        slow->next = fast;
        return second == NULL;
    }
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main() {
    Solution s;

    return 0;
}
