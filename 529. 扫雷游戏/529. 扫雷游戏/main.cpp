//
//  main.cpp
//  529. 扫雷游戏
//
//  Created by 董深育 on 2020/8/20.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;



class Solution {
public:
 
    //判断位置是否有效
    bool isBound(int x,int y,int col,int row){
        return x<col&&y<row&&x>=0&&y>=0;
        
    }
    //得到周围的雷的数量
     int getBomb(int  x,int y,int col,int row,vector<vector<char>>& board){
         int cnt=0;
         //上
         if(isBound(x-1, y, col, row)&&board[x-1][y]=='M'){
             cnt++;
         }
         //下
         if(isBound(x+1, y, col, row)&&board[x+1][y]=='M'){
             cnt++;
         }
         //左
         if(isBound(x, y-1, col, row)&&board[x][y-1]=='M'){
             cnt++;
         }
         //右
         if(isBound(x, y+1, col, row)&&board[x][y+1]=='M'){
             cnt++;
         }
         //左上
         if(isBound(x-1, y-1, col, row)&&board[x-1][y-1]=='M'){
             cnt++;
         }
         //左下
         if(isBound(x+1, y-1, col, row)&&board[x+1][y-1]=='M'){
             cnt++;
         }
        //右上
         if(isBound(x-1, y+1, col, row)&&board[x-1][y+1]=='M'){
                    cnt++;
                }
         //右下
         if(isBound(x+1, y+1, col, row)&&board[x+1][y+1]=='M'){
             cnt++;
         }
         return cnt;
         
     }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x=click[0];
        int y=click[1];
        int col=(int)board.size();
        if(col==0){
            return {};
        }
        int row=(int)board[0].size();
        if(x>=col||y>=row){
            return board;
        }
        //如果是炸弹的话
        if(board[x][y]=='M'){
            board[x][y]='X';
            return board;
        }
        //vector<vector<int>> flag(row,vector<int>(col,0));
        //如果是1的话
        if(board[x][y]!='E'){
            return board;
        }
        queue<pair<int,int>>myqueue;
        myqueue.push(make_pair(x, y));
        vector<vector<int>>flag(col,vector<int>(row,1));
        flag[x][y]=0;
        while(!myqueue.empty()){
            pair<int,int>temp=myqueue.front();
            myqueue.pop();
            int xx=temp.first;
            int yy=temp.second;
            int kk=getBomb(xx, yy, col, row, board);
            board[xx][yy]=kk==0?'B':to_string(kk)[0];
            if(kk!=0){
                continue;
            }
            if(isBound(xx-1, yy, col, row)&&board[xx-1][yy]=='E'&&flag[xx-1][yy]){
                myqueue.push(make_pair(xx-1, yy));
                flag[xx-1][yy]=0;
            }
            //下
            if(isBound(xx+1, yy, col, row)&&board[xx+1][yy]=='E'&&flag[xx+1][yy]){
                myqueue.push(make_pair(xx+1, yy));
                flag[xx+1][yy]=0;
            }
            //左
            if(isBound(xx, yy-1, col, row)&&board[xx][yy-1]=='E'&&flag[xx][yy-1]){
                myqueue.push(make_pair(xx, yy-1));
                flag[xx][yy-1]=0;
            }
            //右
            if(isBound(xx, yy+1, col, row)&&board[xx][yy+1]=='E'&&flag[xx][yy+1]){
                myqueue.push(make_pair(xx, yy+1));
                flag[xx][yy+1]=0;
            }
            //左上
            if(isBound(xx-1, yy-1, col, row)&&board[xx-1][yy-1]=='E'&&flag[xx-1][yy-1]){
                myqueue.push(make_pair(xx-1, yy-1));
                flag[xx-1][yy-1]=0;
            }
            //左下
            if(isBound(xx+1, yy-1, col, row)&&board[xx+1][yy-1]=='E'&&flag[xx+1][yy-1]){
                myqueue.push(make_pair(xx+1, yy-1));
                flag[xx+1][yy-1]=0;
            }
            //右上
            if(isBound(xx-1, yy+1, col, row)&&board[xx-1][yy+1]=='E'&&flag[xx-1][yy+1]){
                myqueue.push(make_pair(xx-1, yy+1));
                flag[xx-1][yy+1]=0;
            }
            //右下
            if(isBound(xx+1, yy+1, col, row)&&board[xx+1][yy+1]=='E'&&flag[xx+1][yy+1]){
                myqueue.push(make_pair(xx+1, yy+1));
                flag[xx+1][yy+1]=0;
            }
        }
        return board;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> click={3,0};
    vector<vector<char> >ard={{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
   
    s.updateBoard(ard, click);
    return 0;
}
