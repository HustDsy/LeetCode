//
//  main.cpp
//  黄金矿工
//
//  Created by 董深育 on 2020/8/23.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int ans=0;
  
    void dfs(int x,int y,vector<vector<int>>grid,int row,int col,int num){
      
        num=num+grid[x][y];
        ans=max(ans,num);
        int t=grid[x][y];
        grid[x][y]=0;
        
        if(x-1>=0&&y>=0&&x-1<row&&y<col&&grid[x-1][y]){
            dfs(x-1,y,grid,row,col,num);
        }
        if(x+1>=0&&y>=0&&x+1<row&&y<col&&grid[x+1][y]){
            dfs(x+1,y,grid,row,col,num);
        }
        if(x>=0&&y+1>=0&&x<row&&y+1<col&&grid[x][y+1]){
            dfs(x,y+1,grid,row,col,num);
        }
        if(x>=0&&y-1>=0&&x<row&&y-1<col&&grid[x][y-1]){
            dfs(x,y-1,grid,row,col,num);
        }
        grid[x][y]=t;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=static_cast<int>(grid.size());
        if(row==0){
            return 0;
        }
        int col=static_cast<int>(grid[0].size());
       
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0){
                    dfs(i,j,grid,row,col,0);
                }
            }
        }
        int ret=ans;
        return ret;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
