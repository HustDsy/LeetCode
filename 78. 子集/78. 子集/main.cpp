//
//  main.cpp
//  78. 子集
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //逐渐递增
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;
        int len=(int)nums.size();
        if(len==0){
            return {};
        }
        ret.push_back({});
        for(int i=0;i<nums.size();i++){
            int curSize=(int)ret.size();
            for(int j=0;j<curSize;j++){
                vector<int>temp=ret[j];
                temp.push_back(nums[i]);
                ret.push_back(temp);
            }
            
        }
        return ret;
    }
    //回溯算法
    vector<vector<int>>ret;
    void getSub(int first,vector<int>& nums,int num,vector<int>&path){
        if(path.size()==num){
            ret.push_back(path);
            return;
        }
        for(int i=first;i<nums.size();i++){
            path.push_back(nums[i]);
            getSub(i+1, nums, num, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets_(vector<int>& nums) {
 
        int size=(int)nums.size();
        for(int i=0;i<=size;i++){
            vector<int>path;
            getSub(0, nums, i,path );
            
        }
        return ret;
    
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
