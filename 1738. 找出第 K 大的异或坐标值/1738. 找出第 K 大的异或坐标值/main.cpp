//
//  main.cpp
//  1738. 找出第 K 大的异或坐标值
//
//  Created by dsy on 2021/5/19.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void quicksort(vector<int>&v,int i,int j){
        if(i>=j) return;
        int l=i;
        int r=j-1;
        int p=v[j];
        while(l<r){
            while(l<r&&v[l]<p)l++;
            while(l<r&&v[r]>=p)r--;
            swap(v[l],v[r]);
        }
        if(v[l]>=p){
            swap(v[l],v[j]);
        }else{
            l++;
        }
        quicksort(v,i,l-1);
        quicksort(v,l+1,j);

    }
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>v(m*n);
        int a,b,c;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a=i-1>=0?v[(i-1)*n+j]:0;
                b=j-1>=0?v[i*n+j-1]:0;
                c=i-1>=0&&j-1>=0?v[(i-1)*n+j-1]:0;
                v[i*n+j]=a^b^c^matrix[i][j];
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        return v[k-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>matrix={{10,9,5},{2,0,4},{1,0,9},{3,4,8}};
    s.kthLargestValue(matrix, 10);
    return 0;
}
