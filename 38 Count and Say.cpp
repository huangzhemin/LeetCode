#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
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

//class Solution {
//public:
//    //˼·��
//    //����һ���򵥵��ַ���ɨ������⣬���Ǵ������������֣�����ֱ���ó������������ó���Ӧ������
//    //������ת��Ϊ�ַ���,�����������ַ���
//    //Ȼ����һ����ʱ�ı�������¼����ֵ
//    //ͨ��ͳ�Ƽ���string��
//    //��Եģ��㲻�������Ҫ˵ʲô
//    string countAndSay(int n) {
//        string numberStr = "";
//
//        while (n) {
//            numberStr += ('0' + n % 10);
//            n /= 10;
//        }
//
//        char tempRecord;
//        int numRecord = 0;
//        string result = "";
//
//        for (int i = 0; i < numberStr.length(); i ++) {
//            if (tempRecord != numberStr[i]) {
//                if (numRecord) {
//                    stringstream ss;
//                    ss << numRecord;
//                    result += tempRecord;
//                    result += ss.str();
//                }
//                numRecord = 1;
//                tempRecord = numberStr[i];
//            } else {
//                numRecord ++;
//            }
//        }
//        if (numRecord) {
//            stringstream ss;
//            ss << numRecord;
//            result += tempRecord;
//            result += ss.str();
//        }
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};

class Solution {
public:
    string countAndSay(int n) {
        vector<string> sequence(n);
        sequence[0]="1";
        for(int i=1;i<n;i++){
            sequence[i]=count_and_say(sequence[i-1]);
        }
        return sequence[n-1];
    }

    string count_and_say(string n){
        int len=n.size();
        int count=0;
        string res;
        char obj=n.at(0);
        for(int i=0;i<len;i++){
            if(n.at(i)==obj)
            count++;
            else{
                res+=count+'0';//may be wrong when count>9
                res+=obj;
                obj=n.at(i);
                count=1;
            }
        }
        if(count>1){
            res+=count+'0';
            res+=obj;
        }
        else{
            res+=1+'0';
            res+=n.at(len-1);
        }
        return res;
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
    cout << s.countAndSay(11) << endl;
    return 0;
}
