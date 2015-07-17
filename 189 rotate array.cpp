#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int temp;
        if (n != k) {
            k %= n;
            reverseArray(nums, 0, n - 1);
            reverseArray(nums, 0, k - 1);
            reverseArray(nums, k, n - 1);
        }

        for (int i = 0; i < n; i ++) {
            cout << nums[i] << ' ';
        }
        cout <<endl;
    }

    void reverseArray(int nums[], int startLoc, int endLoc) {
        int temp;
        while (startLoc < endLoc) {
            temp = nums[startLoc];
            nums[startLoc] = nums[endLoc];
            nums[endLoc] = temp;

            startLoc ++;
            endLoc --;
        }
    }
};

int main() {
    Solution s;
    int nums[] = {1, 2, 3};
    int n = 3;
    int k = 2;
    s.rotate(nums, n, k);

    return 0;
}
