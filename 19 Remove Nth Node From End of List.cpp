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
    //˼·��
    //����������ͷ��㣬ɾ�������ڼ�������
    //�������ȵ�֪��ɾ������ǰ����Ǹ����
    //������Ҫ��ɨ��һ������֪������ĳ��ȣ�Ȼ��λɾ��λ��
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

    //�ύ֮��ı��ֲ�����
    //������Ҫ�Ż�
    //˼·������ָ��ָ��ͷ��㣬һ���ƶ�n����һ����ʼ�ƶ�
    //������һ���ƶ���β����ʱ����һ���պ��ƶ���ɾ������ǰһ��λ��

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
