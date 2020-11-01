//
//  main.cpp
//  140. 单词拆分 II
//
//  Created by 董深育 on 2020/11/1.
//

#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;




//class Solution {
//public:
//    //回溯超时了
//    //可以重复使用wordDict中的数字
//    vector<string>ans;
//    //i是s现在的起始位置,len是s的长度，trace指的是现在的已经组成的字符串,wl是字典的长度
//    void dfs(string s,vector<string>& wordDict,int t,int len,string trace,int wl,vector<int>&wls){
//        //当i是len的时候，这个trace符合条件，直接放入结果
//        if(t==len){
//            ans.emplace_back(trace);
//            return;
//        }
//        //可以使用重复的元素，
//        for(int i=0;i<wl;i++){
//            //这时候选中的数字是wordDict[i]
//            string temp=wordDict[i];
//            int tl=wls[i];
//            string st=s.substr(t,tl);
//            //不等于的话 剪枝，直接pass
//            if(st!=temp)continue;
//            //等于的话，将它加到trace
//            dfs(s,wordDict,t+tl,len,trace+" "+st,wl,wls);
//        }
//
//    }
//    vector<string> wordBreak(string s, vector<string>& wordDict) {
//        int len=(int)s.length();
//        int wl=(int)wordDict.size();
//        vector<int>wls;
//        for(auto&i:wordDict){
//            wls.push_back((int)i.length());
//        }
//        dfs(s,wordDict,0,len,"",wl,wls);
//        for(string&it:ans){
//            int l=it.length();
//            it=it.substr(1,l);
//        }
//        return ans;
//    }
//    //换一个回溯
//
//};

class Solution {
public:
    string s;
    map<int, vector<string>> memo;
    vector<string> dict;
    
    vector<string> wordBreak(string s, vector<string> wordDict) {
        this->s=s;
        dict = wordDict;
        return dfs(0);
    }
    
    vector<string> dfs(int start) {
        if (memo.find(start)!=memo.end()) return memo[start];
        if (start >= s.length()) {
            return {" "};
        }
        vector<string> ret;
        for (int i = start + 1; i <= s.length(); i++) {
            string sub = s.substr(start, i-start);
            if (find(dict.begin(),dict.end(),sub)!=dict.end()) {
                vector<string> last = dfs(i);
                for (string l : last) {
                    ret.emplace_back(l!=" " ? sub + " " + l : sub);
                }
            }
        }
        memo[start]=ret;
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordDict={"apple", "pen", "applepen", "pine", "pineapple"};
    s.wordBreak("pineapplepenapple", wordDict);
    return 0;
}
