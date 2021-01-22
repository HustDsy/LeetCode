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
    vector<int>root;
    int find(int index){
        if(index!=root[index]){
            root[index]=find(root[index]);
        }
        //一定返回root[index]而不是Index
        return root[index];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len=edges.size();
        root=vector<int>(len+1,0);
        for(int i=1;i<=len;i++){
            root[i]=i;
        }
        vector<int>last;//表示出现环的最后一条边，此时入度都为1，同时也可以判断有没有环
        vector<int>edge1;//表示入度为2时的一条边
        vector<int>edge2;//表示入度为2时的第二条边
        vector<int>parents(len+1,0);//记录每个点的父亲节点，判断是不是有入度为2的点
        for(auto&pair:edges){
            int u=pair[0];
            int v=pair[1];
            //表明出现了入度为2的边，
            if(parents[v]!=0){
                //记录edge1,等于之前出现的那条边
                edge1={parents[v],v};
                //现在这条边，跳过，看是否有环
                edge2=pair;
            }else{
                //没有入度为2的话 通过并查集查看有没有环
                parents[v]=u;
                int ru=find(u);
                int rv=find(v);
                if(ru!=rv){
                    root[rv]=ru;
                }else{
                    //出现了环，last补上
                    last=pair;
                }
            }
        }
        if(!edge1.empty()&&!edge2.empty()){
            //last为空表示跳过2就没环了 否则应该返回1
            return last.empty()?edge2:edge1;
        }else{
            return last;
        }
    }
};




int main(int argc, const char * argv[]) {
 
    Solution s;
    vector<vector<int> >edges={
        {1,2},{1,3},{2,3}};
    s.findRedundantDirectedConnection(edges);
   
    
    return 0;
}
