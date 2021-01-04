//
//  main.cpp
//  239. 滑动窗口最大值
//
//  Created by dsy on 2021/1/4.
//

#include <iostream>
#include <vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len=(int)nums.size();
        if(len<2) return nums;
        vector<int>ans;
        deque<int>help;
        for(int i=0;i<len;i++){
            //保证栈顶元素最大
            while(!help.empty()&&nums[help.front()]<nums[i]){
                help.pop_front();
            }
            help.push_front(i);
            if(help.back() <= i-k){
                help.pop_back();
            }
            if(i+1 >= k){
                ans.push_back(nums[help.back()]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
