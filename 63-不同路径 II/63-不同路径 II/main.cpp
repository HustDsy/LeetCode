//
//  main.cpp
//  63-不同路径 II
//
//  Created by 董深育 on 2020/7/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=(int)obstacleGrid.size();
        int n=(int)obstacleGrid[0].size();
        int dp[m][n];
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            obstacleGrid[i][0]==1?dp[i][0]=0:dp[i][0]=dp[i-1][0];
        }
        for(int j=1;j<n;j++){
           obstacleGrid[0][j]==1?dp[0][j]=0:dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
