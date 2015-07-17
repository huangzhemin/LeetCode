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
    //�ж�һ�������Ƿ�Ϊ�����������Ҳ�Ҫ���������ռ䣬��δ���������ȡ��Ӧ����������
    //����Ҫ�ж��Ƿ�Ϊ������������Ҫ����������
    bool isPalindrome(int x) {
        if (x < 0) return false;

        if (reverseInt(x) == x) return true;

        return false;
    }

    int reverseInt(int x) {
        int result = 0;
        while (x) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
};

int main() {
    Solution s;

    cout << s.isPalindrome(-1) << endl;
    return 0;
}
