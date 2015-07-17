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
    //一道简单的将两个单链表合并为一个列表的题目，用俩指针移动比较当前结点的值，合并为一个链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        ListNode *mergeResult;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = mergeResult;
        if (p1->val < p2->val) {
            mergeResult = p1;
            p1 = p1->next;
        } else {
            mergeResult = p2;
            p2 = p2->next;
        }

        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        while (p1) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        while (p2) {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }

        return mergeResult;
    }

    //写了一遍之后觉得没劲，题目的意思是要在不改变l1和l2的基础上来做
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if(l1 == NULL && l2 == NULL)
        return NULL;

    ListNode * tmpl1 = l1;
    ListNode * tmpl2 = l2;

    ListNode * firstNode = new ListNode(0);
    ListNode * currSortedNode = firstNode;

    while(tmpl1 != NULL && tmpl2 != NULL)
    {
        if(tmpl1->val <= tmpl2->val)
        {
            ListNode * newNode = new ListNode(tmpl1->val);
            currSortedNode->next = newNode;
            currSortedNode = newNode;
            tmpl1 = tmpl1->next;
        }
        else
        {
            ListNode * newNode = new ListNode(tmpl2->val);
            currSortedNode->next = newNode;
            currSortedNode = newNode;
            tmpl2 = tmpl2->next;
        }
    }

    while(tmpl1 != NULL)
    {
        ListNode * newNode = new ListNode(tmpl1->val);
        currSortedNode->next = newNode;
        currSortedNode = newNode;
        tmpl1 = tmpl1->next;
    }

    while(tmpl2 != NULL)
    {
        ListNode * newNode = new ListNode(tmpl2->val);
        currSortedNode->next = newNode;
        currSortedNode = newNode;
        tmpl2 = tmpl2->next;
    }

    ListNode * sortedHead = firstNode->next;
    delete firstNode;

    return sortedHead;
}
};

int main() {
    Solution s;
//    TreeNode *tn = new TreeNode(1);
//    TreeNode *tl = new TreeNode(2);
//    tn->left = tl;
//    TreeNode *tr = new TreeNode(20);
//    tn->right = tr;
//    TreeNode *ttt = new TreeNode(15);
//    tr->left = ttt;
//    TreeNode *www = new TreeNode(7);
//    ttt->right = www;
//    cout << s.countAndSay(11) << endl;
    ListNode *a = new ListNode(-30);
    ListNode *p = a;
    for (int i = -29; i < 28; i ++) {
        ListNode *temp = new ListNode(i);
        p->next = temp;
        p = p->next;
    }
    ListNode *b = new ListNode(50);
    ListNode *result = s.mergeTwoLists(a, b);
    while (result) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
    return 0;
}
