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
	//思路：
	 //这道题从一个给定的vector中选出从小到大排列的三个数字，并使得相加的和为0
	 //首先将数字做一个排序
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > retVec;
        if (num.size()<3) return retVec;
        std::sort(num.begin(), num.end());

        for(int i=0; i<num.size()-2;i++) {
            if(num[i]>0) break;
            for(int j=i+1; j<num.size()-1;j++) {
                if(num[i] + num[j] >0) break;
                for(int k=j+1; k<num.size(); k++) {
                    if(num[i] + num[j] + num[k] == 0) {
                        vector<int> newVec;
                        newVec.push_back(num[i]);
                        newVec.push_back(num[j]);
                        newVec.push_back(num[k]);
                        std::sort(newVec.begin(), newVec.end());
                        retVec.push_back(newVec);
                    } else if (num[i] + num[j] + num[k] > 0)
                        break;
                    while (k<num.size()-1 && num[k+1] == num[k]) k++;
                }
                while (j<num.size()-2 && num[j+1] == num[j]) j++;
            }
            while (i<num.size()-3 &&  num[i+1] == num[i]) i++;
        }
        return retVec;
    }
};

int main() {
    Solution s;
    vector<vector<int> > a;
    int x[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> nums;
    for (int i = 0; i < 109; i ++) {
    	nums.push_back(x[i]);
    }
    a = s.threeSum(nums);
	for (int i = 0; i < a.size(); i ++) {
		 for (int j = 0; j < a[i].size(); j ++) {
			 cout << a[i][j] << ' ';
		 }
		 cout << endl;
	}
	cout << endl;
    return 0;
}

