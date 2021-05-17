//
//  main.cpp
//  1838. 最高频元素的频数
//
//  Created by dsy on 2021/5/13.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int n=nums.size();
        int l=0;//左边界
        long long total=0;
        for(int r=1;r<n;r++){
            //都变为i看看有多少种情况,r-l代表这个区间有多少个数
            //每次for循环l-r-1中的树 全变为了nums[r-1]
            total+=(long long)(nums[r]-nums[r-1])*(r-l);
            while(total>k){
                //当total大于k的时候左边界需要进行收缩
                total-=nums[r]-nums[l];
                l++;
            }
            ans=max(ans,r-l+1);

        }
        return ans;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
