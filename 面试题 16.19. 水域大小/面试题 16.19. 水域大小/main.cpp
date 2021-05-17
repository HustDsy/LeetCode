//
//  main.cpp
//  面试题 16.19. 水域大小
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int m;//行
    int n;//列
    int cur;
    void dfs(int i,int j,vector<vector<int>>&v){
        if(i>=m||j<0||j>=n||i<0) return;
        if(v[i][j]) return;
        v[i][j]=1;
        cur++;
        dfs(i-1,j,v);
        dfs(i-1,j+1,v);
        dfs(i-1,j-1,v);
        dfs(i,j-1,v);
        dfs(i,j+1,v);
        dfs(i+1,j,v);
        dfs(i+1,j+1,v);
        dfs(i+1,j-1,v);


    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int>ans;
        m=land.size();
        n=land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!land[i][j]){
                    cur=0;
                    dfs(i,j,land);
                    ans.emplace_back(cur);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>v={{2,8,8,4,1,7,1,5,4,2,0,8,1,9,2,5,6,9,7,4,8,9,1,7,3,6,9,3,7,1,5,7,3,1,9,9,9,6,5,1,9,9,4,1,6,4,7,6,1,6,1,3,3,9,0,3,0,0,0,1,3,1,2,0,0,0,3,2,7,3,6,7,9},{2,0,9,8,2,0,5,8,4,0,4,5,2,1,5,6,0,6,3,3,6,9,5,4,0,9,4,7,1,4,2,8,9,8,0,6,3,5,7,2,1,6,8,4,8,4,6,5,0,3,7,1,7,6,3,0,2,2,2,3,2,4,7,7,6,8,2,9,2,5,0,3,8},{2,7,0,1,1,3,6,5,6,0,7,0,2,4,5,0,3,7,3,1,5,7,9,8,8,0,9,8,1,9,4,7,5,6,5,4,1,7,7,4,4,3,8,3,5,3,3,8,7,4,5,4,8,0,2,0,4,7,5,4,3,9,1,9,4,9,2,2,2,4,1,2,9}};
    return 1;
}
