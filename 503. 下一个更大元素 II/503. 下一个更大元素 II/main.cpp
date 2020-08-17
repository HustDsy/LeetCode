//
//  main.cpp
//  503. 下一个更大元素 II
//
//  Created by 董深育 on 2020/8/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==0){
            return {};
        }
        if(n==1){
            return {nums[0]};
        }
        vector<int>ret(n,-1);
        stack<pair<int,int>>mypair;
        //顺序的弄了一遍
        for(int i=0;i<=2*n-2;i++){
            int t=(i+1)%n;
            if(mypair.empty()){
                mypair.push(make_pair(t, nums[t]));
            }else{
                while(!mypair.empty()){
                    pair<int,int>top=mypair.top();
                    if(nums[t]>top.second){
                        mypair.pop();
                        if(ret[top.first]==-1){
                            ret[top.first]=nums[t];
                        }
                    }else{
                        break;
                    }
                }
                mypair.push(make_pair(t, nums[t]));
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>ss={-1,-1,-1,-1,5};
    s.nextGreaterElements(ss);
    return 0;
}
