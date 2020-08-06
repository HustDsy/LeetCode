//
//  main.cpp
//  5-最长回文子串
//
//  Created by 董深育 on 2020/6/11.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return s;
        }
        int num=(int)s.size();//得到string的长度
        int arry[num][num];
        string maxs;//记录最长的回文串
        //最外层循环代表子串长度
        for(int i=0;i<num;i++){
            for(int j=0;j<num ;j++){
                arry[i][j]=1;
            }
        }
        for(int l=0;l<num;l++){
            for(int i=0;i<num-l;i++){
                //长度为一那一定就是回文数字
                int j=i+l;
                if(l==0){
                    arry[i][j]=1;
                }
                //长度为2的话 ，那么数两个数字一样则为回文数
                else if(l==1){
                    if(s[i]==s[j]){
                        arry[i][j]=1;
                    }else{
                        arry[i][j]=0;
                    }
                }else{
                    arry[i][j]=(arry[i+1][j-1]==1)&&(s[i]==s[j]);
                }
                if(arry[i][j]==1&&(l+1)>maxs.size()){
                    maxs=s.substr(i,(j-i+1));
                }
                
            }
        }
        return maxs;
    }
    
    string longestPalindrome1(string s) {
         int len = s.length();
        if(len==0){
            return "";
        }
         vector<vector<int>>dp(len,vector<int>(len,0));
         int maxlen=1;
         string ret;
         for(int i=len-1;i>=0;i--){
             dp[i][i]=1;
             for(int j=i+1;j<len;j++){
               if(j-i==1){
                   dp[i][j]=s[i]==s[j];
               }else{
               dp[i][j]=s[i]==s[j]&&dp[i+1][j-1];
               }
               if(dp[i][j]==1&&j-i+1>maxlen){
                   maxlen=j-i+1;
                   ret=s.substr(i,(j-i+1));
       
               }
             }
         }
        if(maxlen==1){
            string temp;
            temp+=s[0];
            return temp;
        }
          return ret;
       }
};

int main(int argc, const char * argv[]) {
    string s="babad";
    Solution ss;
    cout<<ss.longestPalindrome1(s)<<endl;
    return 0;
}
