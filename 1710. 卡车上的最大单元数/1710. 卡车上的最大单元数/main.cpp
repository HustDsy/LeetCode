//
//  main.cpp
//  1710. 卡车上的最大单元数
//
//  Created by dsy on 2021/1/14.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
   int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //按照每个箱子可以装载的单元数量进行排序
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b)->bool{
            return a[1]>b[1];
        });
        int ans=0;
        int n=0;
        for(int i=0;i<boxTypes.size()&&truckSize>0;i++){
          n=min(truckSize,boxTypes[i][0]);
          ans+=n*boxTypes[i][1];
          truckSize-=n;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
