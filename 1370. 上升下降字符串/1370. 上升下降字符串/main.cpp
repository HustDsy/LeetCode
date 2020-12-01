//
//  main.cpp
//  1370. 上升下降字符串
//
//  Created by 董深育 on 2020/11/26.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        if(s.length()==0||s.length()==1){
            return s;
        }
        vector<int>dp(26,0);
        string ans;
        for(int i=0;i<s.length();i++){
            dp[s[i]-'a']++;
        }
        while(ans.size()<s.size()){
            for(int i=0;i<26;i++){
                if(dp[i]){
                    ans=ans+char('a'+i);
                    dp[i]--;
                }
            }
            for(int i=25;i>=0;i--){
                if(dp[i]){
                    ans=ans+char('a'+i);
                    dp[i]--;
                }
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
