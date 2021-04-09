//
//  main.cpp
//  695. 岛屿的最大面积
//
//  Created by dsy on 2021/3/26.
//

#include <iostream>
#include<vector>

class Solution {
public:
    int res;
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i>=0&&j>=0&&i<m&&j<n&&grid[i][j]){
            grid[i][j]=0;
            res++;
            dfs(grid,i+1,j,m,n);
           dfs(grid,i,j+1,m,n);
           dfs(grid,i,j-1,m,n);
           dfs(grid,i-1,j,m,n);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res=0;
                    dfs(grid,i,j,m,n);
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
