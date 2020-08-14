//
//  main.cpp
//  739. 每日温度
//
//  Created by 董深育 on 2020/8/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    //从右向左遍历，第33个用例 超时
    vector<int> dailyTemperatures(vector<int>& T) {
        int len=(int)T.size();
        if(len==0){
            return {};
        }
        int max=T[len-1];
        int index=len-1;
        int i=len-2;
        vector<int>ret;
        ret.push_back(0);
        while(i>=0){
            //说明后面没有数字比他大了
            int kk=0;
            if(max<=T[i]){
                ret.insert(ret.begin(), 0);
                //更新max
                max=T[i];
                //更新index
                index=i;
            }else if(max>T[i]){ //当数字比他大的时候 找中间还有没有更接近的
                kk=index-i;
                bool getmin=false;
                for(int j=i+1;j<index;j++){
                    if(T[j]>T[i]&&kk>=(j-i)){
                        kk=j-i;
                        ret.insert(ret.begin(), kk);
                        getmin=true;
                        break;
                    }
                }
                if(!getmin){
                     ret.insert(ret.begin(), kk);
                }
            }
            i--;
            
        }
        return ret;
    }
     vector<int> dailyTemperatures_stack(vector<int>& T) {
         int len=(int)T.size();
         if(len==0){
             return {};
         }
         stack<pair<int,int>>mystack;
         vector<int>ret(len,0);
         mystack.push(make_pair(T[0], 0));
         for(int i=1;i<=len-1;i++){
             while(!mystack.empty()){
                 pair<int,int>kk=mystack.top();
                 if(kk.first<T[i]){
                     ret[kk.second]=i-kk.second;
                     mystack.pop();
                 }else{
                     break;
                 }
             }
            mystack.push(make_pair(T[i], i));
         }
         while(!mystack.empty()){
             pair<int,int>kk=mystack.top();
             ret[kk.second]=0;
             mystack.pop();
         }
         return ret;
     }
    
   
    
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>ret={34,80,80,34,34,80,80,80,80,34};
    s.dailyTemperatures_stack(ret);
    return 0;
}
