//
//  main.cpp
//  803. 打砖块
//
//  Created by dsy on 2021/1/16.
//

#include <iostream>
#include<vector>
using namespace std;

class uion{
public:
    vector<int>parent;
    vector<int>size;
    vector<int>rank;
    uion(int n){
        parent=vector<int>(n);
        size=vector<int>(n,1);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    int getsize(int x){
        return size[find(x)];
    }
    void merge(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty){
            if(rank[rootx]<rank[rooty]){
                swap(rootx, rooty);
            }
            //rank小的放到rank到的
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
        }
    }
};

class Solution {
public:
    //下 上 左 右
    vector<vector<int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        int l = hits.size();
        vector<int>res(l);
        vector<vector<int>>copy(grid);
        for(auto&v:hits){
            copy[v[0]][v[1]]=0;
        }
        uion u(m*n+1);
        for(int j=0;j<n;j++){
            if(copy[0][j]==0) continue;
            u.merge(m*n,j);
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(copy[i][j]==0)continue;
                if(copy[i-1][j]==1){
                    u.merge(i*n+j, (i-1)*n+j);
                }
                if(j>0&&copy[i][j-1]==1){
                    u.merge(i*n+j, i*n+j-1);
                }
            }
        }
        for(int k=l-1;k>=0;k--){
            int i=hits[k][0];
            int j=hits[k][1];
            if(grid[i][j]==0) continue;
            int origin=u.getsize(m*n);
            //被补回的砖块位于房顶
            if(i==0){
                u.merge(m*n,j);
            }
            for(auto&d:dir){
                int r=i+d[0];
                int c=j+d[1];
                if(r<0||r>=m||c<0||c>=n||copy[r][c]==0) continue;
                u.merge(i*n+j,r*n+c);
            }
            int cur=u.getsize(m*n);
            res[k]=max(0,cur-origin-1);
            copy[i][j]=1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
