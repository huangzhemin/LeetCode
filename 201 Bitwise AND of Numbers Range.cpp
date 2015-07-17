#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Line {
    int num;
    vector<string> listArray;
}Line;

int main() {
    int number;
    cin >> number;

    Line *lines = new Line[number];
    for (int i = 0; i < number; i ++) {
        cin >> lines[i]->num;

        for (int j = 0; j < lines[i]->num; j ++) {
            string a;
            cin >> a;
            listArray.push_back(a);
        }
    }

    for (int i = 0; i < number; i ++) {
        for (int j = 0; j < lines[i]->num; j ++) {
            lines[i]->listArray.at(i);
        }

    }

    return 0;
}
