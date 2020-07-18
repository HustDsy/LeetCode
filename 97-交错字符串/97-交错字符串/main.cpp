//
//  main.cpp
//  97-交错字符串
//
//  Created by 董深育 on 2020/7/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    //记忆化递归
    /*
    bool dfs(string s1,string s2,string s3,int i,int j,int k,bool**arry){
        if(arry[i][j]!=NULL){
            return arry[i][j];
        }
        if(i==s1.length()&&j==s2.length()&&k==s3.length()){
            arry[i][j]=true;
            return true;
        }
        if(k>s3.length()){
            arry[i][j]=false;
            return false;
        }
        if(i<s1.length()){
            if(s1[i]==s3[k]&&dfs(s1,s2,s3,i+1,j,k+1,arry)){
                return true;
            }
        }
        if(j<s2.length()){
            if(s2[j]==s3[k]&&dfs(s1,s2,s3,i,j+1,k+1,arry)){
                return true;
            }
        }
        return false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        bool**arry=new bool*[s1.length()+1];
        for(int i=0;i<s1.length()+1;i++){
            arry[i]=new bool[s2.length()+1];
        }
        for(int i=0;i<s1.length()+1;i++){
            for(int j=0;j<s2.length()+1;j++){
                arry[i][j]=nullptr;
            }
        }
        return dfs(s1, s2, s3, 0, 0, 0,arry);
        
    }
     */
    //动态规划
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (s3.length() != m + n) return false;
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for (int i = 1; i <= m ; i++)
        {
            dp[i][0] = dp[i-1][0]&&s1[i-1]==s3[i-1]; 
        }
        for (int j = 1; j <= n; j++){
             dp[0][j] = dp[0][j-1]&&s2[j-1]==s3[j-1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] &&s3[i+j-1] == s1[i-1])
                    || (dp[i][j - 1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string s1="a";
    string s2="";
    string s3="a";
    bool a=s.isInterleave(s1, s2, s3);
    cout<<a;
    return 0;
}
