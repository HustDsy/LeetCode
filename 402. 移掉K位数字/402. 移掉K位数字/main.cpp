//
//  main.cpp
//  402. 移掉K位数字
//
//  Created by 董深育 on 2020/11/16.
//


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>s;
        int tt=(int)num.length()-k;
        for(char&it:num){
            while(s.size()>0&&s.back()>it&&k){
                s.pop_back();
                k--;
            }
            s.push_back(it);
        }
        for(;k>0;k--){
            s.pop_back();
        }
        //遍历vector ，保留前n个数
        
        string ans="";
        int cnt=0;
        for(char&it:s){
            if(it!='0'||ans.size()!=0){
                ans+=it;
                cnt++;
            }
            if(cnt==tt){
                break;
            }
        }
        return ans==""?"0":ans;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.removeKdigits("10200", 1);
    return 0;
}
