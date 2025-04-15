#include <queue>
using namespace std;

class MyStack {
    queue<int> que1;
    queue<int> que2;

public:
    MyStack() {}

    void push(int x) {
        que2.push(x);
        while (!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1, que2);  // Now que1 has the new element at front
    }

    int pop() {
        if (que1.empty()) return -1;  // Optional: handle underflow
        int val = que1.front();
        que1.pop();
        return val;
    }

    int top() {
        if (que1.empty()) return -1;  // Optional: handle empty case
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};
