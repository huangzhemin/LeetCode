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
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() <= 0) return result;
        string int2Str[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


        vector<int> vecDigitIndexs(digits.length(), 0);
        while (true)
        {
            string strResult = "";
            for (size_t i = 0; i < digits.length(); ++i)
            {
                strResult += int2Str[digits[i] - '0'][vecDigitIndexs[i]];
            }
            result.push_back(strResult);

            int nIndex = digits.length() - 1;
            while (nIndex >= 0)
            {
                vecDigitIndexs[nIndex] += 1;
                if (vecDigitIndexs[nIndex] >= int2Str[digits[nIndex] - '0'].length())
                {
                    vecDigitIndexs[nIndex] = 0;
                    --nIndex;
                }
                else
                    break;
            }
            if (nIndex < 0)
            {
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> a = s.letterCombinations("34");
    for (int i = 0; i < a.size(); i ++) {
        cout << a[i] << endl;
    }
    return 0;
}
