//
//  main.cpp
//  34. 在排序数组中查找元素的第一个和最后一个位置
//
//  Created by dsy on 2020/12/1.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>dp(2,-1);
        int len=static_cast<int>(nums.size());
        int l=0;
        int r=len-1;
        while(l<r){
            int mid=l+(r-l)/2;
            int cur=nums[mid];
            if(cur==target){
               //以l和r为边界 中心扩展
                dp[0]=mid;
                dp[1]=mid;
                int ll=mid-1;
                int rr=mid+1;
                while(ll>=l&&nums[ll]==target){
                    ll--;
                }
                dp[0]=ll+1;
                while(rr<=r&&nums[rr]==target){
                    rr++;
                }
                dp[0]=ll+1;
                dp[1]=rr-1;
            }else if(cur>target){
                r=cur-1;
            }else{
                l=cur+1;
            }
        }
        return dp;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
