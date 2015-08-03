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
    //Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    //Integers in each row are sorted in ascending from left to right.
    //Integers in each column are sorted in ascending from top to bottom.
    //思路：先写一个时间复杂度为O(n2)的
    //提交就超时间，正着比大小，会遇到小的数字的纵列，可能出现相等的情况，判断不唯一，就会出现重复检查，效率无法最大化
    //这个时候只需反过来考虑就可以了，反一个，另外一个不反，可以在O(m+n)的时间复杂度下得到结果
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.size() < 1 || matrix[0].size() < 1) return false;
        int col = matrix[0].size() - 1;
        int row = 0;
        while (col >= 0 && row < matrix.size()) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                col --;
            } else if (target > matrix[row][col]) {
                row ++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);

    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);

    row3.push_back(7);
    row3.push_back(8);
    row3.push_back(9);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    cout << s.searchMatrix(matrix, 3) << endl;

    return 0;
}
