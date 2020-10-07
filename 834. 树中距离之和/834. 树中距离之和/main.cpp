//
//  main.cpp
//  834. 树中距离之和
//
//  Created by 董深育 on 2020/10/6.
//

#include <iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>>tree;
    vector<int>count;//存储一下每个点多少邻接节点
    vector<int>ans;//存储结果
    int N;
    void dfs(int cur,int parent){
        for(int child:tree[cur]){
            if(child==parent) continue;
            dfs(child,cur);
            count[cur]+=count[child];
            ans[cur]+=ans[child]+count[child];
        }
        
    }
    void dfs1(int cur,int parent){
        for(int child:tree[cur]){
            if(child!=parent){
                ans[child]=ans[cur]+(N-count[child])-count[child];
                dfs1(child,cur);
            }
        }
        
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //首先存储所有边
        this->N=N;
        tree=vector<vector<int>>(N);
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].emplace_back(edges[i][1]);
            tree[edges[i][1]].emplace_back(edges[i][0]);
        }
        count=vector<int>(N,1);
        ans=vector<int>(N,0);
        dfs(0,-1);
        dfs1(0,-1);
        return ans;

       }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> >edges={{0,1},{0,2},{2,3},{2,4},{2,5}};
    s.sumOfDistancesInTree(6, edges);
    return 0;
}
