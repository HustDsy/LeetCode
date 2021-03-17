//
//  main.cpp
//  剑指 Offer 61. 扑克牌中的顺子
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cur=0;
        for(int i=0;i<=4;i++){
            if(nums[i]==0){
                cur++;
                continue;
            }
            if(i>0&&nums[i]==nums[i-1]){
                return false;
            }
        }
        return nums[4]-nums[cur]<5;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
