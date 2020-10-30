//
//  main.cpp
//  463. 岛屿的周长
//
//  Created by 董深育 on 2020/10/30.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
           int ans=0;
           int row=static_cast<int>(grid.size());
           if(row==0)return 0;
           int len=static_cast<int>(grid[0].size());
           for(int i=0;i<row;i++){
               for(int j=0;j<len;j++){
                   if(grid[i][j]){
                       //上
                       if(i>0){
                           ans=ans+(grid[i-1][j]==0);
                       }
                       //下
                       if(i<row-1){
                           ans=ans+(grid[i+1][j]==0);
                       }
                       //左
                       if(j>0){
                           ans=ans+(grid[i][j-1]==0);
                       }
                       //右
                       if(j<len-1){
                           ans=ans+(grid[i][j+1]==0);
                       }
                       if(i==0){
                           ans++;
                       }
                       if(i==row-1){
                           ans++;
                       }
                       if(j==0){
                           ans++;
                       }
                       if(j==len-1){
                           ans++;
                       }
                       
                       
                   }
               }
           }
           return ans;
       }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
