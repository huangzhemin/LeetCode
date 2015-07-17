#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
//    bool isPalindrome(string s) {
//        string newS;
//        for (int i = 0; i < s.size(); i ++) {
//            if(isalnum(s[i])) {
//                newS += tolower(s[i]);
//            }
//        }
//
//        int i =  0;
//        int j = newS.size() - 1;
//        while (i < j) {
//            if (newS[i] == newS[j]) {
//                i ++;
//                j --;
//            } else {
//                return false;
//            }
//        }
//
//        return true;
//    }

    bool isPalindrome(string s) {
        int i =  0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && ! isalnum(s[i])) {
                i ++;
            }
            while (i < j && ! isalnum(s[j])) {
                j --;
            }

            if (tolower(s[i]) == tolower(s[j])) {
                i ++;
                j --;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;


    return 0;
}
