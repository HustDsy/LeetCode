//
//  main.cpp
//  剑指 Offer 39. 数组中出现次数超过一半的数字
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s=nums.size();
        int cur=0;
        int vot=0;
        for(int i=0;i<s;i++){
            if(vot==0){
                vot++;
                cur=nums[i];
            }else{
                if(nums[i]==cur){
                    vot++;
                }else{
                    vot--;
                }
            }
        }
        return cur;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={3,3,4};
    s.majorityElement(nums);
    return 0;
}
