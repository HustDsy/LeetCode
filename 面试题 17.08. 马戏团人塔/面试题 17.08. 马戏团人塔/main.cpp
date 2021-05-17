//
//  main.cpp
//  面试题 17.08. 马戏团人塔
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>>p;
        int n=height.size();
        p.reserve(n);
        for(int i=0;i<n;i++){
            p.emplace_back(height[i],weight[i]);
        }
        sort(p.begin(),p.end(),[](auto&x,auto&y)->bool{
            return x.first<y.first||(x.first==y.first&&x.second>y.second);
        });
        vector<int>dp;
        dp.push_back(p[0].second);
        for(int i=1;i<n;i++){
            if(p[i].second>dp.back()){
                dp.push_back(p[i].second);
            }else{
                auto pos=lower_bound(dp.begin(),dp.end(),p[i].second);
                *pos=p[i].second;
            }
        }
        return dp.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
