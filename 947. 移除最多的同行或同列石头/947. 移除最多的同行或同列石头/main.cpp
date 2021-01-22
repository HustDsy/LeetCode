//
//  main.cpp
//  947. 移除最多的同行或同列石头
//
//  Created by dsy on 2021/1/15.
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
        return root[index];
    }
    
    void uion(int index1,int index2){
        root[find(index1)]=find(index2);
    }
    int removeStones(vector<vector<int>>& stones) {
        int len=(int)stones.size();
        root=vector<int>(len+1,0);
        for(int i=1;i<=len;i++){
            root[i]=i;
        }
        //初始化并查集
        int ix,iy,jx,jy;
        for(int i=1;i<=len;i++){
            ix=stones[i-1][0];
            iy=stones[i-1][1];
            for(int j=i+1;j<=len;j++){
                jx=stones[j-1][0];
                jy=stones[j-1][1];
                if((ix==jx||iy==jy)&&find(i)!=find(j)){
                    uion(i, j);
                }
            }
        }
        for(int i=1;i<=len;i++){
            find(i);
        }
        vector<int>flag(len+1,0);
        int cur=0;
        for(int i=1;i<=len;i++){
            if(!flag[root[i]]){
                cur+=1;
                flag[root[i]]+=1;
            }else{
                flag[root[i]]+=1;
            }
        }
        return len-cur;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> >stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    s.removeStones(stones);
    return 0;
}
