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
        //Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
    //According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//        _______6______
//       /              \
//    ___2__          ___8__
//   /      \        /      \
//   0      _4       7       9
//         /  \
//         3   5
//For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
//思路:一个比较奇葩的构想,求左边路径为0,右边路径为1,这样,每个结点就是一串01串,先找出p,q的表示串,然后根据两串求公共串,即得公共祖先结点,然后找到并返回就好了.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string pString, qString;
        pString = "";
        qString = "";
        getEachPath(root, p, q, pString, qString);
        string commonString = "";
        getCommonString(pString, qString, commonString);
        cout << "commonString: " << commonString << endl;
        return findNodeByPath(root, commonString);
    }
private:
    void getEachPath(TreeNode* root, TreeNode* p, TreeNode* q, string &pString, string &qString) {
        //广度优先搜索来查找各个路径串,不用递归,采用队列来做
        bool flag1 = 1;
        bool flag2 = 1;
        queue<TreeNode *> nodeQueue;
        queue<string> strQueue;
        nodeQueue.push(root);
        strQueue.push("");
        TreeNode *temp;
        string tempString;
        while (flag1 || flag2 && ! nodeQueue.empty()) {
             temp = nodeQueue.front();
             tempString = strQueue.front();
             if (flag1 && temp == p) {
                flag1 = 0;
                pString = tempString;
                cout << "pString: " << pString << endl;
             }
             if (flag2 && temp == q) {
                flag2 = 0;
                qString = tempString;
                cout << "qString: " << qString << endl;
             }
             if (! flag1 && ! flag2) {


                return;
             }
             if (temp->left) {
                nodeQueue.push(temp->left);
                strQueue.push(tempString+"0");
             }
             if (temp->right) {
                nodeQueue.push(temp->right);
                strQueue.push(tempString+"1");
             }
             nodeQueue.pop();
             strQueue.pop();
        }

    }

    void getCommonString(string &pString, string &qString, string &commonString) {
        if (pString.length() < qString.length()) {
            for (int i = 0; i < pString.length(); i ++) {
                if (pString[i] == qString[i]) {
                    commonString += pString[i];
                } else break;
            }
        } else {
            for (int i = 0; i < qString.length(); i ++) {
                if (pString[i] == qString[i]) {
                    commonString += pString[i];
                } else break;
            }
        }
        return;
    }

    TreeNode* findNodeByPath(TreeNode *root, string &path) {
        TreeNode *result = root;
        for (int i = 0; i < path.length(); i ++) {

            if (path[i] == '0') result = result->left;
            else result = result->right;
        }
        return result;
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
