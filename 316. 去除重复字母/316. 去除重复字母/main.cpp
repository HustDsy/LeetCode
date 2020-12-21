//
//  main.cpp
//  316. 去除重复字母
//
//  Created by dsy on 2020/12/21.
//

#include <iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>ss;
        int dp[26]={0};
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(dp[c-'a']) continue;
            while(!ss.empty()&&ss.top()>c&&s.find(ss.top(),i)!=-1){
                dp[ss.top()-'a']=0;
                ss.pop();
            }
            dp[c-'a']=1;
            ss.push(c);
        }
        string ans;
        while(!ss.empty()){
            ans=ss.top()+ans;
            ss.pop();
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.removeDuplicateLetters("bcabc");
    return 0;
}
