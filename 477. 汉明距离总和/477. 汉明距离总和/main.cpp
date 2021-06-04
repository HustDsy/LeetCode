//
//  main.cpp
//  477. 汉明距离总和
//
//  Created by dsy on 2021/5/28.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int  ans=0,n=nums.size();
        for(int i=29;i>=0;i--){
            int c=0;
            for(int nu:nums){
                c+=(nu>>i)&1;
            }
            ans+=c*(n-c);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
