//
//  main.cpp
//  200. 岛屿数量
//
//  Created by 董深育 on 2020/8/21.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

class Solution {
public:
    void infect(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        infect(grid, i-1, j);
        infect(grid, i+1, j);
        infect(grid, i, j-1);
        infect(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    infect(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
int main(int argc, const char * argv[]) {
    
    vector<vector<char>>kk={
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'}};
    Solution s;
    s.numIslands(kk);
    return 0;
}
