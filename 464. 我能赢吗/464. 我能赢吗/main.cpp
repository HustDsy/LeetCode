//
//  main.cpp
//  464. 我能赢吗
//
//  Created by 董深育 on 2020/9/1.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<numeric>
using namespace std;

class Solution_ {
public:

    vector<int>dp;
    int maxval;
    bool dfs(int status,int sum) {
        if (sum <= 0) {return true;}
        if (dp[status] != 0) {return dp[status] == 1;}
        int ret = 1;
        for (int i = 1;i <=maxval;i++) {
            if ((status & (1<<(i - 1))) == 0) {
                if (dfs(status | (1<<(i - 1)),sum - i)) {
                    ret = -1;
                    break;
                }
            }
        }
        dp[status] = ret;
        return ret == 1;
        
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger + 1)*maxChoosableInteger/2 < desiredTotal) {
            return false;
        }
        maxval  = maxChoosableInteger;
        dp.resize(1<<(maxChoosableInteger+1),0);
        for (int i = 1;i <= maxChoosableInteger;i++) {
            if (dfs(1<<(i - 1),desiredTotal - i)) {return true;}
        }
        return false;
    }
};

class Solution {
public:
    //turn代表轮到了谁
    //1代表A
    //-1代表B
    //我也不知道这样子为啥超时 可能memp变成string 太耗时了
    bool isCan(vector<int>flag,int desiredTotal,unordered_map<string,bool>memo){
        string state="";
        for(int i=0;i<flag.size();i++){
            state=state+to_string(flag[i]);
        }
        if(memo.find(state)!=memo.end()){
            return memo[state];
        }
        for(int i=1;i<=flag.size();i++){
            if(flag[i-1]==0){
                flag[i-1]=1;
                if(desiredTotal-i<=0||!isCan(flag, desiredTotal-i, memo)){
                    memo[state]=true;
                    flag[i-1]=0;
                    return true;
                }
                  flag[i-1]=0;
            }
        }
        return false;
    }
    bool isCan_(int state,int desiredTotal,unordered_map<int,bool>memo,int maxChoosableInteger){
          if(memo.find(state)!=memo.end()){
              return memo[state];
          }
          for(int i=1;i<=maxChoosableInteger;i++){
              if((state&(1<<i))==0){
                  if(desiredTotal-i<=0||!isCan_(state|(1<<i), desiredTotal-i, memo,maxChoosableInteger)){
                      memo[state]=true;
                      return true;
                  }
              }
          }
          return memo[state]=false;
      }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal)
            return true;
        if(((1+maxChoosableInteger)*maxChoosableInteger)/2<desiredTotal)
            return false;
        vector<int>flag(maxChoosableInteger,0);
        unordered_map<string, bool> memo;
        return isCan(flag, desiredTotal,memo);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.canIWin(10, 11);
    return 0;
}
