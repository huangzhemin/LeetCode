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
    //�ҵ�һ���ַ�����������Ӵ�
    //ɨ�����е��ַ�����ÿ��ֻȡһ���֣������һ�����������һ��ѭ��
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int length = 0;
        string result = "";

        while (1) {
            for (int i = 0; i < strs.size(); i ++) {
                if (length == 0 && strs[i].empty()) return "";
                else {
                    if (strs[i][length] != strs[0][length] || strs[i][length] == '\0') return result;
                }
            }
            result += strs[0][length];
            length ++;
        }
    }
};

int main() {
    Solution s;
    vector<string> str;

    cout << s.longestCommonPrefix(str) << endl;
    return 0;
}
