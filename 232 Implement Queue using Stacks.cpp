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

class Queue {
public:
    //Implement the following operations of a queue using stacks.
    //push(x) -- Push element x to the back of queue.
    //pop() -- Removes the element from in front of queue.
    //peek() -- Get the front element.
    //empty() -- Return whether the queue is empty.
    //刚刚睡起来，写个程序热身
    //思路：简单的实现一下基础，不过好歹给个结构啊，坑～～

    // Push element x to the back of queue.
    void push(int x) {
        myQueue.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        //这个只能全部弹栈，再压栈了
        while (! myQueue.empty()) {
            tempQueue.push(myQueue.top());
            myQueue.pop();
        }
        tempQueue.pop();
        while (! tempQueue.empty()) {
            myQueue.push(tempQueue.top());
            tempQueue.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while (! myQueue.empty()) {
            tempQueue.push(myQueue.top());
            myQueue.pop();
        }
        int result = tempQueue.top();
        while (! tempQueue.empty()) {
            myQueue.push(tempQueue.top());
            tempQueue.pop();
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return myQueue.empty();
    }
private:
    stack<int> myQueue;
    stack<int> tempQueue;
};

int main() {
    Queue q;
    q.push(1);
    cout << q.empty() << endl;
    return 0;
}
