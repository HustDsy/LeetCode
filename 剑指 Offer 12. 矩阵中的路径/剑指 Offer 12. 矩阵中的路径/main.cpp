//
//  main.cpp
//  剑指 Offer 12. 矩阵中的路径
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
      inline bool isvaild(int i,int j,int row,int col){
        return i<row&&j<col&&i>=0&&j>=0;
        
    }
    bool dfs(string word,int i,int j,vector<vector<char>>& board,int row,int col,int k){
        if(k==word.length()){
            return true;
        }
        //如果上下左右都不相等 返回false
        
        //上
        if(isvaild(i-1, j, row, col)&&board[i-1][j]==word[k]){
            board[i-1][j]='#';//标记已经访问过
            if(dfs(word,i-1,j,board,row,col,k+1)) return true;
            board[i-1][j]=word[k];
        }
        //下
        if(isvaild(i+1, j, row, col)&&board[i+1][j]==word[k]){
            board[i+1][j]='#';//标记已经访问过
            if(dfs(word,i+1,j,board,row,col,k+1)) return true;
            board[i+1][j]=word[k];
        }
        //左
        if(isvaild(i, j-1, row, col)&&board[i][j-1]==word[k]){
            board[i][j-1]='#';//标记已经访问过
            if (dfs(word,i,j-1,board,row,col,k+1)) return true;;
            board[i][j-1]=word[k];
        }
        //右
        if(isvaild(i, j+1, row, col)&&board[i][j+1]==word[k]){
            board[i][j+1]='#';//标记已经访问过
            if(dfs(word,i,j+1,board,row,col,k+1)) return  true;
            board[i][j+1]=word[k];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=(int)board.size();
        if(row==0) return false;
        int col=(int)board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    board[i][j]='#';
                    if(dfs(word,i,j,board,row,col,1)) return true;
                    board[i][j]=word[0];
                }
                
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
