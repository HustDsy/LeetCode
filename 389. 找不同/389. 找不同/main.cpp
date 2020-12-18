//
//  main.cpp
//  389. 找不同
//
//  Created by dsy on 2020/12/18.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int len_s=s.length();
        int len_t=t.length();
        int dp[26]={0};
        for(int i=0;i<len_s;i++){
            dp[s[i]-'a']+=1;
        }
        for(int i=0;i<len_t;i++){
            if(dp[t[i]-'a']){
                dp[t[i]-'a']--;
            }else{
                return t[i];
            }
        }
        return ' ';
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
