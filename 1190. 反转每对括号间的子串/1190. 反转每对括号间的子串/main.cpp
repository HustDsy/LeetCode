//
//  main.cpp
//  1190. 反转每对括号间的子串
//
//  Created by dsy on 2021/5/26.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;


class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>ss;
        string ans;
        int i=0;
        int len=s.length();
        while(!ss.empty()||i<len){
            char c=s[i++];
            if(c!='('&&c!=')'&&ss.empty()){
                ans.push_back(c);
            }else if(c!=')'){
                ss.push(c);
            }else if(c==')'){
                //开始弹出
                string temp;
                while(!(ss.top()=='(')){
                    temp.push_back(ss.top());
                    ss.pop();
                }
                ss.pop();
                //判断ss是否为空，不为空的话，还要反转
                int j=0;
                if(ss.empty()){
                    ans+=temp;
                }else{
                  while(j<temp.size()){
                      ss.push(temp[j++]);
                  }
                }
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.reverseParentheses("(abcd)");
    return 0;
}
