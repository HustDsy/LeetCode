//
//  main.cpp
//  674. 最长连续递增序列
//
//  Created by dsy on 2021/1/24.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int start=0;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]<=nums[i-1]){
                start=i;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
