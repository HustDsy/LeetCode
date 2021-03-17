//
//  main.cpp
//  剑指 Offer 46. 把数字翻译成字符串
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int res;
    Solution(){}
    void dfs(string s,int start,int len){
        if(start==len){
            res++;
            return;
        }
        for(int l=1;l<=2;l++){
            if(l+start>len) continue;
            if(s[start]=='0'&&l==2) continue;
            int cur=stoi(s.substr(start,l));
            if(cur>25)continue;
            dfs(s,start+l,len);
        }

    }
    int translateNum(int num) {
        res=0;
        string s=to_string(num);
        int len=s.length();
        dfs(s,0,len);
        return res;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    s.translateNum(12258);
    std::cout << "Hello, World!\n";
    return 0;
}
