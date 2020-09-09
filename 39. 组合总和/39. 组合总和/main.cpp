//
//  main.cpp
//  39. 组合总和
//
//  Created by 董深育 on 2020/8/19.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>ret;
    vector<int>temp;
    void getRet(vector<int>& candidates,int currNum,int curr) {
        if(currNum==0){
            ret.push_back(temp);
            return;
        }
        for(int i=curr;i<candidates.size();i++){
            if(currNum<candidates[i]){
                break;
            }
            temp.push_back(candidates[i]);
            getRet(candidates, currNum-candidates[i], i);
            temp.pop_back();

        }
            
      }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0){
            return {};
        }
        sort(candidates.begin(),candidates.end());
        getRet(candidates, target, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> candidates={2,3,6,7};
    s.combinationSum(candidates, 7);
    return 0;
}
