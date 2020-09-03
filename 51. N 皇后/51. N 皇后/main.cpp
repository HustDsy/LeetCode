//
//  main.cpp
//  51. N 皇后
//
//  Created by 董深育 on 2020/9/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<string>>ret;
    vector<string>temp;
    //row记录一下现在到第几行了
    //flag标记着这个j有没有被访问
    //isvisited用来判断斜线有无攻击
    inline vector<pair<int,int>>getSlash(int n,int xx,int yy){
        int tempx=xx;
        int tempy=yy;
        //左上角斜线
        vector<pair<int,int>>slash;
        while(tempx>0&&tempy>0){
            tempx=tempx-1;
            tempy=tempy-1;
            slash.emplace_back(make_pair(tempx, tempy));
        }
        //右上角斜线
        tempx=xx;
        tempy=yy;
        while(tempx>0&&tempy<n-1){
            tempx=tempx-1;
            tempy=tempy+1;
             slash.emplace_back(make_pair(tempx, tempy));
        }
        return slash;
            
    }
    void getRet(int n,int row,vector<int>flag,vector<vector<int>>isVisited){
        //如果i到n了，但是temp还没有满 说明不符合
        if(row==n&&temp.size()!=n){
            return;
        }
        if(temp.size()==n){
            ret.emplace_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            //这个j没有
            if(flag[j]==0){
                flag[j]=1;
                int xx=row;
                int yy=j;
                //上面保证了这个点纵向和横向没有皇后，接下来保证斜线
                vector<pair<int, int>>slashs=getSlash(n, xx, yy);
                bool isHave=true;//判断是否有
                for(int k=0;k<slashs.size();k++){
                    if(isVisited[slashs[k].first][slashs[k].second]==1){
                        isHave=false;
                        break;
                    }
                }
                //如果没有的话，可以把这个点弄进来
                if(isHave){
                    string ss(n,'.');
                    ss[j]='Q';
                    temp.push_back(ss);
                    isVisited[xx][yy]=1;
                    getRet(n, row+1, flag, isVisited);
                    temp.pop_back();
                    isVisited[xx][yy]=0;
                    //成功与否 flag[j]都归位
                    flag[j]=0;
                }else{
                    //如果斜线上有点的话，直接继续操作
                    //成功与否 flag[j]都归位
                    flag[j]=0;
                    continue;
                }
              
            }
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int>flag(n,0);
        vector<vector<int>>isvisited(n,vector<int>(n,0));
        getRet(n, 0, flag, isvisited);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string>>ret=s.solveNQueens(4);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<4;j++){
            cout<<ret[i][j]<<endl;
        }
    }
    return 0;
}
