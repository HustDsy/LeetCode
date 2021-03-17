//
//  main.cpp
//  剑指 Offer 48. 最长不含重复字符的子字符串
//
//  Created by dsy on 2021/2/27.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=1;
        int l=s.length();
        if(!l) return 0;
        int dp[10000]={0};
        dp[s[0]]=1;
        int ans=1;
        while(j<l){
            //窗口右边滑动
            while(j<l&&!dp[s[j]]){
                dp[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
            //现在说明j重复了 i右移 消除重复
            while(i<j&&dp[s[j]]){
                dp[s[i]]--;
                i++;
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
