#include<bits/stdc++.h>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int>que1;
    queue<int>que2;
    MyStack() {

    }
    
    void push(int x) {
        que2.push(x);
        //while(!que1.empty())
        for (int i = que1.size(); i > 0; i--) {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1, que2);
    }
    //移除并返回栈顶元素
    int pop() {
        int temp = que1.front();
        que1.pop();
        return temp;
    }
    //返回栈顶元素
    int top() {
        //因为新元素通过que2放到队首了，所以直接放到front就行
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */