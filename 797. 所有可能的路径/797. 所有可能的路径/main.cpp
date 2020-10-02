//
//  main.cpp
//  797. 所有可能的路径
//
//  Created by 董深育 on 2020/9/30.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>trace;
    vector<vector<int>>ret;
    void dfs(vector<vector<int>>& graph,int start,int len){
        if(start==len-1){
            trace.push_back(start);
            ret.emplace_back(trace);
            trace.pop_back();
            return;
        }
        for(int i=0;i<graph[start].size();i++){
            trace.push_back(start);
            dfs(graph,graph[start][i],len);
            trace.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int row=(int)graph.size();
        if(row==0)return {};
        dfs(graph,0,row);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > graph={{1,2},{3},{3},{}};
    s.allPathsSourceTarget(graph);
    return 0;
}
