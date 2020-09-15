//
//  main.cpp
//  37. 解数独
//
//  Created by 董深育 on 2020/9/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int row=9;
    const int col=9;
    inline int getaAreaNum(int i,int j){
        if(i>=0&&i<=2){
            if(j>=0&&j<=2){
                return 0;
            }
            if(j>=3&&j<=5){
                return 1;
            }
            
            if(j>=6&&j<=8){
                return 2;
            }
        }else if(i>=3&&i<=5){
            if(j>=0&&j<=2){
                return 3;
            }
            if(j>=3&&j<=5){
                return 4;
            }
            
            if(j>=6&&j<=8){
                return 5;
            }
        }else{
            if(j>=0&&j<=2){
                return 6;
            }
            if(j>=3&&j<=5){
                return 7;
            }
            
            if(j>=6&&j<=8){
                return 8;
            }
        }
        return -1;
    }
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& rowNum,vector<vector<int>>& colNum,vector<vector<int>>& areaNum,int i,int j){
        
        //寻找空位置，找不到了就说明是true;
//       bool flag=true;
//        for(int i1=0;i1<row;i1++){
//            for(int j1=0;j1<col;j1++){
//                if(board[i1][j1]=='.'){
//                    flag=false;
//                    i=i1;
//                    j=j1;
//                    break;
//                }
//            }
//             if(!flag) break;
//        }
//        if(flag) return true;
    
        while (board[i][j] != '.') {
            if (++j >= 9) {
                i++;
                j = 0;
            }
            if (i >= 9) {
                return true;
            }
        }
        //对i，j开始填数字
        int kk=getaAreaNum(i, j);
        for(int num=0;num<9;num++){
            if(rowNum[i][num]&&colNum[j][num]&&areaNum[kk][num]){
                board[i][j]=num+1+'0';//int 转 char
                rowNum[i][num]=0;
                colNum[j][num]=0;
                areaNum[kk][num]=0;
                if(dfs(board,rowNum,colNum,areaNum,i,j))return true;
                board[i][j]='.';
                rowNum[i][num]=1;
                colNum[j][num]=1;
                areaNum[kk][num]=1;
            }
        }
        //如果所有数找不到交集
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        //可以取表示1，不可以表示0
        vector<int>nums={1,1,1,1,1,1,1,1,1};
        vector<vector<int>>rowNum(9,nums);//表明这一行可以取的数
        vector<vector<int>>colNum(9,nums);//表明这一列可以取得数
        vector<vector<int>>areaNum(9,nums);//表明每个9*9的区域可以取得的数
        //初始化上面三个数组
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]>'0'&&board[i][j]<='9'){
                    rowNum[i][board[i][j]-'0'-1]=0;
                    colNum[j][board[i][j]-'0'-1]=0;
                    int areaIndex=getaAreaNum(i, j);
                    areaNum[areaIndex][board[i][j]-'0'-1]=0;
                }
            }
        }
        dfs(board,rowNum,colNum,areaNum,0,0);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>>board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
    return 0;
}
