//
//  main.cpp
//  40. 组合总和 II
//
//  Created by 董深育 on 2020/8/19.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>trace;
    vector<vector<int>>ret;
    void getRet(vector<int>& candidates, int target,int begin){
        if(target==0){
            ret.push_back(trace);
            return;
        }
        for(int i=begin;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            //i>begin 同一层不出现相同的元素 但是不同的层可以使用相同的元素
            if(i>begin&&candidates[i]==candidates[i-1]){
                continue;
            }
            trace.push_back(candidates[i]);
            getRet(candidates, target-candidates[i], i+1);
            trace.pop_back();
        }
        
    }
    vector<vector<int>>combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n=(int)candidates.size();
        if(n==0){
            return {};
        }
        getRet(candidates, target, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>candidates={10,1,2,7,6,1,5};
    s.combinationSum2(candidates, 8);
    return 0;
}
