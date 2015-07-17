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
    //˼·:
    //1.�����ƼӺͣ����Ĳ����������ַ������ͣ�����˼·����ת���֣��Ӻͺ���ת��
    //2.ֱ�Ӷ��ַ������мӺͣ�������ab������λ�ã��Ӻͺ����������ַ���
    //ѡ��˼·2
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        string result = "";

        int flag = 0;
        while (i < a.length() && i < b.length()) {
            if (a[i] == '0' && b[i] == '0') {
                result += '0' + flag;
                flag = 0;
            } else if (a[i] == '1' && b[i] == '1') {
                result += '0' + flag;
                flag = 1;
            } else {
                if (flag) {
                    result += '0';
                    flag = 1;
                } else {
                    result += '1';
                    flag = 0;
                }
            }
            i ++;
        }

        while (i < a.length()) {
            if (a[i] == '1') {
                if (flag) {
                    result += '0';
                    flag = 1;
                } else {
                    result += '1';
                    flag = 0;
                }
            } else {
                result += '0' + flag;
                flag = 0;
            }
            i ++;
        }
        while (i < b.length()) {
            if (b[i] == '1') {
                if (flag) {
                    result += '0';
                    flag = 1;
                } else {
                    result += '1';
                    flag = 0;
                }
            } else {
                result += '0' + flag;
                flag = 0;
            }
            i ++;
        }
        if (flag) {
            result += '1';
        }

        reverse(result.begin(), result.end());
        return result;
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
    cout << s.addBinary("11", "1") << endl;
    return 0;
}
