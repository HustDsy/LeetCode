//
//  main.cpp
//  1711. 大餐计数
//
//  Created by dsy on 2021/1/14.
//

#include <iostream>
#include<vector>
#include<map>
using namespace std;

const int Mod=1e9+7;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        //从小到大排序
        map<int,int>cnt;
        for(auto&v:deliciousness) cnt[v]++;
        int ret=0;
        for(const auto&[k,v]:cnt){
            for(int x=1;x<=(1<<21);x*=2){
                int nk=x-k;
                if(nk<k) continue; //防止重复计算
                if(cnt.find(nk)!=cnt.end()){
                    if(nk!=k){
                        ret+=1LL*cnt[nk]*cnt[k]%Mod;
                        if(ret>=Mod) ret-=Mod;
                    }else{
                        ret+=1LL*v*(v-1)/2%Mod;
                        if(ret>=Mod) ret-=Mod;
                    }
                }
                
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> deliciousness={1,1,1,3,3,3,7};
    cout<<s.countPairs(deliciousness);
    return 0;
}
