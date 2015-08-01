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
    //Given two strings s and t, write a function to determine if t is an anagram of s.
    //For example,
    //s = "anagram", t = "nagaram", return true.
    //s = "rat", t = "car", return false.
    //思路：看到这个题的第一反应就是统计出现的字母以及字母出现的次数，如果这个串只包含字母的话
    //在仔细思考一下，包含的不仅仅为英文小写字母，很可能测试用例里面会包含大写字母，毕竟是字谜游戏，当然只是猜测，如果是这样的话
    //感觉现在写的代码的成本就比较高了，那怎么做呢？用hash表吧，如果碰到某个字母就把它的value和count当做key、value输入
    //对于第二个字符串，直接去扫描，有则，count减1，无，则直接返回false
    bool isAnagram(string s, string t) {
        //首先判断长度，如果长度都不相等的话，就直接返回false
        if (s.length() != t.length()) return false;
        map<char, int> charCountRecordMap;
        //遍历字符串s
        for (int i = 0; i < s.length(); i ++) {
            if (charCountRecordMap.find(s[i]) == charCountRecordMap.end()) {
                charCountRecordMap[s[i]] = 1;
            } else {
                charCountRecordMap[s[i]] ++;
            }
        }
        //扫描字符串t
        for (int i = 0; i < t.length(); i ++) {
            if (charCountRecordMap.find(t[i]) == charCountRecordMap.end()) {
                return false;
            } else {
                charCountRecordMap[t[i]] --;
            }
        }
        //扫描map，判断是否其中的value为0，如果是的话，返回true，反之返回false
        map<char, int>::iterator iter;
        for (iter = charCountRecordMap.begin(); iter != charCountRecordMap.end(); iter ++) {
            if (iter->second < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isAnagram("a", "b") << endl;
    return 0;
}
