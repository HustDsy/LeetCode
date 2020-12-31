//
//  main.cpp
//  435. 无重叠区间
//
//  Created by dsy on 2020/12/31.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)->bool{
            return a[1]<b[1];
        });
        int count=1;
        //记录第一个位置的end端
        int x=intervals[0][1];
        for(vector<int>&nums:intervals){
            int start=nums[0];
            if(start>=x){
                count++;
                x=nums[1];
            }
        }
        return (int)intervals.size()-count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
