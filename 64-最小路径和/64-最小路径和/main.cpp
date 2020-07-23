//
//  main.cpp
//  64-最小路径和
//
//  Created by 董深育 on 2020/7/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //空间复杂度为m*n
    int minPathSum(vector<vector<int>>& grid) {
        int m=(int)grid.size();
        if(m==0){
            return 0;
        }
        int n=(int)grid[0].size();
        //m*n行的数组
        int dp[m][n];
        dp[0][0]=grid[0][0];
        //对于第一列的数组 dp[m][0]=dp[m-1][0]+grid[m][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //对于第一行的数组 dp[0][n]=dp[0][n-1]+grid[0][n]
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        //对于其它行的数组有
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    //将它优化为O(n)
    int minPathSum2(vector<vector<int>>& grid){
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int dp[n];
        dp[0]=0;
        for(int i=0;i<m;i++){
            dp[0]=dp[0]=dp[0]+grid[i][0];
            for(int j = 1; j < grid[i].size(); j++){
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
