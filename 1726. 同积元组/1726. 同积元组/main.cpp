//
//  main.cpp
//  1726. 同积元组
//
//  Created by dsy on 2021/1/22.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
//    int K;
//    vector<int>trace;
//    //begin 开始的数字
//    //len num数组的长度
//    void dfs(vector<int>&trace,int begin,vector<int>&nums,int len){
//        for(int i=begin;i<len;i++){
//            trace.push_back(nums[i]);
//            int size=trace.size();
//            if(size==4){
//                //判断满足不满足要求
//                K=trace[0]*trace[3]==trace[1]*trace[2]||trace[0]*trace[2]==trace[1]*trace[3]?K+1:K;
//                if(trace[0]*trace[3]>trace[1]*trace[2]&&trace[0]*trace[2]<trace[1]*trace[3]){
//                    return;
//                }
//                continue;
//            }
//            if(len-i-1<4-size){
//                return;
//            }
//            dfs(trace,i+1,nums,len);
//            trace.pop_back();
//        }
//    }
//    int tupleSameProduct(vector<int>& nums) {
//        K=0;
//        int len=nums.size();
//        sort(nums.begin(),nums.end());
//        dfs(trace,0,nums,len);
//        return 8*K;
//    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> um;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                um[nums[i] * nums[j]]++;
            }
        }
        
        int res = 0;
        for (auto& [k, v] : um) {
            if (v <= 1) continue;
            res += v * (v-1) / 2 * 8;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={1,2,4,5,10};
    s.tupleSameProduct(nums);
    return 0;
}
