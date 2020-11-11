//
//  main.cpp
//  514. 自由之路
//
//  Created by 董深育 on 2020/11/11.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int>ans;
    //i表示key i
    //pre表示上一步的索引
    //len表示key的长度
    //indexMap表示每个i的索引
    //cnt表示到这一步需要的步数
    void dfs(int i,int pre,string ring,string key,int len,int cnt,unordered_map<int, vector<int>>indexMap){
        if(i==len){
            ans.push_back(cnt);
            return;
        }
        vector<int>indexs=indexMap[key[i]-'a'];
        for(int item:indexs){
            //旋转来的，pre为最开始的位置
            //逆时针还是顺时针
            int temp=min(abs(item-pre),abs())+1;
        }
        
        
    }
    
    int findRotateSteps(string ring, string key) {
        //记录一下每个位置在那几个索引
        unordered_map<int, vector<int>>indexMap;
        int rl=(int)ring.length();
        int kl=(int)key.length();
        for(int i=0;i<rl;i++){
            indexMap[ring[i]-'a'].emplace_back(i);
        }
        

    }
    
    
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];
        for (int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }
        int dp[m][n];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for (auto& i: pos[key[0] - 'a']) {
            dp[0][i] = min(i, n - i) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (auto& j: pos[key[i] - 'a']) {
                for (auto& k: pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1], dp[m - 1] + n);
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
