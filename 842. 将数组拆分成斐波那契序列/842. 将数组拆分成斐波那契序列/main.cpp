//
//  main.cpp
//  842. 将数组拆分成斐波那契序列
//
//  Created by 董深育 on 2020/9/30.
//

#include <iostream>
#include<vector>
using  namespace std;

class Solution {
public:
    vector<int>ret;
    bool dfs(int begin,string S){
        int size=(int)ret.size();
        if(begin==S.length()){
            if(size<3)
                return false;
            return (ret[size-1]-ret[size-2])==ret[size-3];
            
        }
        for(int j=begin;j<S.length();j++){
            if(j!=begin&&S[begin]=='0')break;
            long num=stol(S.substr(begin,j-begin+1));
            if(num>(pow(2, 31) - 1)) break;
            if(size>=2&& (num-ret[size-1])!=ret[size-2]){
                continue;
            }
            ret.push_back((int)num);
            if(dfs(j+1,S)) return true;
            ret.pop_back();
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        dfs(0,S);
        return ret;

    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.splitIntoFibonacci("123456579");
    return 0;
}
