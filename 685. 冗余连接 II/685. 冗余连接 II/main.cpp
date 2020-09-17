//
//  main.cpp
//  685. 冗余连接 II
//
//  Created by 董深育 on 2020/9/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>roots;//并查集
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //初始化并查集
        int n=(int)edges.size();
        roots=vector<int>(n+1,0);
        for(int i=1;i<=n;i++){
            roots[i]=i;
        }
        vector<int>parent(n+1,0);//记录父亲节点
        vector<int>edge1;
        vector<int>edge2;
        vector<int>last;
        for(int i=0;i<n;i++){
            //0是父节点，1是字节点
            int u=edges[i][0];
            int v=edges[i][1];
            //开始初始化并查集
            if(parent[v]!=0){
                edge1={parent[v],v};
                edge2=edges[i];
            }else{
                parent[v]=u;
                int ancu=find(u);
                int ancv=find(v);
                if(ancu!=ancv){
                    roots[ancv]=ancu;
                }else{
                    last=edges[i];
                }
            }
        }
        if(!edge1.empty()&&!edge2.empty()){
            return last.empty()?edge2:edge1;
        }else{
            return last;
        }
    }
    int find(int node){
        if(roots[node]==node)return node;
        roots[node]=find(roots[node]);
        return roots[node];
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > edges={{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
    s.findRedundantDirectedConnection(edges);
    std::cout << "Hello, World!\n";
    return 0;
}
