//������119��ֱ�ӵ���119��û�뵽������ô��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex+1,0);
        row[0]=1;
        for(int i=1;i<=rowIndex;i++)
            for(int j=i;j>=1;j--)
                row[j]=row[j-1]+row[j];

        return(row);
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri;
        for (int i = 0; i < numRows; i ++) {
            pascalTri.push_back(getRow(i));
        }
        return pascalTri;
    }

    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex+1,0);
        row[0]=1;
        for(int i=1;i<=rowIndex;i++)
            for(int j=i;j>=1;j--)
                row[j]=row[j-1]+row[j];

        return(row);
    }
};

int main() {
    Solution s;
    vector<int> result = s.getRow(5);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}
