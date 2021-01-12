//
//  main.cpp
//  228. 汇总区间
//
//  Created by dsy on 2021/1/10.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int len=nums.size();
        if(len==0) return {};
        for(int i=0;i<nums.size();i++){
            int begin=i;
            int end=i;
            while(i<len-1&&nums[i]==nums[i+1]-1){
                end++;
                i++;
            }
            string result;
            if(begin==end){
                result=to_string(begin);
            }else{
                result=to_string(begin)+"->"+to_string(end);
            }
            ans.emplace_back(result);
        }
        return ans;

    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
