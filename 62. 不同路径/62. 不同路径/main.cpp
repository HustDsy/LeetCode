//
//  main.cpp
//  62. 不同路径
//
//  Created by 董深育 on 2020/10/20.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        //第一行的全为1
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        //第一列的全为1
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        //开始计算其它的点
        //dp[i][j]=dp[i-1][j]+dp[i][j-1]
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.uniquePaths(3, 2);
    return 0;
}
