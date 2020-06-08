//  main.cpp
//1-两数之和
//
//  Created by 董深育 on 2020/6/8.
//  Copyright 董深育. All rights reserved.
//

#include <iostream>
#include<map>
#include<vector>
using namespace std;
vector<int>twoSum(vector<int>& nums, int target) {
      map<int,int>mymap;
       for(int i=0;i<nums.size();i++){
          mymap.insert(pair<int,int>(nums[i],i));
       }
      for(int i=0;i<nums.size();i++){
          map<int,int>::iterator it=mymap.find(target-nums[i]);
          if(it!=mymap.end()&&it->second!=i){
              return{i,it->second};
          }
      }
      return {};
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int result[2];
    int num,target;
    cin>>num;
    cin>>target;
    map<int,int>mymap;
    int arry[num];
    for(int i=0;i<num;i++){
        cin>>arry[i];
        mymap.insert(pair<int,int>(arry[i],i));
    }
    for(int i=0;i<num;i++){
        map<int,int>::iterator it=mymap.find(target-arry[i]);
        if(it!=mymap.end()){
            result[0]=i;
            result[1]=it->second;
            break;
        }
    }
    std::cout << result[0]<<" "<<result[1];
    return 0;
}

