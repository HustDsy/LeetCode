//
//  main.cpp
//  785-判断二分图
//
//  Created by 董深育 on 2020/7/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int uncolor=0;//未被染色
        int red=1;//被染成红色
        int green=2;//被染成绿色
        //graph[i]代表节点i相邻的节点
        int n=(int)graph.size();
        vector<int>color(n,uncolor);
        //由于可能是非连通图，避免有的节点未染色，每个节点都遍历一遍
        for(int i=0;i<n;i++){
            if(color[i]==uncolor){
                queue<int>nodes;
                nodes.push(i);
                color[i]=red;
                while(!nodes.empty()){
                    //开始染色
                    int node=nodes.front();
                    nodes.pop();
                    //用来判断他的邻居应该是什么颜色
                    int temp=(color[node]==red)?green:red;
                    for(int j=0;j<graph[node].size();j++){
                        if(color[graph[node][j]]==uncolor){
                            color[graph[node][j]]=temp;
                            nodes.push(graph[node][j]);
                        }else if(color[graph[node][j]]!=temp){
                            return false;
                        }
                    }
                }
                
                
            }
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
