//
//  main.cpp
//  575. 分糖果
//
//  Created by 董深育 on 2020/8/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int size=(int)candies.size();
        map<int,int>mymap;
        for(int i=0;i<size;i++){
            //找不到
            if(mymap.find(candies[i])==mymap.end()){
                mymap[candies[i]]=1;
            }else{
                mymap[candies[i]]+=1;
            }
        }
        if(mymap.size()>=size/2){
            return size/2;
        }
        return  mymap.size();
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>can={1,1,2,2,3,3};
    s.distributeCandies(can);
    return 0;
}
