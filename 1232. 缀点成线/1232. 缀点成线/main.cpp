//
//  main.cpp
//  1232. 缀点成线
//
//  Created by dsy on 2021/1/17.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len=(int)coordinates.size();
        if(len==2) return true;
        //计算斜率
        auto point1=coordinates[0];
        auto point2=coordinates[1];
        //判断是否都在y轴
        bool yy=false;
        if(point2[0]-point1[0]==0){
            yy=true;
        }
        float k=yy?0:(float)(point2[1]-point1[1])/(point2[0]-point1[0]);
        for(int i=2;i<len;i++){
            auto point3=coordinates[i];
            if(yy){
                if(point3[0]!=point2[0]){
                    return false;
                }
            }else{
                if(point3[0]-point2[0]==0||((float)(point3[1]-point2[1])/(point3[0]-point2[0])!=k)){
                    return false;
                }
            }
            point2=point3;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>coordinates={{1,2},{2,3},{3,5}};
    cout<<s.checkStraightLine(coordinates);
    std::cout << "Hello, World!\n";
    return 0;
}
