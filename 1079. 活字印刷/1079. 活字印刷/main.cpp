//
//  main.cpp
//  1079. 活字印刷
//
//  Created by 董深育 on 2020/8/25.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int nums=0;
    //flag 用来标记是否被访问过
    //原字符串 tiles
    //kk 当前所求字符串
    //len 当前长度
    void getNums(vector<int>flag,string tiles,string kk,int len){
        //满足长度的话，nums+1
        if(kk.length()==len){
            nums+=1;
            return;
        }
        for(int i=0;i<static_cast<int>(tiles.length());i++){
            if(flag[i]==0){
                //当i和i-1相等的时候 如果i-1被访问的话 那个这个i就不访问了
                //如果flag[i-1]等于0的话 说明 flag[i-1]在这一层已经被调用了 而且更新了
                //如果flag[i-1]等于1的话 说明flag[i-1]正在走这个分支 那么就是可以访问的
                //这样子的话 这一层就不再添加重复的元素了
                if(i>0&&tiles[i]==tiles[i-1]&&flag[i-1]==0){
                    continue;
                }
                kk+=tiles[i];
                flag[i]=1;
                getNums(flag, tiles, kk, len);
                kk.pop_back();
                flag[i]=0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        for(int i=0;i<tiles.length();i++){
            string kk;
            vector<int>flag(tiles.length(),0);
            getNums(flag, tiles, kk, i+1);
        }
        return nums;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    int k=s.numTilePossibilities("AAB");
    return 0;
}
