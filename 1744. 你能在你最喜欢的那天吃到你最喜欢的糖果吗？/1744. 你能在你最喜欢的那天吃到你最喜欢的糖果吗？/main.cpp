//
//  main.cpp
//  1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
//
//  Created by dsy on 2021/6/1.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n=candiesCount.size();
        vector<bool>ans;
        vector<long long>sum(n);
        sum[0]=candiesCount[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+candiesCount[i];
        }
        for(auto&q:queries){
            long long type=q[0];//喜欢的类型索引
            long long day=q[1];//要在第几天吃到
            long long cap=q[2];//每天最多吃多少
            long long x1=day+1;//到这一天时，至少得吃多少糖果
            long long y1=(day+1)*cap;//最多吃多少
            long long x2=type==0?0:sum[type-1]+1;//到这一天 前缀和，至少吃了
            long long y2=sum[type];
            ans.push_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
