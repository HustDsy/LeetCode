//
//  main.cpp
//  387. 字符串中的第一个唯一字符
//
//  Created by dsy on 2020/12/23.
//

#include <iostream>
#include<string>
using namespace std;



class Solution {
public:
    int firstUniqChar(string s) {
        int dp[26]={0};
        for(int i=0;i<s.length();i++){
            dp[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(dp[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
