//
//  main.cpp
//  841. 钥匙和房间
//
//  Created by 董深育 on 2020/8/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    //将这一行都感染
    void  infection(int i,vector<vector<int>>&rooms,vector<int>&flag){
        for(int k=0;k<rooms[i].size();k++){
            int j=rooms[i][k];
            rooms[i][k]=0;
            if(flag[j]==0){
                flag[j]=1;
                infection(j, rooms, flag);
                
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len=(int)rooms.size();
        if(len==1){
            return true;
        }
        vector<int>flag(len,0);
        flag[0]=1;
        infection(0,rooms,flag);
        
        return accumulate(flag.begin(), flag.end(), 0)==len;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > rooms={{1},{2},{3},{}};
    s.canVisitAllRooms(rooms);
    return 0;
}
