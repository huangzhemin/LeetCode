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
    //˼·��
    //����� ˼·�����ó��ֵ�Ԫ�ر�����һ��
    //����������������ռ䣬ֻ������ʱ�������ɨ��
    //ÿ��ɨ���ʱ���¼��������ĸ�����ɾ����һ��������ֵĶ���Ԫ��
    //����һ����ɣ�û�����Ŀ��˼��ֻ��Ҫ�������յĳ��ȼ���
    //�����������Ѿ��Ź���ģ��Ҳ�
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int currPtr = 0;
        for(int i = 1; i<nums.size(); i++) {
           if(nums[currPtr] != nums[i]) {
               nums[++currPtr] = nums[i];
           }
        }
        return ++currPtr;
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
    cout << s.strStr("a", "") << endl;
    return 0;
}
