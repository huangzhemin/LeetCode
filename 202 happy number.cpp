#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int>* content;

    bool isHappy(int n) {
        if(sumValue(n)<10){
            if(sumValue(n)==1)
                return true;
            else
                return false;
        }
        else{
            return isHappy(sumValue(n));
        }
    }


    int sumValue(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

};



int main() {
    Solution s;
    if (s.isHappy(20)) {
        cout << "happy" << endl;
    } else {
        cout << "unhappy" << endl;
    }
    return 0;
}
