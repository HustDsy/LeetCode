//
//  main.cpp
//  1202. 交换字符串中的元素
//
//  Created by dsy on 2021/1/11.
//

#include <iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//
////    void clear(queue<int>& q) {
////        queue<int> empty;
////        swap(empty, q);
////    }
//    //BFS，时间超时 我一点办法都没有
//    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//        string tt(s);
//        int len=(int)s.length();
//        vector<vector<int>>memo(len);
//        for(auto&it:pairs){
//            memo[it[0]].push_back(it[1]);
//            memo[it[1]].push_back(it[0]);
//
//        }
//        //开始BFS
//        vector<int>flag(len,0);
//        int size=0;
//        vector<int>temp;
//        vector<int>temp_;
//        queue<int>help;
//        for(auto&it:pairs){
//            if(flag[it[0]]) continue;
//            temp.clear();
//            temp_.clear();
//           // clear(help);
//            help.push(it[0]);
//            flag[it[0]]=1;
//            while(!help.empty()){
//                size=help.size();
//                while(size>0){
//                    int front=help.front();
//                    //temp_.push(front);
//                    temp.emplace_back(front);
//                    for(int it:memo[front]){
//                        if(!flag[it]){
//                            help.push(it);
//                            flag[it]=1;
//                        }
//                    }
//                    help.pop();
//                    size--;
//                }
//            }
//
//            //记录交换之前的位置
//            sort(temp.begin(),temp.end());
//            temp_=temp;
//            sort(temp.begin(), temp.end(),[s](int a,int b)->bool{
//                return s[a]<s[b];
//            });
//
//            for(int i=0;i<temp.size();i++){
//                tt[temp_[i]]=s[temp[i]];
//            }
//        }
//        return tt;
//    }
//};
class uion{
public:
    vector<int>parent;//记录根节点
    vector<int>rank;//记录树的高度
    uion(int n){
        for(int i=0;i<n;i++){
            parent.emplace_back(i);
            rank.emplace_back(0);
        }
    }
    //路径压缩
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    //路径不压缩，单纯找父节点
    int find_(int x){
        int temp=x;
        while(temp!=parent[temp]){
            temp=parent[temp];
        }
        return temp;
    }
    
    void merge(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry]){
                swap(rx,ry);
            }
            parent[ry]=rx;
            if(rank[rx]==rank[ry]) rank[rx]++;
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>>dp;
        int len=s.length();
        uion u(len);
        for(const auto&pair:pairs){
            u.merge(pair[0],pair[1]);
        }
        for(int i=0;i<len;i++){
            dp[u.find(i)].emplace_back(s[i]);
        }
        for(auto&[x,vec]:dp){
            sort(vec.begin(),vec.end(),greater<int>());
        }
        
        for(int i=0;i<len;i++){
            int x=u.find(i);
            s[i] = dp[x].back();
            dp[x].pop_back();
        }
        return s;
    }
};
  

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int> > pairs={{0,3},{1,2}};
    s.smallestStringWithSwaps("dcab", pairs);
    return 0;
}
