#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> split(string str, string pattern)
    {
        vector<string> ret;
        if(pattern.empty()) return ret;
        size_t start=0,index=str.find_first_of(pattern,0);
        while(index!=str.npos)
        {
            if(start!=index)
            ret.push_back(str.substr(start,index-start));
            start=index+1;
            index=str.find_first_of(pattern,start);
            }
        if(!str.substr(start).empty())
            ret.push_back(str.substr(start));
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<string> result1 = split(version1, ".");
        vector<string> result2 = split(version2, ".");

        for (int i = 0; i < result1.size(); i ++) {

            cout << result1[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < result2.size(); i ++) {
            cout << result2[i] << ' ';
        }
        cout << endl;
        if (result1[0] < result2[0]) {
            return -1;
        } else if (result1[0] > result2[0]) {
            return 1;
        } else {
            if (result1[1] < result2[1]) {
                return -1;
            } else if (result1[1] > result2[1]) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    int compareVersion(string version1, string version2) {
    int i = 0;
    int j = 0;
    int n1 = version1.size();
    int n2 = version2.size();

    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }

        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }

        if(num1>num2) return 1;
        else if(num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }

    return 0;
}
};

int main() {
    Solution s;
    string a = "1.34";
    string b = "1.35";
    cout << s.compareVersion(a, b) << endl;

    return 0;
}
