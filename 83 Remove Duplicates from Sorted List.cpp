#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *recordNode = head;
        if (recordNode) {
            ListNode *deleteNode = recordNode->next;
            while (deleteNode) {
                if (deleteNode->val == recordNode->val) {
                    recordNode->next = deleteNode->next;
                    delete deleteNode;
                    deleteNode = recordNode->next;
                } else {
                    recordNode = deleteNode;
                    deleteNode = recordNode->next;
                }
            }
        }
        return head;
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
    ListNode *myListNode = NULL;
    cout << s.deleteDuplicates(myListNode) << endl;
    return 0;
}
