//
//  main.cpp
//  225. 用队列实现栈
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int>inqueue;
    queue<int>outqueue;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        inqueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size=(int)inqueue.size();
        int kk;
        while(size>1){
            outqueue.push(inqueue.front());
            inqueue.pop();
            size--;
        }
        kk=inqueue.front();
        inqueue.pop();
        //将outqueue数据复制过去
        while(!outqueue.empty()){
            inqueue.push(outqueue.front());
            outqueue.pop();
        }
        return kk;
    }
    
    /** Get the top element. */
    int top() {
        int tt=pop();
        inqueue.push(tt);
        return tt;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return inqueue.empty();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
