//
//  main.cpp
//  126. 单词接龙 II
//
//  Created by dsy on 2021/3/26.
//

#include <iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using  namespace std;

class Solution {
public:
    vector<vector<string>>ss;
    vector<string>temp;
    void dfs(string beginWord,string endWord,int l,unordered_map<string,vector<string>>m,int cur){
        //cur表示用了多少次
        if(cur>l) return;//大于当前的最小次数 return
        if(cur==l&&beginWord==endWord){
            ss.push_back(temp);
            return;
        }
        //如过cur==l 但是temp不一样的话 return;
        if(cur==l) return;
        //开始做选择
     
        for(auto&s:m[beginWord]){
            temp.push_back(s);
            dfs(s,endWord,l,m,cur+1);
            temp.pop_back();
        }
    }
    bool check(string&a,string&b){
        int cur=0;
        if(a.length()!=b.length()){
            return false;
        }
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                cur++;
            }
            if(cur>1) return false;
        }
        return true;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return {};
            if(find(wordList.begin(),wordList.end(),beginWord)==wordList.end()){
                //将begin插入进去
                wordList.push_back(beginWord);
            }
            int n=wordList.size();
            unordered_map<string,vector<string>>m;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(check(wordList[i],wordList[j])){
                        m[wordList[i]].push_back(wordList[j]);
                        m[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
            queue<string>q;
            q.push(beginWord);
            int l=0;
            bool ok=false;
            while(!q.empty()&&!ok){
                l++;
                int cur=q.size();
                while(cur--){
                    string temp=q.front();
                    q.pop();
                    if(temp==endWord){
                        ok=true;
                        break;
                    }
                    //不等于的话 继续广度优先搜索，因为这里是求最小的值，不用flag也可
                    for(auto&s:m[temp]){
                        q.push(s);
                    }
                }
            }
            //dfs构建路径
            temp.push_back(beginWord);
            dfs(beginWord,endWord,l,m,1);
            return ss;
    }

};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "dog", wordList);
    return 0;
}
