//这个代码绝了，直接就accept了，主函数无法运行，构造的时候有问题。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
}ListNode;


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA) {
            lengthA ++;
            tempA = tempA->next;
        }
        while (tempB) {
            lengthB ++;
            tempB = tempB->next;
        }

        int lengthDiff = lengthA - lengthB;
        tempA = headA;
        tempB = headB;
        while (lengthDiff < 0) {
            tempB = tempB->next;
            lengthDiff ++;
        }
        while (lengthDiff > 0) {
            tempA = tempA->next;
            lengthDiff --;
        }
        while (tempA && tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};

int main() {
    ListNode *a, *b;
    ListNode *a1 = new ListNode();
    a1->val = 1;
    a->next = a1;
    ListNode *a2 = new ListNode();
    a2->val = 2;
    a1->next = a2;
    ListNode *b1 = new ListNode();
    b1->val = 1;
    b->next = b1;
    ListNode *b2 = new ListNode();
    b2->val = 2;
    b1->next = b2;
    ListNode *b3 = new ListNode();
    b3->val = 3;
    b2->next = b3;

    ListNode *c1 = new ListNode();
    c1->val = 5;
    a2->next = c1;
    b3->next = c1;

    ListNode *c2 = new ListNode();
    c2->val = 6;
    c1->next = c2;

    Solution s;

//    cout << s.getIntersectionNode(a, b)->val << endl;

    return 0;
}
