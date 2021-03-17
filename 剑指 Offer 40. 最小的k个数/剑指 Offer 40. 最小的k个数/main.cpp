//
//  main.cpp
//  剑指 Offer 40. 最小的k个数
//
//  Created by dsy on 2021/2/27.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void quicksort(vector<int>& arr,int l,int r,int k){
        if(l>r) return;
        int pivot=arr[r];
        int i=l;
        int j=r-1;
        while(i<j){
            while(i<j&&arr[i]<=pivot) i++;
            while(i<j&&arr[j]>pivot) j--;
            swap(arr[i],arr[j]);
        }
        if(arr[i]>=pivot){
            swap(arr[i],arr[r]);
        }else{
            i++;
        }
        int cnt=i-l+1;
        if(cnt==k){
            return;
        }else if(cnt<k){
            quicksort(arr,i+1,r,k-cnt);
        }else{
            quicksort(arr,l,i-1,k);
        }

    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int r=arr.size()-1;
        quicksort(arr,0,r,k);
        vector<int>ans(arr.begin(),arr.begin()+k)  ;
        return  ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr={3,2,1};
    s.getLeastNumbers(arr, 2);
    return 0;
}
