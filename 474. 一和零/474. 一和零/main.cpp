//
//  main.cpp
//  474. 一和零
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> getZero(string&str){
        vector<int>res(2,0);
        for(char i:str){
            i-'0'==0?res[0]++:res[1]++;
        }
        return res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        vector<int>ans=getZero(strs[0]);
        for(int k=0;k<=m;k++){
            for(int j=0;j<=n;j++){
                dp[0][k][j]=k>=ans[0]&&j>=ans[1]?1:0;
            }
        }
        for(int i=1;i<l;i++){
            ans=getZero(strs[i]);
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=max(dp[i-1][j][k],j>=ans[0]&&k>=ans[1]?dp[i-1][j-ans[0]][k-ans[1]]+1:0);
                }
            }
        }
        return dp[l-1][m][n];
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> strs{"1","2","123"};
    s.findMaxForm(strs, 5, 6);
    return 0;
}
