//
//  main.cpp
//  647. 回文子串
//
//  Created by 董深育 on 2020/8/19.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    //动态规划
    int countSubstrings(string s) {
        int len=(int)s.length();
        if(len==0){
            return 0;
        }
        int ret=0;
        vector<vector<int>>dp(len,vector<int>(len ,0));
        for(int i=len;i>=0;i--){
            for(int j=i;j<len;j++){
                if(i==j){
                    dp[i][j]=1;
                    ret+=1;
                }else if(j-i==1){
                    dp[i][j]=s[i]==s[j];
                    if(dp[i][j]){
                        ret+=1;
                    }
                }else{
                    dp[i][j]=dp[i+1][j-1]&&s[i]==s[j];
                    if(dp[i][j]){
                        ret+=1;
                    }
                }
                
            }
                
        }
        return ret;
    }
    //马拉车算法
    int countSubstrings_(string s) {
        int len=(int)s.length();
        if(len==0){
            return 0;
        }
        string ss="&#";
        for(int i=0;i<len;i++){
            ss+=s[i];
            ss+="#";
        }
        s=ss;
        len=(int)s.length();
        int kk=0;
        //左边端点
        vector<int>dp(len,0);
        int r=0;//最右边的值
        int mid=0;//中心点
        for(int l=1;l<len;l++){
            dp[l]=l<r?min(r-l,dp[2*mid-l]):1;
            while(s[l+dp[l]]==s[l-dp[l]]){
                dp[l]++;
            }
            if(r<l+dp[l]){
                r=l+dp[l];
                mid=l;
            }
            kk+=dp[l]/2;
        }
        return kk;
    }
    
      
};



int main(int argc, const char * argv[]) {
    Solution s;

    cout<<ceil(1/2);
    return 0;
}
