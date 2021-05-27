//
//  main.cpp
//  664. 奇怪的打印机
//
//  Created by dsy on 2021/5/26.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[i]){
                    dp[i][j]=dp[i][j-1];
                }else{
                    int cur=INT_MAX;
                    for(int k=i;k<j;k++){
                        cur=min(cur,dp[i][k]+dp[k+1][j]);
                    }
                    dp[i][j]=cur;
                }
            }
        }
        return dp[0][n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
