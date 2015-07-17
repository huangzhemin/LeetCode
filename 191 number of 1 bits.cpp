#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
//    int hammingWeight(uint32_t n) {
//        int sum = 0;
//        while (n) {
//            if (n % 2 == 1) {
//                sum ++;
//            }
//            n /= 2;
//        }
//        return sum;
//    }

    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n) {
            sum += n & 1;
            n >>= 1;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(1000000000000000000) << endl;

    return 0;
}
