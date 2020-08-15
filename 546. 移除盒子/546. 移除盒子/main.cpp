//
//  main.cpp
//  546. 移除盒子
//
//  Created by 董深育 on 2020/8/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dp[100][100][100]={0};
    int removeBoxes(vector<int>& boxes) {
        int l=0;
        int r=(int)boxes.size()-1;
        int k=0;
        return calculatePoints(boxes, l, r, k);

    }
    //dp[l][r][k]代表了l,r区间分割的最大的值，其中k代表后面跟着k个 和boxes[r]一样的值
    //比如 [1,2,3,3,3,3]那么这个区间为dp[0][2][3]
    //那么自然而然 dp[0][2][3]=dp[0][1][0]+4*4
    //然而对于[1,3,2,3,3,3,3] dp[0][2][3]=dp[2][2][0]+dp[0][1][3]
    int calculatePoints(vector<int>&boxes,int l,int r,int k){
        if(l>r){
            return 0;
        }
        //记忆化递归
        if (dp[l][r][k]!=0)
            return dp[l][r][k];
        //剪枝
        while (l<r && boxes[r]==boxes[r-1])
        {
            r--;
            k++;
        }
        dp[l][r][k]=calculatePoints(boxes, l, r-1, 0)+(k+1)*(k+1);
        for(int i=l;i<r;i++){
            if(boxes[i]==boxes[r]){
                dp[l][r][k]=max(dp[l][r][k],calculatePoints(boxes, l, i, k+1)+calculatePoints(boxes, i+1, r-1, 0));
            }
        }
        return dp[l][r][k];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
