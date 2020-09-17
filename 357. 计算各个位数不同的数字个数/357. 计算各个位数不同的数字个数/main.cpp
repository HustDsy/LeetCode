//
//  main.cpp
//  357. 计算各个位数不同的数字个数
//
//  Created by 董深育 on 2020/9/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string>nums;
    vector<int>dp;
    void dfs(int n,string s,vector<int>&flag){
        if(s.length()>n){
            return;
        }
        //这里相当于push了0
        if(s.length()<=n&&s!=""){
            nums.push_back(s);
        }
        for(int i=0;i<10;i++){
            if(s.length()==0&&i==0)continue;
            //如果这个数字用过了的话，那么就继续
            if(flag[i])continue;
            flag[i]=1;
            dfs(n,s+to_string(i),flag);
            flag[i]=0;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        dp=vector<int>(n,0);
        vector<int>flag(10,0);
        if(n>=10) dfs(10,"",flag);
        if(n<10) dfs(n,"",flag);
        //+1包括了0
        return (int)nums.size()+1;
    }
    void print(){
           vector<string>::iterator it=nums.begin();
           for(;it<nums.end();it++){
               cout<<*it<<endl;
           }
       }
    //动态规划的方法
    int countNumbersWithUniqueDigits_dp(int n){
         if(n==0)return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        if(n>=10) n=10;
        vector<int>dp(n+1,0);
        //统一不计算0，后面的数字
        dp[0]=0;
        dp[1]=9;
        dp[2]=90;
        //求n需要循环n次
        for(int k=3;k<=n;k++){
            //求前面的那个相减的数
            for(int i=0;i<k;i++){
                if(i==0){
                    dp[k]+=9;
                }else{
                    dp[k]=dp[k]+(dp[i]-dp[i-1])*(10-i);
                }
            }
        }
        return dp[n]+1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.countNumbersWithUniqueDigits(4)<<" "<<s.countNumbersWithUniqueDigits_dp(4)<<endl;
    //s.print();
    return 0;
}
