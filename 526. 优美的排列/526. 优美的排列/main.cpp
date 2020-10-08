//
//  main.cpp
//  526. 优美的排列
//
//  Created by 董深育 on 2020/10/8.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int ans;
    //pos表示已经成功到达第几个位置了
    //flag表示哪些单词用了
    void dfs(int N,int pos,vector<int>&flag){
        if(pos==N+1){
            ans++;
            return;
        }
        for(int i=1;i<=N;i++){
            if(flag[i])continue;
            if((i%pos==0)||(pos%i)==0){
                flag[i]=1;
                dfs(N,pos+1,flag);
                flag[i]=0;
            }
        }
    }
    
    int countArrangement(int N) {
        vector<int>flag(N+1,0);
        dfs(N,1,flag);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.countArrangement(2);
    return 0;
}
