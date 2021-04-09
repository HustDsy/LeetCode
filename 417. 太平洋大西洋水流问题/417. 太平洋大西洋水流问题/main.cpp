//
//  main.cpp
//  417. 太平洋大西洋水流问题
//
//  Created by dsy on 2021/3/26.
//

#include <iostream>
#include<vector>


class Solution {
public:
    int m;
    int n;
    int dirs[5] = {1, 0, -1, 0, 1};
    void dfs(vector<vector<int>>& target,int i,int j,vector<vector<int>>& matrix){
        if(target[i][j]==0){
            target[i][j]=1;
            for(int k=0;k<4;k++){
                int x=i+dirs[k];
                int y=j+dirs[k+1];
                if(x>=0&&x<m&&y>=0&&y<n&&!target[x][y]&&matrix[i][j]<=matrix[x][y]){
                    dfs(target,x,y,matrix);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
         m=matrix.size();
         if(m==0) return {};
         n=matrix[0].size();
        vector<vector<int>>A(m,vector<int>(n,0));
        vector<vector<int>>B(m,vector<int>(n,0));
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            dfs(A,i,0,matrix);
            dfs(B,i,n-1,matrix);
        }
        for(int i=0;i<n;i++){
            dfs(A,0,i,matrix);
            dfs(B,m-1,i,matrix);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]&&B[i][j]){
                    ans.push_back({i,j});
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
