//
//  main.cpp
//  205. 同构字符串
//
//  Created by dsy on 2020/12/27.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
 bool isIsomorphic(string s, string t) {
        vector<int>dp(128,-1);
        vector<int>dp_(128,0);
        int len1=s.length();
        int len2=t.length();
        if(len1!=len2) return false;
        for(int i=0;i<len1;i++){
            if(dp[s[i]]==-1&&dp_[t[i]]==0){
                dp[s[i]]=t[i];
                dp_[t[i]]++;
            }else{
                if(t[i]!=(dp[s[i]])){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.isIsomorphic("ab","aa");
    return 0;
}
