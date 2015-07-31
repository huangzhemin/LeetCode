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
    // Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
    //Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
    //思路：删除一个结点，给定的入口只有需要删除的节点，这样的话，直接删除该结点，显然是不现实的，必须要回退到上一个结点，修改next指针，
    //所以可以考虑把后面的val移入该结点，删除它的next结点
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};

int main() {
    Solution s;
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(2);
    TreeNode *root = new TreeNode(0);
    root->left = p;
    root->right = q;
    TreeNode *a = new TreeNode(3);
    p->left = a;
    TreeNode *b = new TreeNode(4);
    a->right = b;
    TreeNode *c = new TreeNode(5);
    b->left = c;

    TreeNode *result = s.lowestCommonAncestor(root, q, c);
    cout << result->val << endl;
    return 0;
}
