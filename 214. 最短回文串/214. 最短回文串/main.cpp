//
//  main.cpp
//  214. 最短回文串
//
//  Created by 董深育 on 2020/8/29.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    //马拉车算法
    string shortestPalindrome(string s) {
        if(s.length()==0||s.length()==1){
            return s;
        }
        string kk="&#";
        
        for(int i=0;i<s.length();i++){
            kk+=s[i];
            kk+="#";
        }
        int len=static_cast<int>(kk.length());
        vector<int>pmax(len,1);
        //最长回文字符串的中心
        int maxi=0;
        //最右端的值
        int r=0;
        //左端点 是否为s[1]
        int target=-1;
        for(int i=1;i<len;i++){
            pmax[i]=i>=r?1:min(r-i,pmax[2*maxi-i]);
            //pmax是回文串长度
            while(kk[i+pmax[i]]==kk[i-pmax[i]]){
                pmax[i]++;
            }
            //更行maxi和r
            if(r<pmax[i]+i-1){
                r=pmax[i]+i-1;
                maxi=i;
            }
            if(i-pmax[i]+1==1){
                target=i;
            }
        }
        int left=target-pmax[target]+1;
        int right=target+pmax[target]-1;
        string prefix;
        for(int i=len-1;i>=right+1;i--){
            if(kk[i]!='#'&&kk[i]!='&'){
                prefix+=kk[i];
            }
        }
        string suffix;
        for(int i=left;i<=len-1;i++){
            if(kk[i]!='#'&&kk[i]!='&'){
                suffix+=kk[i];
            }
        }
        string ret=prefix+suffix;
        return ret;
    }
    //kmp算法 求next
    //这里不赘述了
    string shortestPalindrome_kmp(string s) {
        int len=static_cast<int>(s.length());
        if(len==0||len==1){
            return s;
        }
        int next[len];
        next[0]=0;
        int i=1;
        int now=0;
        while(i<len){
            if(s[i]==s[now]){
                now=now+1;
                next[i]=now;
                i++;
            }else if(now!=0){
                now=next[now-1];
            }else{
                next[i]=0;
                i++;
            }
        }
        return "";
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.shortestPalindrome("abcd");
    return 0;
}
