//
//  main.cpp
//  329-矩阵中的最长递增路径
//
//  Created by 董深育 on 2020/7/26.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //得到从点i，j出发的最大的递增路径
    int getMax(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&result){
        int row=(int)matrix.size();
        int col=(int)matrix[0].size();
        if(i>=row&&j>=col){
            return 0;
        }
        int ret=1;
        int num=0;
        //走右边
        if(j+1<col){
            if(matrix[i][j+1]>matrix[i][j]){
                if(result[i][j+1]==0){
                    num=max(num,getMax(matrix, i, j+1,result));
                }else{
                    num=max(num,result[i][j+1]);
                }
     
            }
        }
        //走下边
        if(i+1<row){
            if(matrix[i+1][j]>matrix[i][j]){
                if(result[i+1][j]==0){
                    num=max(num,getMax(matrix, i+1, j,result));
                }else{
                    num=max(num,result[i+1][j]);
                }
            }
        }
        //左边走
        if(j-1>=0){
            if(matrix[i][j-1]>matrix[i][j]){
                if(result[i][j-1]==0){
                    num=max(num,getMax(matrix, i, j-1,result));
                    
                }else{
                    num=max(num,result[i][j-1]);
                }
            }
        }
        //往上走
        if(i-1>=0){
            if(matrix[i-1][j]>matrix[i][j]){
                if(result[i-1][j]==0){
                    num=max(num,getMax(matrix, i-1, j,result));
                    
                }else{
                    num=max(num,result[i-1][j]);
                }
            }
        }
        ret=ret+num;
        result[i][j]=ret;
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret=0;
        int row=(int)matrix.size();
        if(row==0){
            return 0;
        }
        int col=(int)matrix[0].size();
        vector<vector<int>>result(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ret=max(ret,getMax(matrix,i , j,result));
            }
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code
    Solution s;
    vector<vector<int>>matrix={{9,9,4},{6,6,8},{2,1,1}};
    int ret=s.longestIncreasingPath(matrix);
    return 0;
}
