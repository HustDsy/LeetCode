//
//  main.cpp
//  79. 单词搜索
//
//  Created by 董深育 on 2020/8/26.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool flag=false;
    bool isCan(int x,int y,int col,int row){
        return x>=0&&x<row&&y>=0&&y<col;
        
    }
    bool dfs(int x,int y,vector<vector<char>>& board, string word,int kk,vector<vector<int>>visited,int col,int row){
        if(kk==(int)word.length()){
            flag=true;
            return true;
        }
        //上
        if(isCan(x-1, y, col, row)&&board[x-1][y]==word[kk]&&!visited[x-1][y]){
            visited[x-1][y]=1;
            if(dfs(x-1,y,board,word,kk+1,visited,col,row)){
                return true;
            }
            visited[x-1][y]=0;
        }
        //下
        if(isCan(x+1, y, col, row)&&board[x+1][y]==word[kk]&&!visited[x+1][y]){
            visited[x+1][y]=1;
            if(dfs(x+1,y,board,word,kk+1,visited,col,row)){
                return true;
            }
            visited[x+1][y]=0;
        }
        //左
        if(isCan(x, y-1, col, row)&&board[x][y-1]==word[kk]&&!visited[x][y-1]){
            visited[x][y-1]=1;
            if(dfs(x,y-1,board,word,kk+1,visited,col,row)){
                return true;
            }
            visited[x][y-1]=0;
        }
        //右
        if(isCan(x, y+1, col, row)&&board[x][y+1]==word[kk]&&!visited[x][y+1]){
            visited[x][y+1]=1;
            if (dfs(x,y+1,board,word,kk+1,visited,col,row)){
                return true;
            }
            visited[x][y+1]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=static_cast<int>(board.size());
        if(row==0){
            return false;
        }
        int col=static_cast<int>(board[0].size());
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    int kk=1;
                    vector<vector<int>>visited(row,vector<int>(col,0));
                    visited[i][j]=1;
                    bool tt=dfs(i,j,board,word,kk,visited,col,row);
                    if(tt){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char> >board={{'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    s.exist(board, "ABCCEd");
    return 0;
}
