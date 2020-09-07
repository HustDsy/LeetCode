//
//  main.cpp
//  347. 前 K 个高频元素
//
//  Created by 董深育 on 2020/9/7.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    void sort(vector<pair<int, int>>&ret,int begin,int end){
        if(begin>end){
            return;
        }
        int mid=ret[end].second;
        int left=begin;
        int right=end-1;
        while(left<right){
            while(ret[left].second<mid&&left<right) left++;
            while(ret[right].second>=mid&&left<right) right--;
            pair<int,int>temp=ret[left];
            ret[left].first=ret[right].first;
            ret[left].second=ret[right].second;
            ret[right].first=temp.first;
            ret[right].second=temp.second;
        }
        if(ret[left].second>=ret[end].second){
            pair<int,int>temp=ret[left];
            ret[left].first=ret[end].first;
            ret[left].second=ret[end].second;
            ret[end].first=temp.first;
            ret[end].second=temp.second;
        }else{
            left++;
        }
        sort(ret,begin,left-1);
        sort(ret,left+1,end);
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size=static_cast<int>(nums.size());
        if(size==0){
            return {};
        }
        unordered_map<int, int>map;
        for(int i=0;i<size;i++){
            map[nums[i]]+=1;
        }
        int len=static_cast<int>(map.size());
        vector<pair<int,int>>ret;
        unordered_map<int,int>::iterator map_iter;
        //first是值,second是出现的次数，根据次数排序就好
        for(map_iter=map.begin();map_iter!=map.end();map_iter++){
            ret.push_back(make_pair(map_iter->first, map_iter->second));
        }
        sort(ret, 0, len-1);
        vector<int>cnt;
        for(int i=len-1;i>=len-k;i--){
            cnt.push_back(ret[i].first);
        }
        return cnt;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums={4,1,-1,2,-1,2,3};
    s.topKFrequent(nums, 2);
    return 0;
}
