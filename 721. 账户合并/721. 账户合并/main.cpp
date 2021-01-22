//
//  main.cpp
//  721. 账户合并
//
//  Created by dsy on 2021/1/18.
//

#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //并查集
    vector<int>parent;
    int kinds;
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void uion(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            parent[px]=py;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //账户映射成姓名
        unordered_map<string,string>a_to_u;
        //将账户映射成int
        unordered_map<string, int>a_to_i;
        //int to i
        unordered_map<int, string>i_to_a;
        //初始化账户
        int cnt=0;
        for(auto&a:accounts){
            string name=a[0];
            int size=static_cast<int>(a.size());
            for(int i=1;i<size;i++){
                a_to_u[a[i]]=name;
                if(!a_to_i.count(a[i])){
                    a_to_i[a[i]]=cnt;
                    i_to_a[cnt]=a[i];
                    cnt++;
                }
            }
        }
        parent=vector<int>(cnt,0);
        kinds=cnt;
        for(int i=0;i<cnt;i++){
            parent[i]=i;
        }
        for(auto&a:accounts){
            int size=static_cast<int>(a.size());
            for(int i=1;i<size-1;i++){
                if(i==size-1){
                    continue;
                }
                uion(a_to_i[a[i]],a_to_i[a[i+1]]);
                kinds--;
            }
        }
        unordered_map<int, vector<string>>res_;
        //计算root
        for(int i=0;i<cnt;i++){
            string s=i_to_a[i];
            int px=find(i);
            if(res_[px].empty()){
                res_[px].emplace_back(a_to_u[s]);
            }
            res_[px].emplace_back(s);
        }
        //vector<vector<string>>ans;
        int num=static_cast<int>(res_.size());
        vector<vector<string>>ans(num);
        int cur=0;
        for(auto&[k,v]:res_){
            sort(v.begin()+1, v.end());
            ans[cur++]=v;
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string> >accounts={{"Ethan","Ethan1@m.co","Ethan2@m.co","Ethan0@m.co"},{"David","David1@m.co","David2@m.co","David0@m.co"},{"Lily","Lily0@m.co","Lily0@m.co","Lily4@m.co"},{"Gabe","Gabe1@m.co","Gabe4@m.co","Gabe0@m.co"},{"Ethan","Ethan2@m.co","Ethan1@m.co","Ethan0@m.co"}};
    s.accountsMerge(accounts);
    return 0;
};
