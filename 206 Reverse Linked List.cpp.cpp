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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        ListNode *p = head;
        ListNode *q = head;
        while (q) {
            p = q;
            q = q->next;
            p->next = newHead->next;
            newHead->next = p;
        }
        ListNode *result = newHead->next;
        delete newHead;
        return result;
    }
};

int main() {
    Solution s;

    cout << s.reverse(-2147483648) << endl;
    return 0;
}
