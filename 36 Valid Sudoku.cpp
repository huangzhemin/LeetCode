//这道题懒得不想构造矩阵。。。
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <map>
#include <set>
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

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool rawFlags[9][9]={false};
        bool colFlags[9][9]={false};
        bool sectionFlags[9][9]={false};
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int section = (i/3)*3+j/3;
                if(rawFlags[i][num-1] || colFlags[j][num-1]|| sectionFlags[section][num-1])
                    return false;
                else {
                    rawFlags[i][num-1] = true;
                    colFlags[j][num-1] = true;
                    sectionFlags[section][num-1] = true;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    //思路：
    //给的是一个矩阵，最简单的方法是横竖扫描
    //建立一个map，如果map里contain已经放进去的元素，则直接return false
    //扫描完毕，return true;
    bool isValidRow(char **boardNum) {
        set<char> s;
        for (int i = 0; i < 9; i ++) {
            s.clear();
            for (int j = 0; j < 9; j ++) {
                if (boardNum[i][j] == '.') continue;
                if (s.find(boardNum[i][j]) != s.end()) {
                    s.insert(boardNum[i][j]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidCol(char **boardNum) {
        set<char> s;
        for (int j = 0; j < 9; j ++) {
            s.clear();
            for (int i = 0; i < 9; i ++) {
                if (boardNum[i][j] == '.') continue;
                if (s.find(boardNum[i][j]) != s.end()) {
                    s.insert(boardNum[i][j]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidMatrix(char **boardNum) {
        set<char> s;
        for (int i = 0; i < 3; i ++) {
            s.clear();
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 3; k ++) {
                    if (boardNum[3 * i + j][3 * i + k] = '.')
                    if (s.find(boardNum[3 * i + j][3 * i + k]) != s.end()) {
                        s.insert(boardNum[3 * i + j][3 * i + k]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> >& board) {
        char **boardNum;
        boardNum = new char *[9];
        for (int i = 0; i < 9; i ++) {
            boardNum[i] = new char [9];
        }
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                boardNum[i][j] = board[i][j];
            }
        }
        if (isValidRow(boardNum) && isValidCol(boardNum) && isValidMatrix(boardNum)) return true;
        else return false;
    }
};

int main() {
    Solution s;
//    TreeNode *tn = new TreeNode(1);
//    TreeNode *tl = new TreeNode(2);
//    tn->left = tl;
//    TreeNode *tr = new TreeNode(20);
//    tn->right = tr;
//    TreeNode *ttt = new TreeNode(15);
//    tr->left = ttt;
//    TreeNode *www = new TreeNode(7);
//    ttt->right = www;
//    cout << s.countAndSay(11) << endl;
    return 0;
}
