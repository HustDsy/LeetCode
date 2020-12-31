//
//  main.cpp
//  330. 按要求补齐数组
//
//  Created by dsy on 2020/12/30.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        long x=1;
        int len=nums.size();
        int index=0;
        while(x<=n){
            if(index<len&&nums[index]<=x){
                x+=nums[index];
                index++;
            }else{
                x=x*2;
                ans++;
            }
        }
        return ans;
    }
};





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
