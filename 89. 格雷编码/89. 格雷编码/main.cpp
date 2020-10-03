//
//  main.cpp
//  89. 格雷编码
//
//  Created by 董深育 on 2020/10/3.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<int>ret;
    int size;
    bool dfs(int n,int cur,vector<int>&flag){
        if(ret.size()==size){
            return  true;
        }
        for(int i=0;i<n;i++){
            int num=1<<i;
            int next=cur^num;
            if(flag[next]){
                continue;
            }
            ret.push_back(next);
            flag[next]=1;
            if(dfs(n,next,flag))return true;
            flag[next]=0;
            ret.pop_back();
        }
        return  false;
    }
    vector<int> grayCode(int n) {
        size=pow(2,n);
        ret.push_back(0);
        vector<int>flag(size,0);
        flag[0]=1;
        dfs(n,0,flag);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.grayCode(2);
    return 0;
}
