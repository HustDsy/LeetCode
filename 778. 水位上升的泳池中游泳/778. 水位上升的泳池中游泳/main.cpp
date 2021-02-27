//
//  main.cpp
//  778. 水位上升的泳池中游泳
//
//  Created by dsy on 2021/1/30.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//广度优先搜索
//class Solution {
//private:
//    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//public:
//    int swimInWater(vector<vector<int>>& heights) {
//        int m = heights.size();
//        int n = heights[0].size();
//        int left = heights[0][0], right = 999999, ans = 0;
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            queue<pair<int, int>> q;
//            q.emplace(0, 0);
//            vector<int> seen(m * n);
//            seen[0] = 1;
//            while (!q.empty()) {
//                auto [x, y] = q.front();
//                q.pop();
//                for (int i = 0; i < 4; ++i) {
//                    int nx = x + dirs[i][0];
//                    int ny = y + dirs[i][1];
//                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && heights[nx][ny] <= mid) {
//                        q.emplace(nx, ny);
//                        seen[nx * n + ny] = 1;
//                    }
//                }
//            }
//            if (seen[m * n - 1]) {
//                ans = mid;
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        return ans;
//    }
//};

/*
 并查集
 */
class Solution {
public:
    //记录每个点的父亲
    vector<int>parent;
    //树压缩
    vector<int>rank;
    //每个父亲节点的大水位
    vector<int>size;
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    
    void uion(int x,int y,int len){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            if(rank[px]<rank[py]){
                swap(px,py);
            }
            parent[py]=px;
            size[px]=max(len,size[px]);
            if(rank[px]==rank[py]) rank[px]++;
        }
    }
    
    int isconnected(int x,int y){
        return find(x)==find(y);
    }

    int swimInWater(vector<vector<int>>& grid) {
        //构造边
        int m=grid.size();
        int n=grid[0].size();
        vector<tuple<int,int,int>>edges;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0){
                    edges.emplace_back((i-1)*n+j,i*n+j,max(grid[i][j],grid[i-1][j]));
                }
                if(j>0){
                    edges.emplace_back(i*n+j,i*n+j-1,max(grid[i][j],grid[i][j-1]));
                }
            }
        }
        sort(edges.begin(),edges.end(),[](const auto&a,const auto&b)->bool{
            return get<2>(a)<get<2>(b);
        });
        //初始化parent
        parent.reserve(m*n);
        size.reserve(m*n);
        rank.reserve(m*n);
        for(int i=0;i<m*n;i++){
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(0);
        }
        for(auto&e:edges){
            uion(get<0>(e),get<1>(e),get<2>(e));
            if(isconnected(0,m*n-1)){
                return size[find(0)];
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
