//
//  main.cpp
//  525. 连续数组
//
//  Created by dsy on 2021/6/3.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>pos;
        int len = nums.size();
        int ans=0;
        int sum=0;
        int t;
        for(int i=0;i<len;i++){
            //hash表里面存的是到现在之前存的数
            t=nums[i]==0?-1:1;
            sum+=t;
            if(pos.count(sum)){
                ans=max(ans,i-pos[sum]+2);
            }else{
                pos[sum]=i+1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={0,1,0,1};
    s.findMaxLength(nums);
    return 0;
}
