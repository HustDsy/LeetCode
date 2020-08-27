//
//  main.cpp
//  332. 重新安排行程
//
//  Created by 董深育 on 2020/8/27.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;



class Solution {
public:
    //先做dfs，将所有满足提条件的路径 找出来
    //把路径放在vector，之后排序 即可
    vector<string>path;
    vector<string>ret;
    //cur 记录现在的起点
    //flag 记录车票是否被用过了
    //tickets 记录所有的车票
    //kk 记录当前使用了多少张票
    //row 记录一共有多少张票
    bool dfs(string cur,vector<int>flag,vector<vector<string>>& tickets,int kk,int row,string trace){
        //这是一个有效的行程
        if(kk==row){
            path.emplace_back(trace);
            return true;
        }
        for(int i=0;i<row;i++){
            if(flag[i]==0&&tickets[i][0]==cur){
                flag[i]=1;
                if(kk+1==row){
                    cur=tickets[i][0]+tickets[i][1];
                }
                if(dfs(tickets[i][1],flag,tickets,kk+1,row,trace+cur)){
                    return true;
                };
                flag[i]=0;
            }
        }
        return false;
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int row=static_cast<int>(tickets.size());
        if(row==0){
            return {};
        }
        vector<int>flag(row,0);
        //对ticket排序，使得第二小的放在前面
        for(int i=1;i<row;i++){
            for(int j=0;j<row-i;j++){
                if(tickets[j][1]>tickets[j+1][1]){
                    string kk0=tickets[j][0];
                    string kk1=tickets[j][1];
                    tickets[j][0]=tickets[j+1][0];
                    tickets[j][1]=tickets[j+1][1];
                    tickets[j+1][0]=kk0;
                    tickets[j+1][1]=kk1;
                }
            }
        }
//        for(int i=0;i<row;i++){
//            cout<<tickets[i][0]<<" "<<tickets[i][1]<<endl;
//        }

        dfs("JFK",flag,tickets,0,row,"");
        sort(path.begin(), path.end());
        for(int i=0;i<path[0].size();i++){
            if((i+1)%3==0){
                string kk=path[0].substr(i-2,3);
                ret.emplace_back(kk);
            }
        }
        return ret;;
    }
    
    //欧拉回路
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

        vector<string> stk;

        void dfs(const string& curr) {
            while (vec.count(curr) && vec[curr].size() > 0) {
                string tmp = vec[curr].top();
                vec[curr].pop();
                dfs(move(tmp));
            }
            stk.emplace_back(curr);
        }

        vector<string> findItinerary_(vector<vector<string>>& tickets) {
            for (auto& it : tickets) {
                vec[it[0]].emplace(it[1]);
            }
            dfs("JFK");

            reverse(stk.begin(), stk.end());
            return stk;
        }

};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string> >tickets={{"JFK","AAA"},{"JFK","BBB"},{"BBB","JFK"}};
    vector<string>test=s.findItinerary_(tickets);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<endl;
    }
    return 0;
}
