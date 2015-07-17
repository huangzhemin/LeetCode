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
    //思路：
    //计算两个矩形相交的面积是该题的重点
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_width = max(min(C, G) - max(A, E), 0);
        int overlap_height = max(min(D, H) - max(B, F), 0);
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap_width * overlap_height;
    }
};

int main() {
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
