#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int>inStack;
    stack<int>outStack;
    MyQueue() {

    }
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        //保证outStack有数据
        if (outStack.empty()) in2out();
        int temp = outStack.top();
        outStack.pop();
        return temp;
    }

    int peek() {
        if (outStack.empty())in2out();
        return outStack.top();
        
    }

    bool empty() {
        return outStack.empty() && inStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */