//
//  main.cpp
//  3-无重复字符的最长子串
//
//  Created by 董深育 on 2020/6/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int beginIndex=0;
        int endIndex=0;
        int length=s.size();
        int max=1;
        string temp="";
        for(int i=1;i<length;i++){
            temp=s.substr(beginIndex,endIndex+1-beginIndex);
            int index=temp.find(s[i]);
            if(index==-1){
                endIndex=endIndex+1;
                max=(max>(endIndex-beginIndex+1))?max:(endIndex-beginIndex+1);
            }else{
                beginIndex+=index+1;
                endIndex=i;
            }
          
        }
        return max;
    }
};


int main(int argc, const char * argv[]) {
    string s="bbtablud";
    Solution s1;
    cout<<s1.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
