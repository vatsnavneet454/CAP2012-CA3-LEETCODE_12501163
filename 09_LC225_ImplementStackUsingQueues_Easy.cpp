// LeetCode 225 - Implement Stack using Queues (Easy)
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() = default;

    void push(int x) {
        q.push(x);
        int count = static_cast<int>(q.size());

        // Move older elements behind the newly inserted element.
        for (int i = 0; i < count - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int value = q.front();
        q.pop();
        return value;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
