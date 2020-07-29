//
//  main.cpp
//  LCP 13-寻宝
//
//  Created by 董深育 on 2020/7/29.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    //迷宫的行
    int n;
    //迷宫的列
    int m;
    struct Point{
        int x;
        int y;
        Point(int x,int y){
            this->x=x;
            this->y=y;
        }
    };
 
    //判断点是否在边界内
    bool inBound(int x,int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    //计算某个点到其它点的距离
    vector<vector<int>>bfs(int x,int y,vector<string>maze){
        vector<vector<int>> ret(n, vector<int>(m, -1));
        Point point(x,y);
        queue<Point>points;
        points.push(point);
        ret[x][y]=0;
        while(!points.empty()){
            Point tempPoint=points.front();
            points.pop();
            int x=tempPoint.x;
            int y=tempPoint.y;
            //上
            if(inBound(x-1,y)&&maze[x-1][y]!='#'&&ret[x-1][y]==-1){
                ret[x-1][y]=ret[x][y]+1;
                Point assist(x-1,y);
                points.push(assist);
            }
            //下
            if(inBound(x+1,y)&&maze[x+1][y]!='#'&&ret[x+1][y]==-1){
                ret[x+1][y]=ret[x][y]+1;
                Point assist(x+1,y);
                points.push(assist);
            }
            //左
            if(inBound(x,y-1)&&maze[x][y-1]!='#'&&ret[x][y-1]==-1){
                ret[x][y-1]=ret[x][y]+1;
                Point assist(x,y-1);
                points.push(assist);
            }
            //右
            if(inBound(x,y+1)&&maze[x][y+1]!='#'&&ret[x][y+1]==-1){
                ret[x][y+1]=ret[x][y]+1;
                Point assist(x,y+1);
                points.push(assist);
            }
        }
        return ret;
    }

    int minimalSteps(vector<string>& maze) {
        n=(int)maze.size();
        m=(int)maze[0].size();
        //记录起点和终点
        int bx,by;
        int ex,ey;
        //记录石头
        vector<Point>stonePoint;
        //记录机关
        vector<Point>buttonPoint;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='S'){
                    bx=i;
                    by=j;
                }
                if(maze[i][j]=='T'){
                    ex=i;
                    ey=j;
                }
                if(maze[i][j]=='M'){
                    Point temp(i,j);
                    buttonPoint.push_back(temp);
                }
                if(maze[i][j]=='O'){
                    Point temp(i,j);
                    stonePoint.push_back(temp);
                }
            }
        }
        //石头的数量
        int stones=(int)stonePoint.size();
        //按钮的数量
        int buttons=(int)buttonPoint.size();
        vector<vector<int>> start_dist = bfs(bx, by, maze);
        //没有机关的话，那么最近的距离就是起点到终点的距离了
        if(buttons==0){
            return start_dist[ex][ey];
        }
        
        
        
        
        //机关到机关之间的距离,以及到起点和终点的距离
        vector<vector<int>>button_dist(buttons,vector<int>(buttons+2,-1));
        // 中间结果，记录每一个button到其它i，j的距离
        vector<vector<vector<int>>> dd(buttons);
        for(int i=0;i<buttons;i++){
            vector<vector<int>> temp_dist=bfs(buttonPoint[i].x, buttonPoint[i].y, maze);
            dd[i]=temp_dist;
            //从某个点到终点不需要拿石头
            button_dist[i][buttons+1]=temp_dist[ex][ey];
        }
        
        //得到S-O-M 以及M-O-M的最短距离
        for(int i=0;i<buttons;i++){
            int tmp=-1;
            //枚举所有O
            for(int k=0;k<stones;k++){
                int mid_x=stonePoint[k].x;
                int mid_y=stonePoint[k].y;
                //如果这个M可以到达这个机关，并且S也可以到达这个机关，寻求S-O-M的最小值
                if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {
                    if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
                        tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                    }
                }
            }
            button_dist[i][buttons]=tmp;
            //继续枚举O和除它之外的M，寻找M-O-M的最小值
            for(int j=i+1;j<buttons;j++){
                int t=-1;
                for(int k=0;k<stones;k++){
                    int mid_x=stonePoint[k].x;
                    int mid_y=stonePoint[k].y;
                    //如果这个M可以到达这个机关，并且另一个M也可以到达这个机关，寻求M-O-M的最小值
                    if (dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
                        if (t == -1 || t> dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]) {
                            t = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];
                        }
                    }
                }
                button_dist[i][j]=t;
                button_dist[j][i]=t;
            }
        }
        //到这里button_dist[i][j]就代表着第i个M到第j个的最短距离，以及到S的最短距离 到T的距离
         //没有一条路径可以使得S-O-M-O-M-T
        //因为要经过所有M，那么对于每个M 必须可以S-O-M-T 至少有这样的一条路径存在
        for(int i=0;i<buttons;i++){
            if(button_dist[i][buttons]==-1||button_dist[i][buttons+1]==-1){
                return -1;
            }
        }
        //如过可以抵达的话，必须经过经过所有的
        //f(mask|j,j)=min(f(mask,i)+dp[i][j])
        //一共由2的buttons的次方的状态
         // dp 数组， -1 代表没有遍历
        //1左移buttons位相当于2^buttons
        vector<vector<int>> dp(1 << buttons, vector<int>(buttons, -1));
        //当只有一种位置的时候,
        for(int i=0;i<buttons;i++){
            dp[1<<i][i]=button_dist[i][buttons];
        }
        //状态逐渐变化,这里开始求M1-MN的最断距离
        for(int mask=1;mask<(1<<buttons);mask++){
            for(int i=0;i<buttons;i++){
                //当前dp是合法的，结尾状态为i，即i不包含在mask中的话
                if (mask & (1 << i)) {
                    for (int j = 0; j < buttons; j++) {
                        // j 不在 mask 里
                        if (!(mask & (1 << j))) {
                            int next = mask | (1 << j);
                            if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + button_dist[i][j]) {
                                dp[next][j] = dp[mask][i] + button_dist[i][j];
                            }
                        }
                    }
                }

 
            }
        }
        //加上到达终点的值，找出最小的cost即可
        int ret = -1;
        //找到最后的状态
        int final_mask = (1 << buttons) - 1;
        for (int i = 0; i < buttons; i++) {
            if (ret == -1 || ret > dp[final_mask][i] + button_dist[i][buttons + 1]) {
                ret = dp[final_mask][i] + button_dist[i][buttons + 1];
            }
        }
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>nums={"S#O", "M..", "M.T"};
    cout<<s.minimalSteps(nums);
    return 0;
}
