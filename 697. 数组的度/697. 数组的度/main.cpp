//
//  main.cpp
//  697. 数组的度
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //记录每个数字出现的次数
        vector<int>dp(50000,0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            dp[nums[i]]++;
            ans=max(ans,dp[nums[i]]);
        }
        //得到最大数字的起始点与终点
        unordered_map<int, pair<int, int>>m;
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(dp[nums[i]]==ans){
                if(m.count(nums[i])){
                    m[nums[i]].second=i;
                }else{
                    m[nums[i]]=make_pair(i,0);
                }
            }
        }
        //遍历map
        for(auto&it:m){
            res=min(res,it.second.second-it.second.first+1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
