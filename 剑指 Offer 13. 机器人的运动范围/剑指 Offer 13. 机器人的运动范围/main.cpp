//
//  main.cpp
//  剑指 Offer 13. 机器人的运动范围
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int  res=0;
    void dfs(int i,int j,int k,int m,int n,vector<vector<int>>&flag){
        if(i<0||j<0||i>=m||j>=n||flag[i][j]) return;
        int sum=0;//数位之和
        int x=i;
        int y=j;
        while(x||y){
            sum+=x%10;
            sum+=y%10;
            x=x/10;
            y=y/10;
        }
        if(sum<=k)
        {
            res++;
        }
        flag[i][j]=1;
        if(sum>k) return;
        //上
        //dfs(i-1,j,k,m,n,flag);
        //右
        dfs(i,j+1,k,m,n,flag);
        //下
        dfs(i+1,j,k,m,n,flag);
        //左
        //dfs(i,j-1,k,m,n,flag);
        
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int>>flag(m,vector<int>(n,0));
        dfs(0,0,k,m,n,flag);
        return  res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.movingCount(16, 8, 4);
    return 0;
}
