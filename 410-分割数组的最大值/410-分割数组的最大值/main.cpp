//
//  main.cpp
//  410-分割数组的最大值
//
//  Created by 董深育 on 2020/7/25.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include"limits.h"
using namespace std;


class Solution {
public:
    //动态规划
    int splitArray(vector<int>& nums, int m) {
        //用来存储num[i]到nums[j]之间的距离
        //numss[i][j]=disance[j]-distance[i]+nums[i];
        int n=(int)nums.size();

        long distance[n+1];
        distance[0]=0;
        for(int i=0;i<n;i++){
            distance[i+1]=distance[i]+nums[i];
        }
        //定义数组dp[i][j]为将i个数分成j段的最大值最小的数组
        //为了防止越界 i=n+1;j=m+1;
        //其中dp[0][0]=0;
        vector<vector<long>>dp(n+1,vector<long>(m+1,LONG_MAX));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            //将i个数分成j段
            for(int j=1;j<=min(m,i);j++){
                //dp[i][j]=min(k=0:i-1){max(dp[k][j-1],diatance(k+1,i))}
                for(int k=0;k<=i-1;k++){
                    dp[i][j]=min(dp[i][j],max(dp[k][j-1],distance[i]-distance[k]));
                    
                }
            }
        }
        return (int)dp[n][m];

    }
    //二分查找，很像上次那个寻找第k小的数字了
    int splitArray2(vector<int>& nums, int m) {
        long l=*max_element(nums.begin(),nums.end());
        long r=0;
        for(int temp:nums){
            r+=temp;
        }
        while(l<r){
            long mid=(l+r)/2;
            //得到不大于mid的分组数
            long temp=0;
            int cnt=1;
            for(int i:nums){
                temp+=i;
                if(temp>mid){
                    temp=i;
                    cnt++;
                }
            }
            //如果分组数过多的话 那么mid太小了
            if(cnt>m){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return (int)l;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int>nums={7,2,5,10,8};
    int ret=s.splitArray(nums, 2);
    return 0;
}
