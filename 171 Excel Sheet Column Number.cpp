#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        int n = s.size();
        int mulNum = 1;
        for (int i = n - 1; i >= 0; i --) {
            num += mulNum * (s[i] - 'A' + 1);
            mulNum *= 26;
        }
        return num;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("AAA") << endl;

    return 0;
}
