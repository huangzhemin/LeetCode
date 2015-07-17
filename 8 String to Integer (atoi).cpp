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
    //���ַ���ת��Ϊ�����ٻ�����������Ŀ
    //��Ҫ���Ƿ���
    //��Ҫ�����Ƿ�����ĸ����
    int myAtoi(string str) {
        int flag = 1;
        int result = 0;
        if (str.empty()) return 0;
        //��ʼɨ���ַ���
        while (1) {
            if (str[0] == ' ' || str[0] == '\t') str.erase(0, 1);
            else break;
        }
        if (str[0] == '-' || str[0] == '+') {
            if (str[0] == '-') flag = -1;
            else flag = 1;
            int i = 1;
            while (str[i]) {
               if (str[i] >= '0' && str[i] <= '9') {
                   result *= 10;
                   result += str[i] - '0';
                   i ++;
                   if (result > INT_MAX) return flag > 0 ? INT_MAX : INT_MIN;
               } else {
                   cout << result << endl;
                   return result *= flag;
               }
            }
            result *= flag;
        } else {
            int i = 0;
            while (str[i]) {
               if (str[i] >= '0' && str[i] <= '9') {
                   result *= 10;
                   result += str[i] - '0';
                   i ++;
                   if (result > INT_MAX) return flag > 0 ? INT_MAX : INT_MIN;
               } else {
                   cout << result << endl;
                   return result;
               }
            }
        }

        return result;
    }
    //���ϵĽⷨ������һ����Χ��
    int myAtoi(string str) {
        long res = 0;
        int i=0;
        int sign = 1;

        while(str[i]==' ') i++;
        if(str[i] == '-' || str[i] == '+')
        {
            sign = str[i++] == '-'?-1:1;
        }
        while(str[i]>='0' && str[i]<='9')
        {
            res = res*10 + str[i++]-'0';
            if(res>INT_MAX) return sign>0?INT_MAX:INT_MIN;
        }
        return res*sign;

    }
};

int main() {
    Solution s;

    cout << s.myAtoi("2147483648") << endl;
    return 0;
}
