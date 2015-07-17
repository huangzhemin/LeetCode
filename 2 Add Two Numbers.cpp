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
    //这道题是用两个单链表表示两个数字，加和之后输出一个结果单链表
    //而且数字在单链表中的表示是逆序的
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultHead = new ListNode(0);
        ListNode *fuck = resultHead;
        ListNode *p = l1;
        ListNode *q = l2;
        int flag = 0;
        while (p && q) {
            ListNode *tempNode = new ListNode(0);
            int val = p->val + q->val + flag;
            if (val >= 10) {
                tempNode->val = val - 10;
                flag = 1;
            } else {
                tempNode->val = val;
                flag = 0;
            }
            fuck->next = tempNode;
            fuck = fuck->next;
            p = p->next;
            q = q->next;
        }
        while (p) {
            ListNode *tempNode = new ListNode(0);
            int val = p->val + flag;
            if (val >= 10) {
                tempNode->val = val - 10;
                flag = 1;
            } else {
                tempNode->val = val;
                flag = 0;
            }
            fuck->next = tempNode;
            fuck = fuck->next;
            p = p->next;
        }
        while (q) {
            ListNode *tempNode = new ListNode(0);
            int val = q->val + flag;
            if (val >= 10) {
                tempNode->val = val - 10;
                flag = 1;
            } else {
                tempNode->val = val;
                flag = 0;
            }
            fuck->next = tempNode;
            fuck = fuck->next;
            q = q->next;
        }
        if (flag) {
            ListNode *tempNode = new ListNode(1);
            fuck->next = tempNode;
        }
        p = resultHead;
        resultHead = resultHead->next;
        delete p;
        return resultHead;
    }
};

int main() {
    Solution s;
    ListNode *p = new ListNode(0);
    ListNode *q = new ListNode(0);
    ListNode *result = s.addTwoNumbers(p, q);
    while (result) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
    return 0;
}
