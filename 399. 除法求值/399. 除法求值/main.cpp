//
//  main.cpp
//  399. 除法求值
//
//  Created by dsy on 2021/1/6.
//

#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //unordered_map 建立映射
        unordered_map<string, int>maps;
        int cnt=0;//一一对应
        for(const auto&it:equations){
            if(!maps.count(it[0])){
                maps[it[0]]=cnt;
                cnt++;
            }
            if(!maps.count(it[1])){
                maps[it[1]]=cnt;
                cnt++;
            }
        }
        //记录每个点的相邻节点
        unordered_map<int, vector<int>>memo;
        //建立图
        vector<vector<double>>graph(cnt,vector<double>(cnt,-2));
        //初始化图
        for(int i=0;i<cnt;i++){
            graph[i][i]=1;
        }
        int i=0;
        for(auto&it:equations){
            graph[maps[it[0]]][maps[it[1]]]=values[i];
            graph[maps[it[1]]][maps[it[0]]]=(double)(1/values[i]);
            memo[maps[it[0]]].push_back(maps[it[1]]);
            memo[maps[it[1]]].push_back(maps[it[0]]);
            i++;
        }
      
        //计算结果
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            //不存在的话 直接给出-1
            if(maps.count(queries[i][0])==0||maps.count(queries[i][1])==0){
                ans.push_back((double)-1);
                continue;
            }
            //是否已经记录了
            int first=maps[queries[i][0]];
            int second=maps[queries[i][1]];
            if(graph[first][second]!=-2){
                ans.push_back(graph[first][second]);
                continue;
            }
            //没记录，BFS
            queue<int>bfs;
            vector<int>flag(cnt,0);
            bfs.push(first);
            while(!bfs.empty()){
                int size=bfs.size();
                while(size>0){
                    int cur=bfs.front();
                    flag[cur]=1;
                    vector<int>temp=memo[cur];
                    for(int i=0;i<temp.size();i++){
                        if(flag[temp[i]]){
                            continue;
                        }
                        bfs.push(temp[i]);
                        graph[first][temp[i]]=graph[first][cur]*graph[cur][temp[i]];
                        graph[temp[i]][first]=1/ graph[first][temp[i]];
                    }
                    bfs.pop();
                    size--;
                }
            }
            graph[first][second]=graph[first][second]==-2?-1:graph[first][second];
            ans.push_back(graph[first][second]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<string>>equations={{"a","b"},{"b","c"}};
    vector<double>values={2.0,3.0};
    vector<vector<string>>queries={{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    s.calcEquation(equations, values, queries);
    return 0;
}
