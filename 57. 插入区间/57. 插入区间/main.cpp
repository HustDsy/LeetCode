//
//  main.cpp
//  57. 插入区间
//
//  Created by 董深育 on 2020/11/4.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int nx=newInterval[0];
        int ny=newInterval[1];
        vector<vector<int>>ans;
        bool placed=false;
        for(const vector<int>&item:intervals){
            //在右边无交集
            if(item[0]>ny){
                if(!placed){
                    ans.push_back({nx, ny});
                    placed = true;
                }
                ans.push_back(item);
            }else if(item[1]<nx){//在左边无交集
                ans.push_back(item);
            }else{//有交集
                nx=min(nx,item[0]);
                ny=max(ny,item[1]);
            }
        }
        if(!placed){
            ans.push_back({nx,ny});
        }
        return  ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
