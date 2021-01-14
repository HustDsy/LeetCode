//
//  main.cpp
//  1203. 项目管理
//
//  Created by dsy on 2021/1/12.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    //入度数组 图 设计到的顶点
    vector<int>topSort(vector<int>&deg,vector<vector<int>>&gra,vector<int>&items){
        queue<int>q;//将入度为0的数据push进去
        for(auto&it:items){
            if(deg[it]==0){
                q.push(it);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.emplace_back(u);
            for(auto&v:gra[u]){
                if(--deg[v]==0){
                    q.push(v);
                }
            }
        }
        return ans.size()==items.size()?ans:vector<int>{};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //groupItem 代表对应的组所要处理的项目
        vector<vector<int>>groupItem(n+m);
        
        //组间和组内依赖图
        vector<vector<int>>groupGraph(n+m);
        vector<vector<int>>itemGraph(n);
        
        
        vector<int>groupDegree(n+m,0);
        vector<int>itemDegree(n,0);
        
        vector<int>id;
        
        for(int i=0;i<n+m;i++){
            id.emplace_back(i);
        }
        int leftId=m;
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=leftId;
                leftId++;
            }
            groupItem[group[i]].emplace_back(i);
        }
        //依赖关系建立图
        for(int i=0;i<n;i++){
            int curGroupId=group[i];
            //看这个项目依赖哪些其它的项目
            for(auto&item:beforeItems[i]){
                //看这个组依赖其它的哪些组
                int beforeGoupId=group[item];
                if(beforeGoupId==curGroupId){
                    itemDegree[i]+=1;
                    itemGraph[item].emplace_back(i);
                }else{
                    groupDegree[curGroupId]+=1;
                    groupGraph[beforeGoupId].emplace_back(curGroupId);
                }
            }
        }
        vector<int>groupTopSort=topSort(groupDegree, groupGraph, id);
        if(groupTopSort.size()==0){
            return {};
        }
        vector<int>ans;
        for(auto&item:groupTopSort){
            int size=groupItem[item].size();
            if(size==0) continue;
            vector<int>itemTopSort=topSort(itemDegree, itemGraph, groupItem[item]);
            if(itemTopSort.size()==0) return {};
            for(auto&i:itemTopSort){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    return 0;
}
