//
//  main.cpp
//  395. 至少有K个重复字符的最长子串
//
//  Created by dsy on 2021/2/27.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int dfs(string s,int l,int r,int k){
        if(r-l+1<k) return 0;
        int dp[26]={0};
        for(int i=l;i<=r;i++){
            dp[s[i]-'a']++;
        }
        while(r-l+1>=k&&dp[s[l]-'a']<k){
            l++;
        }
        while(r-l+1>=k&&dp[s[r]-'a']<k){
            r--;
        }
        if(r-l+1<k) return 0;
        for(int i=l;i<r;i++){
            if(dp[s[i]-'a']<k){
                return max(dfs(s,l,i-1,k),dfs(s,i+1,r,k));
            }
        }
        return r-l+1;
    }
    int longestSubstring(string s, int k) {
        return dfs(s,0,s.length()-1,k);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.longestSubstring("aaabbb", 3);
    return 0;
}
