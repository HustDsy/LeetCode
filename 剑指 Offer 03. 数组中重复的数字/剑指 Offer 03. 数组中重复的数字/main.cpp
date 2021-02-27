//
//  main.cpp
//  剑指 Offer 03. 数组中重复的数字
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]!=i){
                if(nums[nums[i]]==nums[i]){
                    return nums[i];
                }
                int temp=nums[i];
                i=nums[temp];
                nums[temp]=temp;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
