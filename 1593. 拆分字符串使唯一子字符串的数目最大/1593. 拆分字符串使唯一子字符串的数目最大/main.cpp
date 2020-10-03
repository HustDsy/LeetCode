//
//  main.cpp
//  1593. 拆分字符串使唯一子字符串的数目最大
//
//  Created by 董深育 on 2020/10/3.
//

#include <iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<string>ret;
    int ans=0;
    void dfs(string&s,int i){
        if(s.size()-i+ret.size()<=ans) return;
        if(i==s.length()){
            ans=max(ans,(int)ret.size());
            return;
        }
        for(int begin=i;begin<s.length();begin++){
            string temp=s.substr(i,begin-i+1);
            if(ret.find(temp)!=ret.end()){
                continue;
            }
            ret.insert(temp);
            dfs(s,begin+1);
            ret.erase(temp);
        }
        
        
    }
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
