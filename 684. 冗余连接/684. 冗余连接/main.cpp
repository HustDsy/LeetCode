//
//  main.cpp
//  684. 冗余连接
//
//  Created by dsy on 2021/1/14.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>parent;
    
    int find(int index){
        if(parent[index]!=index){
            parent[index]=find(parent[index]);
        }
        return parent[index];
    }
    void uion(int index1,int index2){
        
        parent[find(index1)]=find(index2);
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        parent=vector<int>(nodesCount+1,0);
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i]=i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (find(node1) !=find(node2)) {
                uion(node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int> >edges={{1,2},{1,3},{2,3}};
    s.findRedundantConnection(edges);
    return 0;
}
