//
//  main.cpp
//  剑指 Offer 59 - II. 队列的最大值
//
//  Created by dsy on 2021/2/3.
//

#include <iostream>
#include<queue>
using namespace std;

class MaxQueue {
public:
    queue<int>nums;
    deque<int>maxn;
    MaxQueue() {

    }
    
    int max_value() {
        if(maxn.empty()){
            return -1;
        }
        return maxn.back();
    }
    
    void push_back(int value) {
        nums.push(value);
        while(!maxn.empty()&&value>maxn.front()){
            maxn.pop_back();
        }
        maxn.push_front(value);
    }
    
    int pop_front() {
        if(nums.empty()) return -1;
        int front=nums.front();
        if(front==maxn.front()){
            maxn.pop_front();
        }
        nums.pop();
        return front;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
