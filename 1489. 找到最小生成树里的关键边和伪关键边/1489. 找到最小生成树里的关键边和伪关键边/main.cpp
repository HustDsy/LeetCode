//
//  main.cpp
//  1489. 找到最小生成树里的关键边和伪关键边
//
//  Created by dsy on 2021/1/21.
//

#include <iostream>
#include<vector>
using namespace std;

class uion{
public:
    vector<int>parent;
    vector<int>rank;
    vector<int>len;
    vector<int>size;
    int nums;
    uion(int n):parent(n),rank(n,0),len(n,0),size(n,1),nums(n){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    
    int merge(int x,int y,int l){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            if(rank[px]<rank[py]){
                swap(px,py);
            }
            parent[py]=px;
            if(rank[px]==rank[py]) rank[px]++;
            size[px]=size[px]+size[py];
            len[px]+=len[py]+l;
            if(size[px]==nums) return len[px];
        }
        return -1;
    }
    
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>a=edges;
        //一共有n个点
        vector<vector<int>>ans(2);
        int es=(int)edges.size();
        for(int i=0;i<es;i++){
            edges[i].push_back(i);
        }
        //从小到大排序
        sort(edges.begin(),edges.end(),[](auto&a,auto&b)->bool{
            return a[2]<b[2];
        });
    
        vector<int>flag(es,0);
        int rs=0;
        uion uu(n);
        for(auto&e:edges){
            int ret=uu.merge(e[0], e[1], e[2]);
            flag[e[3]]=1;
            if(ret!=-1){
                rs=ret;
                break;
            }
        }
        for(int i=0;i<es;i++){
            int rs_=0;
            uion u(n);
            vector<int>flag_1;
            for(int j=0;j<es;j++){
                if(i==j)
                    continue;
                rs_=u.merge(edges[j][0], edges[j][1], edges[j][2]);
                flag_1.push_back(edges[j][3]);
                if(rs_!=-1){
                    break;
                }
                
            }
            if(rs_!=rs){
                ans[0].push_back(edges[i][3]);
                flag[edges[i][3]]=2;
            }else{
                for(int i=0;i<flag_1.size();i++){
                    if(flag[flag_1[i]]) continue;
                    flag[flag_1[i]]=1;
                }
            }
        }
        
        for(int i=0;i<es;i++){
            if(flag[i]==1){
                ans[1].push_back(i);
            }
            if(flag[i]==0){
                uion t(n);
                int r=0;
                t.merge(a[i][0],a[i][1],a[i][2]);
                for(auto&e:edges){
                    if(e[3]==i){
                        continue;
                    }
                    r=t.merge(e[0], e[1], e[2]);
                    if(r!=-1) break;
                }
                if(r==rs){
                    ans[1].push_back(i);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > edges={{0,1,1},{0,2,2},{1,2,3}};
    s.findCriticalAndPseudoCriticalEdges(3,edges);
    return 0;
}
