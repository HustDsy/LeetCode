//
//  main.cpp
//  696. 计数二进制子串
//
//  Created by 董深育 on 2020/8/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    //暴力法超时
    int countBinarySubstrings(string s) {
        int len=(int)s.length();
        int count=0;
        if(len<=1){
            return 0;
        }
        for(int i=0;i<len;i++){
            int zero=0;
            int one=0;
            if(s[i]-'0'==1){
                one=1;
            }else{
                zero=1;
            }
            int j=i+1;
            while(j<len&&s[j]==s[i]){
                if(s[j]-'0'==1){
                    one+=1;
                }else{
                    zero+=1;
                }
                j++;
            }
            while(j<len&&s[j]!=s[i]){
                if(s[j]-'0'==1){
                    one+=1;
                }else{
                    zero+=1;
                }
                j++;
                if(zero==one){
                    count++;
                    break;
                }
            }

        }
        return count;
    }
    //字符串分组
    int countBinarySubstrings_(string s) {
        vector<int>ss;
        int len=(int)s.length();
        int count=0;
        if(len<=1){
            return 0;
        }
        char pre=s[0];
        int k=0;
        for(int i=0;i<len;i++){
            if(s[i]==pre){
                k++;
            }else{
                pre=s[i];
                i--;
                ss.push_back(k);
                k=0;
            }
        }
        ss.push_back(k);
        for(int i=1;i<ss.size();i++){
            count+=min(ss[i-1],ss[i]);
        }
        return count;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    s.countBinarySubstrings_("00110");
    std::cout << "Hello, World!\n";
    return 0;
}
