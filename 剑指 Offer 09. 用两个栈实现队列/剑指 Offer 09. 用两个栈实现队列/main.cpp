//
//  main.cpp
//  剑指 Offer 09. 用两个栈实现队列
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<stack>
using namespace std;

class CQueue {
public:
    stack<int>p;
    stack<int>q;
    CQueue() {

    }
    void appendTail(int value) {
        p.push(value);
    }
    
    int deleteHead() {
        if(p.empty()&&q.empty()){
            return -1;
        }
        if(!q.empty()){
            int x=q.top();
            q.pop();
            return x;
        }
        while(!p.empty()){
            q.push(p.top());
            p.pop();
        }
        int ans=q.top();
        q.pop();
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
