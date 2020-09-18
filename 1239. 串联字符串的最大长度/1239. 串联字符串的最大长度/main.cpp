//
//  main.cpp
//  1239. 串联字符串的最大长度
//
//  Created by 董深育 on 2020/9/18.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    //判断有没有重复
    bool isunique(string kk,vector<int>&m){
        for(int i=0;i<kk.length();i++){
            m[kk[i]-'a']++;
        }
        if(find_if(m.begin(), m.end(), [](int i){return i>1;})!=m.end()){
            return false;
        }
        return true;
    }
    //m用来记录26个字母出现的次数
    int dfs(vector<string>&arr, int index,vector<int>m){
        if(index==arr.size()){
            return 0;
        }
        //加入字符串arr[index]之后m的变化
        vector<int>mm(m);
        if(isunique(arr[index], mm)){
            int curlen=(int)arr[index].length();
            int len1=curlen+dfs(arr,index+1,mm);
            int len2=dfs(arr, index+1, m);
            return max(len1,len2);
        }
        return dfs(arr,index+1,m);
    }
    int maxLength(vector<string>& arr) {
        //记录这个路径中 26个字母出现的次数
        vector<int>m(26,0);
        return dfs(arr,0,m);
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>m(26,0);
    s.isunique("abcd",m);
    return 0;
}
