//
//  main.cpp
//  973. 最接近原点的 K 个点
//
//  Created by 董深育 on 2020/11/9.
//

#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    void quickSort(int left,int right,vector<pair<vector<int>,int>>&dp,int K){
        if(left>right){
            return;
        }
        int pivot=dp[right].second;
        int L=left;
        int R=right-1;
        while(L<R){
            while(dp[L].second<pivot&&L<R)L++;
            while(dp[R].second>=pivot&&L<R)R--;
           // pair<vector<int>, int>temp;
            dp[L].swap(dp[R]);
        }
        if(dp[L].second>=pivot){
            dp[L].swap(dp[right]);
        }else{
            L++;
        }
        if (K < L - left + 1) {
            quickSort(left,L-1, dp,K);
        }
        else if (K > L - left + 1) {
            quickSort(L+1,right, dp, K-(L-left+1));
        }

    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<vector<int>,int>>dp;
        int size=(int)points.size();
        for(int i=0;i<size;i++){
            int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pair<vector<int>,int>p=make_pair(points[i], distance);
            dp.push_back(p);
        }
        //points进行排序
        quickSort(0, size-1, dp,K);
        vector<vector<int>>ans;
        for(int i=0;i<K;i++){
            ans.push_back(dp[i].first);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
