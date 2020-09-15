//
//  main.cpp
//  980. 不同路径 III
//
//  Created by 董深育 on 2020/9/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int ret;

    inline bool isvaild(int i,int j,int row,int col){
        return i>=0&&j>=0&&i<row&&j<col;
    }
     //i,j是要经过的点
    void dfs(vector<vector<int>>& grid,int i,int j,int k,pair<int,int>end,int path,vector<vector<int>>flag,int row,int col){
        //到达终点
        if((i==end.first)&&(j==end.second)){
            if(k==path+1){
                ret++;
                return;
            }else{
                return;
            }
            return;
        }
        //上
        if(isvaild(i-1, j, row, col)&&!flag[i-1][j]&&grid[i-1][j]!=-1){
            flag[i-1][j]=1;
            dfs(grid,i-1,j,k+1,end,path,flag,row,col);
            flag[i-1][j]=0;
        }
        //下
        if(isvaild(i+1, j, row, col)&&!flag[i+1][j]&&grid[i+1][j]!=-1){
            flag[i+1][j]=1;
            dfs(grid,i+1,j,k+1,end,path,flag,row,col);
            flag[i+1][j]=0;
        }
        //左
        if(isvaild(i, j-1, row, col)&&!flag[i][j-1]&&grid[i][j-1]!=-1){
            flag[i][j-1]=1;
            dfs(grid,i,j-1,k+1,end,path,flag,row,col);
            flag[i][j-1]=0;
        }
        //右
        if(isvaild(i, j+1, row, col)&&!flag[i][j+1]&&grid[i][j+1]!=-1){
            flag[i][j+1]=1;
            dfs(grid,i,j+1,k+1,end,path,flag,row,col);
            flag[i][j+1]=0;
        }
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        //统计障碍的数目
        int barrNum=0;
        int row=static_cast<int>(grid.size());
        int col=static_cast<int>(grid[0].size());
        //0表示没访问，1表示访问了
        vector<vector<int>>flag(row,vector<int>(col,0));
        pair<int,int>start;//记录起始点
        pair<int,int>end;//记录终点
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==-1){
                    barrNum++;
                }else if(grid[i][j]==1){
                    start=make_pair(i, j);
                }else if(grid[i][j]==2){
                    end=make_pair(i, j);
                }
            }
        }
        //统计可以走的空格的数目
        int path=row*col-barrNum-2;
        flag[start.first][start.second]=1;
        dfs(grid, start.first, start.second,0,end, path, flag, row,col);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int> > grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    Solution s;
    cout<<s.uniquePathsIII(grid);
    return 0;
}
