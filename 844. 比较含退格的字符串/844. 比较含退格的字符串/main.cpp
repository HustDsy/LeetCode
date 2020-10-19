//
//  main.cpp
//  844. 比较含退格的字符串
//
//  Created by 董深育 on 2020/10/19.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    //辅助栈写法
    string getS(string&s){
        string rs="";
        int len=(int)s.length();
        stack<char>nums;
        if(len==0)return rs;
        for(int i=0;i<len;i++){
            if(s[i]!='#'){
                nums.push(s[i]);
            }else{
                if(nums.empty()){
                    continue;
                }else{
                    nums.pop();
                }
            }
        }
        while(!nums.empty()){
            rs=nums.top()+rs;
            nums.pop();
        }
        return rs;
    }
    bool backspaceCompare(string S, string T) {
        return getS(S)==getS(T);
    }

    
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.backspaceCompare("a#c","b");
    return 0;
}
