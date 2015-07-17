#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while (n) {
            sum += n / 5;
            n /= 5;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.trailingZeroes(10) << endl;

    return 0;
}
