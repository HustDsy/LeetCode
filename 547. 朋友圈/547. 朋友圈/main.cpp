//
//  main.cpp
//  547. 朋友圈
//
//  Created by 董深育 on 2020/8/29.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //直接感染一行
    void infection(int i,vector<vector<int>>&M){
        //如果i,j等于1 将i所有的关系变为0，再去感染j
        for(int k=0;k<M.size();k++){
            if(M[i][k]==1){
                M[i][k]=0;
                infection(k, M);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int row=(int)M.size();
        if(row==0){
            return 0;
        }
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<row;j++){
                if(M[i][j]==1){
                    infection(i,M);
                    cnt++;
                }
            }
          
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
