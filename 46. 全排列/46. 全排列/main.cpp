//
//  main.cpp
//  46. 全排列
//
//  Created by 董深育 on 2020/8/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    void dfs(int len,vector<int>&nums,vector<int>flag){
        if(len==temp.size()){
            ret.emplace_back(temp);
            return;
        }
        for(int k=0;k<len;k++){
            if(flag[k]==0){
                flag[k]=1;
                temp.push_back(nums[k]);
                dfs(len,nums,flag);
                temp.pop_back();
                flag[k]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len=static_cast<int>(nums.size());
        if(len==0){
            return {};
        }
        vector<int>flag(len,0);
        dfs(len,nums,flag);
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
