//
//  main.cpp
//  643. 子数组最大平均数 I
//
//  Created by dsy on 2021/2/4.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int p=0;
        int q=0;
        int n=nums.size();
        int ans=INT_MIN;
        int cur=0;
        for(int i=0;i<n;i++){
            if(i>=k){
                p=i;
                q=i-k;
                cur=cur+nums[p]-nums[q];
                ans=max(cur,ans);
                continue;
            }
            cur+=nums[i];
            ans=cur;
        }
        ans=max(cur,ans);
        return double(ans)/k;

    }
};
int main(int argc, const char * argv[]) {
    // insert code her
    Solution s;
    vector<int> nums={7,4,5,8,8,3,9,8,7,6};
    cout<<s.findMaxAverage(nums, 7);
    return 0;
}
