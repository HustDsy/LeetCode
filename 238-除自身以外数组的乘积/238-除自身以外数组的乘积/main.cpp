//
//  main.cpp
//  238-除自身以外数组的乘积
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=(int)nums.size();
        if(len==0){
            return {};
        }
        vector<int>ret(len,0);
        vector<int>left(len,0);
        vector<int>right(len,0);
        left[0]=1;
        for(int i=1;i<len;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        right[len-1]=1;
        for(int i=len-2;i>=0;i--){
            right[i]=nums[i+1]*right[i+1];
        }
        for(int i=0;i<len;i++){
            ret[i]=left[i]*right[i];
        }
        return ret;
    }
    //常数
    vector<int> productExceptSelf_Const(vector<int>& nums) {
        int len=(int)nums.size();
        if(len==0){
            return {};
        }
        vector<int>ret(len,0);
        //构造左侧乘积
        ret[0]=1;
        for(int i=1;i<len;i++){
            ret[i]=nums[i-1]*ret[i-1];
        }
        //构造右侧乘ji
        int R=1;
        for(int i=len-1;i>=0;i--){
            ret[i]=R*ret[i];
            R=R*nums[i];
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>num={1,2,3,4};
    Solution s;
    vector<int>ret=s.productExceptSelf(num);
    return 0;
}
