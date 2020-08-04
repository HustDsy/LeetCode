//
//  main.cpp
//  207-课程表
//
//  Created by 董深育 on 2020/8/4.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
  
        
    
    //BFS,判断是不是连通图
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==1||prerequisites.size()==0){
            return true;
        }
        //将邻居放到一起
        vector<int> a[numCourses];
        for(int i=0;i<(int)prerequisites.size();i++){
            a[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<vector<int>>isTrue(numCourses,vector<int>(numCourses,0));
        for(int i=0;i<numCourses;i++){
            //判断改点是否被找到过
            vector<bool>flag(numCourses,false);
            queue<int>myqueue;
            myqueue.push(i);
            while(!myqueue.empty()&&flag[myqueue.front()]==false){
                int top=myqueue.front();
                flag[top]=true;
                vector<int>neighbor=a[top];
                myqueue.pop();
                for(int j=0;j<neighbor.size();j++){
                    isTrue[i][neighbor[j]]=1;
                    if(isTrue[neighbor[j]][i]==1){
                        return false;
                    }
                    myqueue.push(neighbor[j]);
                }
            }
            
        }
   
        return true;
    }
    //top排序
    bool canFinish_TopSort(int numCourses, vector<vector<int>>& prerequisites) {
        //将邻居放到一起,邻接表
        vector<int> a[numCourses];
        vector<int>cur(numCourses,0);
        for(int i=0;i<(int)prerequisites.size();i++){
            a[prerequisites[i][0]].push_back(prerequisites[i][1]);
            cur[prerequisites[i][1]]++;
        }
        queue<int>myqueue;
        for(int i=0;i<numCourses;i++){
            if(cur[i]==0){
                myqueue.push(i);
            }
        }
        while(!myqueue.empty()){
            int temp=myqueue.front();
            myqueue.pop();
            numCourses--;
            for(int i=0;i<a[temp].size();i++){
                cur[a[temp][i]]--;
                if(cur[a[temp][i]]==0){
                    myqueue.push(a[temp][i]);
                }
            }
        }
        return numCourses==0;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>>ret={{1,0},{0,2},{2,1}};
    bool tr=s.canFinish(3, ret);
    std::cout << "Hello, World!\n";
    return 0;
}
