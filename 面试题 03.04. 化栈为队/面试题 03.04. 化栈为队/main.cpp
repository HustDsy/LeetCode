//
//  main.cpp
//  面试题 03.04. 化栈为队
//
//  Created by dsy on 2021/1/7.
//

#include <iostream>
#include<stack>
using namespace std;


class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=peek();
        if(x==-1) return -1;
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(empty()){
            return -1;
        }
        if(!s2.empty()){
            return s2.top();
        }
        //将s1的数据迁移到s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
