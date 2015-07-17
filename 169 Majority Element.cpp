#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major = nums[0];
        for(int i = 0; i < nums.size(); i ++) {
            if(count==0){
                major=nums[i];
                count++;
            }
            else if(nums[i]==major) {
                 count++;
            }
            else count--;
        }
        return major;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(5);
    cout << s.majorityElement(nums) << endl;

    return 0;
}
