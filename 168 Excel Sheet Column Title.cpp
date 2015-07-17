#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n) {
            n -= 1;
            char temp = n % 26 + 'A';
            result += temp;
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(27) << endl;

    return 0;
}
