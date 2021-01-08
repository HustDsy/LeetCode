//
//  main.cpp
//  547. 省份数量
//
//  Created by dsy on 2021/1/7.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int point_num=static_cast<int>(isConnected.size());
        if(!point_num) return 0;
        vector<int>flag(point_num,0);
        //每个点开始遍历
        int ans=0;
        for(int i=0;i<point_num;i++){
            if(flag[i]) continue;
            ans++;
            queue<int>bfs;
            bfs.push(i);
            while(!bfs.empty()){
                int size=bfs.size();
                while(size>0){
                    int top=bfs.front();
                    flag[top]=1;
                    for(int i=0;i<point_num;i++){
                        if(i!=top&&isConnected[top][i]==1&&!flag[i]){
                            bfs.push(i);
                        }
                    }
                    bfs.pop();
                    size--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
