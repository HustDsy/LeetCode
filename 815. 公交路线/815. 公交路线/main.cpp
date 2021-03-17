//
//  main.cpp
//  815. 公交路线
//
//  Created by dsy on 2021/3/10.
//

#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        //建立站台到线路的映射
        unordered_map<int,vector<int>>s_to_r;
        for(int i=0;i<routes.size();i++){
            for(int r:routes[i]){
                s_to_r[r].push_back(i);
            }
        }
        queue<int>q;
        vector<int>flag(routes.size(),0);//开始都没遍历过
        //将source的线路放入队列中
        for(int r:s_to_r[source]){
            q.push(r);
            flag[r]=1;
        }
        //开始遍历
        int res=0;
        while(!q.empty()){
            int size=q.size();
            res++;
            while(size){
                //将这个线路得到
                int top=q.front();
                q.pop();
                //首先判断这个线路包不包括target
                for(int i:routes[top]){
                    if(i==target){
                        return res;
                    }
                    //将有交叉的站点压入到队列中,i
                    for(int k:s_to_r[i]){
                        if(flag[k]) continue;
                        q.push(k);
                    }
                }
                --size;
            }
        }
        //遍历都没得到的话 返回-1
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>dp={{25,33},{3,5,13,22,23,29,37,45,49},{15,16,41,47},{5,11,17,23,33},{10,11,12,29,30,39,45},{2,5,23,24,33},{1,2,9,19,20,21,23,32,34,44},{7,18,23,24},{1,2,7,27,36,44},{7,14,33}};
    cout<<s.numBusesToDestination(dp, 7, 47);
    return 0;
}
