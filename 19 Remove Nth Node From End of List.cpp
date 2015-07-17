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

class Solution {
public:
    //思路：
    //这道题告诉了头结点，删除倒数第几个数字
    //但是首先的知道删除结点的前面的那个结点
    //所以需要先扫描一遍链表，知道具体的长度，然后定位删除位置
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        int length = 0;
//        ListNode *p = head;
//        while (p) {
//            p = p->next;
//            length ++;
//        }
//        cout << length << endl;
//        if (length == n) {
//            p = head->next;
//            delete head;
//            head = p;
//            return head;
//        }
//        p = head;
//        for (int i = 0; i < length - n - 1; i ++) {
//            p = p->next;
//        }
//        ListNode *q = p->next;
//        p->next = q->next;
//        delete q;
//
//        return head;
//    }

    //提交之后的表现不理想
    //程序还需要优化
    //思路：用两指针指向头结点，一个移动n后另一个开始移动
    //这样在一个移动到尾结点的时候，另一个刚好移动到删除结点的前一个位置

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *p = newHead;
        ListNode *q = newHead;

        while (n --) {
            q = q->next;
        }
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        if (q) {
            p->next = q->next;
            delete q;
        }

        return newHead->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *newHead = s.removeNthFromEnd(head, 0);
    while (newHead) {
        cout << newHead->val << endl;
        newHead = newHead->next;
    }
    return 0;
}
