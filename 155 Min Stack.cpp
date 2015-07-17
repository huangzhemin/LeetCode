#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
protected:
    stack<int> data;
    stack<int> min;

public:

    void push(int x) {

        // If empty
        if (min.empty()) {
            data.push(x);
            min.push(x);
            return;
        }

        // Not empty
        data.push(x);

        if (x <= min.top())
            min.push(x);

    }

    void pop() {

        if (!min.empty()) {
            if (data.top() == min.top())
                min.pop();
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};

int main() {
    MinStack ms;


    return 0;
}
