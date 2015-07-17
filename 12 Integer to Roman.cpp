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
	//又遇罗马数字，不过这次正好相反，不是罗马数字转换为数字，而是数字转换为罗马数字
	string intToRoman( int n )
	{
		string s = "";

		for( ; n / 1000 ; )     { s += "M";     n -= 1000; }
		if( n >= 900 )          { s += "CM";    n -=  900; }
		if ( n >= 500 )         { s += "D";     n -=  500; }
		if ( n >= 400 )         { s += "CD";    n -=  400; }
		for( ; n / 100 ; )      { s += "C";     n -=  100; }
		if( n >= 90 )           { s += "XC";    n -=   90; }
		if ( n >= 50 )          { s += "L";     n -=   50; }
		if ( n >= 40 )          { s += "XL";    n -=   40; }
		for( ; n / 10 ; )       { s += "X";     n -=   10; }
		if ( n == 9 )           { s += "IX";    return s;  }
		if ( n >= 5 )           { s += "V";     n -=    5; }
		if ( n == 4 )           { s += "IV";    return s;  }
		for( ; n / 1 ; )        { s += "I";     n -=    1; }
		return s;
	}
};

int main() {
    Solution s;
    vector<string> str;

    cout << s.intToRoman(1343) << endl;
    return 0;
}
