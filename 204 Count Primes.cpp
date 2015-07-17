#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//class Solution {
//public:
//    int countPrimes(int n) {
//        if (n < 3) return 0;
//
//        int sum = 0;
//        for (int i = 3; i < n; i ++) {
//            if (isPrime(i)) {
//                sum ++;
//            }
//        }
//        return sum;
//    }
//
//    bool isPrime(int x)
//    {
//        int end = sqrt(x);
//        for (int i=2;i<end;i++){
//            if(x%i==0) {
//                return false;
//            }
//        }
//        return true;
//    }
//};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        bool* primes = new bool[n];
        int sqr = sqrt(n-1);
        for (int i = 3; i <= sqr; i += 2){
            if (primes[i] == false){
                for (int j = i * i; j < n; j += i)
                    primes[j] = true;
            }
        }
        int sum = 1;
        for (int i = 3; i < n; i += 2)
            sum += (primes[i] == false) ? 1 : 0;
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(3000000) << endl;
    return 0;
}
