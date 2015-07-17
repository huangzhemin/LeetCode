#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
}ListNode;

class Solution {
public:
    ListNode *head = NULL;

    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head;
        while (p) {
            if (p->val == val) {
                ListNode *temp = p;
                p = p->next;
                delete temp;
                temp = NULL;
            }
            if (p) {
                ListNode *q = p->next;
                if (q && q->val == val) {
                    p->next = q->next;
                    delete q;
                    q = NULL;
                }
                p = p->next;
            }
        }

        return head;

//        ListNode dummy(0);
//        ListNode* prev = &dummy;
//
//        while (head)
//        {
//            if (head->val != val)
//                prev->next = head, prev=head;
//
//            head = head->next;
//        }
//
//        prev->next = 0;
//        return dummy.next;
    }

    void init(vector<int>* content) {
        head = new ListNode();
        head->val = content->at(0);
        head->next = NULL;
        ListNode *p = head;

        for (int i = 1; i < content->size(); i ++) {
            ListNode *node = new ListNode();
            node->val = content->at(i);
            node->next = NULL;
            p->next = node;
            p = node;
        }
        show();
    }

    void show () {

        ListNode *p = head;
        while (p) {
            cout << p->val << ' ';
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    vector<int>* content = new vector<int>();
    content->push_back(1);

    Solution s;
    s.init(content);

    s.removeElements(s.head, 1);

    s.show();

    return 0;
}
