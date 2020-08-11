//
//  main.cpp
//  130. 被围绕的区域
//
//  Created by 董深育 on 2020/8/11.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    //广度优先搜索
    struct Point{
        int i;
        int j;
        Point(int i,int j){
            this->i=i;
            this->j=j;
        }
    };
    bool inSide(int i,int j,int row,int col){
        return i<=row-1&&i>=0&&j>=0&&j<=col-1;
    }
    void solve(vector<vector<char>>& board) {
        int row=(int)board.size();
        if(row==0||row==1){
            return;
        }
        int col=(int)board[0].size();
        if(col==1){
            return;
        }
        //1代表需要染色 0代表不要，初始化都要染色
        vector<vector<int>>dp(row,vector<int>(col,1));
        //是否访问过了
        vector<vector<bool>>flag(row,vector<bool>(col,0));
        queue<Point>myqueue;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //把边界的O都找出来
                if((i==0||i==row-1||j==0||j==col-1)&&board[i][j]=='O'){
                    //不需要染色
                    dp[i][j]=0;
                    Point point(i,j);
                    //被访问过了
                    flag[i][j]=1;
                    myqueue.push(point);
                }
                if(board[i][j]=='X'){
                    //不需要染色
                    dp[i][j]=0;
                }
            }
        }
        //BFS
        while(!myqueue.empty()){
            Point temp=myqueue.front();
            myqueue.pop();
            int x=temp.i;
            int y=temp.j;
            //左边的值
            //索引有效，没被访问过，并且为O
            if((inSide(x,y-1, row, col)&&!flag[x][y-1]&&board[x][y-1]=='O')){
                Point point(x,y-1);
                myqueue.push(point);
                flag[x][y-1]=1;
                //不需要被染色
                dp[x][y-1]=0;
            }
            //右边的值
            if((inSide(x,y+1, row, col)&&!flag[x][y+1]&&board[x][y+1]=='O')){
                Point point(x,y+1);
                myqueue.push(point);
                flag[x][y+1]=1;
                //不需要被染色
                dp[x][y+1]=0;
            }
            //上面的值
            if((inSide(x-1,y, row, col)&&!flag[x-1][y]&&board[x-1][y]=='O')){
                Point point(x-1,y);
                myqueue.push(point);
                flag[x-1][y]=1;
                //不需要被染色
                dp[x-1][y]=0;
            }
            //下面的值
            if((inSide(x+1,y, row, col)&&!flag[x+1][y]&&board[x+1][y]=='O')){
                Point point(x+1,y);
                myqueue.push(point);
                flag[x+1][y]=1;
                //不需要被染色
                dp[x+1][y]=0;
            }
        }
        //染色
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dp[i][j]==1&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>>rr={{1,2,3}};
    vector<vector<char>>board ={{'O','O'},{'O','O'}};
    s.solve(board);

    return 0;
}
