//
//  main.cpp
//  733. 图像渲染
//
//  Created by 董深育 on 2020/8/16.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;




class Solution {
public:
    bool isIn(int x,int y,int row,int col){
        return x>=0&&x<row&&y>=0&&y<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row=(int)image.size();
        if(row==0){
            return {};
        }
        int col=(int)image[0].size();
        //初始化为0，代表均没有访问过
        vector<vector<int>>visited(row,vector<int>(col,0));
        //BFS
        queue<pair<int,int>>myqueue;
        //将起始点push进来
        myqueue.push(make_pair(sr, sc));
        //记录当前点的颜色
        int currColor=image[sr][sc];
        //访问过了
        visited[sr][sc]=1;
        image[sr][sc]=newColor;
        while(!myqueue.empty()){
            pair<int,int>temp=myqueue.front();
            myqueue.pop();
            int x=temp.first;
            int y=temp.second;
            //满足在边界，颜色一致并且没有被访问过
            //上面的点
            if(isIn(x-1, y, row, col)&&image[x-1][y]==currColor&&visited[x-1][y]==0){
                myqueue.push(make_pair(x-1, y));
                image[x-1][y]=newColor;
                visited[x-1][y]=1;
            }
            //下面的点
            if(isIn(x+1, y, row, col)&&image[x+1][y]==currColor&&visited[x+1][y]==0){
                myqueue.push(make_pair(x+1, y));
                image[x+1][y]=newColor;
                visited[x+1][y]=1;
            }
            //左边的点
            if(isIn(x, y-1, row, col)&&image[x][y-1]==currColor&&visited[x][y-1]==0){
                myqueue.push(make_pair(x, y-1));
                image[x][y-1]=newColor;
                visited[x][y-1]=1;
            }
            //右边的点
            if(isIn(x, y+1, row, col)&&image[x][y+1]==currColor&&visited[x][y+1]==0){
                myqueue.push(make_pair(x, y+1));
                image[x][y+1]=newColor;
                visited[x][y+1]=1;
            }
            
        }
        return image;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>>image={{0,0,0},{0,1,1}};
    Solution s;
    s.floodFill(image, 1, 1, 1);
    return 0;
}
