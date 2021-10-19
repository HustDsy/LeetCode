//
//  main.cpp
//  787. K 站中转内最便宜的航班
//
//  Created by dsy on 2021/3/12.
//

#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>>dp(n,vector<int>(K+1,INT_MAX));
        for(int i=0;i<=K;i++){
            dp[src][i]=0;
        }
        for(auto&f:flights){
            if(f[0]==src){
                dp[f[1]][0]=f[2];
            }
        }
        for(int i=1;i<=K;i++){
            for(auto&f:flights){
                int from=f[0];
                int to=f[1];
                int cost=f[2];
                if(dp[from][i-1]!=INT_MAX){
                    dp[to][i]=min(dp[to][i],dp[from][i-1]+cost);
                }
            }
        }
        
        return dp[dst][K]==INT_MAX?-1:dp[dst][K];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > flights={{0,1,100},{1,2,100},{0,2,500}};
    s.findCheapestPrice(3, flights, 0, 2, 1);
    return 0;
}
