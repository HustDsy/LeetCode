//
//  main.cpp
//  179. 最大数
//
//  Created by dsy on 2021/4/12.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b)->bool{
            string sa=to_string(a);
            string sb=to_string(b);
            return sa+sb>sb+sa;
        });
        string ans;
        for(int n:nums){
            ans=ans+to_string(n);
        }
        return ans;
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>nums={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    s.largestNumber(nums);
    return 0;
}
