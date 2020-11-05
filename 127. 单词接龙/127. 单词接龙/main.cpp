//
//  main.cpp
//  127. 单词接龙
//
//  Created by 董深育 on 2020/11/5.
//

#include <iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    inline bool isTrue(string a,string b,int len){
        int diffnum=0;
        if(a==b)return false;
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                diffnum++;
            }
            if(diffnum>1){
                return false;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()) return 0;
        int len=static_cast<int>(beginWord.length());
        int wlen=static_cast<int>(wordList.size());
        queue<int>trace;
        trace.push(-1);
        int ans=0;
        vector<int>flag(wlen,0);
        int target=-1;
        //建立一个表，设置这个单词 对应的差一的数，这样子就不用每次都遍历了
        vector<vector<int>>dp(wlen,vector<int>());
        for(int i=0;i<wlen;i++){
            if(wordList[i]==endWord){
                target=i;
            }
            for(int j=i+1;j<wlen;j++){
                if(isTrue(wordList[i], wordList[j],len)){
                    dp[i].push_back(j);
                    dp[j].push_back(i);
                }
            }
        }
        vector<int>bp;
        for(int i=0;i<wlen;i++){
            if(isTrue(wordList[i], beginWord, len)){
                bp.push_back(i);
            }
        }
        while(!trace.empty()){
            int size=static_cast<int>(trace.size());
            ans++;
            while(size>0){
                int top=trace.front();
                trace.pop();
                //如果是beginword的话
                if(top==-1){
                    for(int i=0;i<bp.size();i++){
                        trace.push(bp[i]);
                        flag[bp[i]]=1;
                        if(bp[i]==target){
                            return ++ans;
                        }
                    }
                }else{
                    for(int i=0;i<dp[top].size();i++){
                        if(!flag[dp[top][i]]){
                            flag[dp[top][i]]=1;
                            trace.push(dp[top][i]);
                            if(dp[top][i]==target){
                                return ++ans;
                            }
                        }
                    }
                }
                size--;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>wordList={"a","b","c"};
    cout<<s.ladderLength("a","c" ,wordList );
    return 0;
}
