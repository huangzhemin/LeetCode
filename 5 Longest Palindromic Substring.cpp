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
    //˼·��
    //����Ļ����Ӵ���������Ŀ����Ҫɨ���ˣ����Ҹ��ӶȽ���ﵽ0(n2)
    //�ȿ����ַ���s�ĳ��ȣ����е�λ�ÿ�ʼ��Ϊ���ĵ㣬�����߽߱��ߡ�
    //��дһ���������ж��Ƿ�Ϊ�����ַ���
    //����һ���򵥵�һ��ɨ��
    string longestPalindrome(string s) {
        string result;
        int maxLength = 0;
        //����
        for (int i = 0; i < s.length(); i ++) {
            //��i��λ����Ϊ����λ�ã�������ɨ�裬�ж��Ƿ�Ϊ����
//            cout << "i:" << i << endl;
            int startPos = i - 1, endPos = i + 1;

            while (startPos >= 0 && endPos < s.length()) {
                if (s[startPos] == s[endPos]) {
                    startPos --;
                    endPos ++;
                } else {
                    startPos ++;
                    endPos --;
                    break;
                }
            }
            if (startPos < 0 || endPos >= s.length()) {
                startPos ++;
                endPos --;
            }
//            cout << "starpos:" << startPos << endl;
//            cout << "endPos:" << endPos << endl;
            if (startPos >= 0 && endPos <= s.length() && endPos - startPos + 1 > maxLength) {
//                cout << startPos << endl;
//                cout << endPos << endl;
                maxLength = endPos - startPos + 1;
                result = s.substr(startPos, endPos - startPos + 1);
//                cout << "result:" << result << endl;
            }
        }
        //ż��
        for (float i = 0.5; i < s.length(); i ++) {
            //��i��λ����Ϊ����λ�ã�������ɨ�裬�ж��Ƿ�Ϊ����
//            cout << "i:" << i << endl;
            int startPos = i - 0.5, endPos = i + 0.5;

            while (startPos >= 0 && endPos < s.length()) {
                if (s[startPos] == s[endPos]) {
                    startPos --;
                    endPos ++;
                } else {
                    startPos ++;
                    endPos --;
                    break;
                }
            }
            if (startPos < 0 || endPos >= s.length()) {
                startPos ++;
                endPos --;
            }
//            cout << "starpos:" << startPos << endl;
//            cout << "endPos:" << endPos << endl;
            if (startPos >= 0 && endPos <= s.length() && endPos - startPos + 1 > maxLength) {
                maxLength = endPos - startPos + 1;
//                cout << "1:" << startPos << endl;
//                cout << "2:" << endPos << endl;
                result = s.substr(startPos, endPos - startPos + 1);
//                cout << "result:" << result << endl;
//                cout << "resultLength:" << result.length() << endl;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("asadgfsdafabcddcbadsafsdaf") << endl;
    return 0;
}
