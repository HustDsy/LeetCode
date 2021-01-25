//
//  main.cpp
//  1319. 连通网络的操作次数
//
//  Created by dsy on 2021/1/23.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int types;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    //-1 表示有环
    int  merge(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            if(rank[px]<rank[py]){
                swap(px, py);
            }
            parent[py]=px;
            if(rank[px]==rank[py]) rank[px]++;
            types--;
            return 0;
        }
        return -1;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int kk=0;//表示多少会造成环路的线
        parent.reserve(n);
        rank.reserve(n);
        types=n;
        for(int i=0;i<n;i++){
            parent.emplace_back(i);
            rank.emplace_back(0);
        }
        for(auto&c:connections){
            int ret=merge(c[0],c[1]);
            if(ret==-1){
                kk++;
            }
        }
        return kk>=(types-1)?types-1:-1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > connections={{0,1},{0,2},{1,2}};
    s.makeConnected(4, connections);
    return 0;
}
