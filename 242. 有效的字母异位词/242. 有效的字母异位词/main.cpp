//
//  main.cpp
//  242. 有效的字母异位词
//
//  Created by 董深育 on 2020/11/22.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
           int dp[26]={0};
           if(s.length()!=t.length()) return false;
           for(int i=0;i<s.length();i++){
               dp[s[i]-'a']++;
               dp[t[i]-'a']--;
           }
           for(int i=0;i<26;i++){
               if(dp[i]!=0){
                   return false;
               }
           }
           return true;
       }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
