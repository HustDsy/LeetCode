//
//  main.cpp
//  448. 找到所有数组中消失的数字
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            //用nums当哈希表
            if(nums[i]==-1){
                continue;
            }
            int cur=nums[i]-1;
            while(nums[cur]!=-1){
                int temp=nums[cur]-1;
                nums[cur]=-1;
                cur=temp;
            }
        }
        vector<int>res;
        for(int i=0;i<len;i++){
            if(nums[i]!=-1){
                res.emplace_back(i+1);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={4,3,2,7,8,2,3,1};
    s.findDisappearedNumbers(nums);
    return 0;
}
