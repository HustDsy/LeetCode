//
//  main.cpp
//  485. 最大连续 1 的个数
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0;
        int t=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==1){
                t++;
            }else{
                cur=max(cur,t);
                t=0;
            }
        }
        cur=max(cur,t);
        return cur;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
