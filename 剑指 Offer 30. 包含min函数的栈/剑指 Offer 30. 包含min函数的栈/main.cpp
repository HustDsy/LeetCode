//
//  main.cpp
//  剑指 Offer 30. 包含min函数的栈
//
//  Created by dsy on 2021/1/30.
//

#include <iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s1;
    stack<int>s2;
    MinStack() {

    }
    void push(int x) {
        s1.push(x);
        if(s2.empty()||s2.top()>=x){
             s2.push(x);
        }
    }
    void pop() {
        if(s1.empty()) return;
        if(!s2.empty()&&s1.top()==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
