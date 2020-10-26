//
//  main.cpp
//  1365. 有多少小于当前数字的数字
//
//  Created by 董深育 on 2020/10/26.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>cnt(101,0);
        vector<int>ret;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
            ans=max(ans,nums[i]);
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        for(int i=0;i<nums.size();i++){
            ret.push_back(nums[i]==0?0:cnt[nums[i]-1]);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
