//
//  main.cpp
//  452. 用最少数量的箭引爆气球
//
//  Created by dsy on 2021/3/19.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=0;
        sort(points.begin(),points.end(),[](auto&a,auto&b)->bool{
            return a[0]<b[0];
        });
        if(points.size()==0) return res;
        auto pre=points[0];
        for(auto&p:points){
            //判断有没有交集
            int x=p[0];
            int y=p[1];
            if(x>pre[1]){
                pre=p;
                res++;//没有交集
            }else{
                pre[0]=max(pre[0],x);
                pre[1]=min(pre[1],y);
            }
        }
        return res+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
