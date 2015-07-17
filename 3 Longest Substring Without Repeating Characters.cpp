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

//class Solution {
//public:
//    //˼·��
//    //�������һ��������˼�����⣬�����Ƿ��������Ŀ��˼����Ҫ
//    //д�������������Ӧ��ȥдһƪ��־������¼һ�������������·����
//    //˵�����⣬��Ȼ�������ظ���������Ӵ��ĳ��ȣ���ô��εõ���Ĺ����Ӵ�
//    //˵���ף�����һ������˼�������⡣
//    int lengthOfLongestSubstring(string s) {
//        vector<char> charQueue; //���charSet�Ǽ�¼S���ַ��Ĵ���
//        int maxLength = 0;
//        int length = 0;
//        for (int i = 0; i < s.length() - maxLength; i ++) {
//            if (length != 0) {
//                charQueue.erase(charQueue.begin(), charQueue.begin() + 1);
//                length --;
//            }
////            cout << "length1:" << length << endl;
//            for (int j = i + charQueue.size(); j < s.length(); j ++) {
//                if (! findChar(charQueue, s[j])) {
////                    cout << "s[" << j << "]: " << s[j] << endl;
//                    charQueue.push_back(s[j]);
//                    length ++;
//                } else {
//                    break;
//                }
////                cout << "i: " << i << endl;
////                cout << "j: " << j << endl;
////                cout << "length: " << length << endl;
//            }
//            if (maxLength < length) maxLength = length;
//        }
//        return maxLength;
//    }
//
//    bool findChar(vector<char> charQueue, char character) {
//        for (int i = 0; i < charQueue.size(); i ++) {
//            if (charQueue[i] == character) return true;
//        }
//        return false;
//    }
//};

class Solution {
public:
    //˼·��
    //�������һ��������˼�����⣬�����Ƿ��������Ŀ��˼����Ҫ
    //д�������������Ӧ��ȥдһƪ��־������¼һ�������������·����
    //˵�����⣬��Ȼ�������ظ���������Ӵ��ĳ��ȣ���ô��εõ���Ĺ����Ӵ�
    //˵���ף�����һ������˼�������⡣
    int lengthOfLongestSubstring(string s) {
        string charQueue; //���charSet�Ǽ�¼S���ַ��Ĵ���
        int maxLength = 0;
        int length = 0;
        for (int i = 0; i < s.length() - maxLength; i ++) {
            if (length != 0) {
                charQueue.erase(0, 1);
                length --;
            }
            for (int j = i + charQueue.size(); j < s.length(); j ++) {
                if (charQueue.find(s[j]) == s.npos) {
                    charQueue += s[j];
                    length ++;
                } else {
                    break;
                }
            }
            if (maxLength < length) maxLength = length;
        }
        return maxLength;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("aab") << endl;
    return 0;
}
