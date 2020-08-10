//
//  main.cpp
//  232. 用栈实现队列
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int>instack;
    stack<int>outstack;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outstack.empty()){
            while(!instack.empty()){
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int ret=outstack.top();
        outstack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int top=pop();
        outstack.push(top);
        return top;

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return outstack.empty()&&instack.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
