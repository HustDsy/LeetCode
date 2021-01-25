//
//  main.cpp
//  959. 由斜杠划分区域
//
//  Created by dsy on 2021/1/25.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>&g,int i,int j){
        if(i >= 0 && i < g.size() && j >= 0 && j < g[0].size() && g[i][j] == 0){
            g[i][j] = 1;
            dfs(g,i+1,j);
            dfs(g,i-1,j);
            dfs(g,i,j+1);
            dfs(g,i,j-1);
        }
    }
    //转换成岛屿数量
    int regionsBySlashes(vector<string>& grid) {
        int res=0;
        int N=grid.size();
        vector<vector<int>>g(N*3,vector<int>(N*3,0));
        //初始化岛屿
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='/'){
                    g[i*3+2][j*3] = g[i*3+1][j*3+1] = g[i*3][j*3+2] = 1;
                }else if(grid[i][j]=='\\'){
                    g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2] = 1;
                }
            }
        }
        for(int i = 0;i < g.size();i++){
            for(int j = 0;j < g[0].size();j++){
                if(g[i][j] == 0){
                    dfs(g,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
