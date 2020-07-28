//
//  main.cpp
//  542-01 矩阵
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct points{
     int x;
     int y;
     points(int x,int y){
         this->x=x;
         this->y=y;
     }
 };

class Solution {
public:
    //动态规划
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row= (int)matrix.size();
        if(row==0){
            return {};
        }
        int col=(int)matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        //dp[i][j]代表这个点到0的最近的距离
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dp[i][j]=matrix[i][j]==0?0:10001;
            }
        }
        //从左上到右下,dp[i][j]只依赖于dp[i-1][j]或者dp[i][j-1]
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i-1>=0){
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                }
                if(j-1>=0){
                     dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
                }
            }
        }
        //从右下到左上，dp[i][j]依赖于dp[i][j+1]或者dp[i+1][j]
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=20;j--){
                if(i+1<row){
                    dp[i][j]=min(dp[i+1][j]+1,dp[i][j]);
                }
                if(j+1<col){
                    dp[i][j]=min(dp[i][j+1]+1,dp[i][j]);
                }
            }
        }
        return dp;
    }
    //广度优先搜索
    vector<vector<int>> updateMatrix_BFS(vector<vector<int>>& matrix) {
        int row= (int)matrix.size();
        if(row==0){
            return {};
        }
        int col=(int)matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        queue<points>myPoint;
        //将等于0的位置 dp变为0，并且放入我们的队列中
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                    matrix[i][j]=-1;
                    points point(i,j);
                    myPoint.push(point);
                }
            
              
            
            }
        }
        //逐层渲染，渲染的将值变为+1
        int size=1;
        while(!myPoint.empty()){
            int sz=(int)myPoint.size();
            while(sz>0){
                points temp=myPoint.front();
                myPoint.pop();
                int x=temp.x;
                int y=temp.y;
                //找到它上面的点,并且没访问过
                if(x-1>=0&&matrix[x-1][y]!=-1){
                    points upPoint(x-1,y);
                    //标志已经访问过了
                    matrix[x-1][y]=-1;
                    //渲染当前层数
                    dp[x-1][y]=size;
                    myPoint.push(upPoint);
                }
                //它下面的点
                if(x+1<row&&matrix[x+1][y]!=-1){
                    points downPoint(x+1,y);
                    //标志已经访问过了
                    matrix[x+1][y]=-1;
                    //渲染当前层数
                    dp[x+1][y]=size;
                    myPoint.push(downPoint);
                }
                //它左边的点
                if(y-1>=0&&matrix[x][y-1]!=-1){
                    points leftPoint(x,y-1);
                    //标志已经访问过了
                    matrix[x][y-1]=-1;
                    //渲染当前层数
                    dp[x][y-1]=size;
                    myPoint.push(leftPoint);
                }
                //它右边的点
                if(y+1<col&&matrix[x][y+1]!=-1){
                    points rightPoint(x,y+1);
                    //标志已经访问过了
                    matrix[x][y+1]=-1;
                    //渲染当前层数
                    dp[x][y+1]=size;
                    myPoint.push(rightPoint);
                }
                sz--;
            }
            //层数+1
            size++;
        }
        return dp;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>>ret={{0,0,0},{0,1,0},{1,1,1}};
    s.updateMatrix_BFS(ret);
    return 0;
}
