//
//  main.cpp
//  1482. 制作 m 束花所需的最少天数
//
//  Created by dsy on 2021/5/9.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int total;
    bool check(vector<int>& bloomDay, int m, int k,int limit){
        //滑动窗口来解
        int l=0;
        int r=total;
        int cur;
        int curm=0;
        while(l<r){
            cur=0;
            while(l<r&&bloomDay[l]<=limit){
                cur++;
                if(cur==k){
                    cur=0;
                    curm++;
                    if(curm>=m) return true;
                    break;
                }
                l++;
            }
            l++;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        total=static_cast<int>(bloomDay.size());
        if(total<m*k){
            return -1;
        }
        int l=1;
        int r=*max_element(bloomDay.begin(), bloomDay.end(),less<int>());
        while(l<r){
            int mid=l+(r-l)/2;
            //如果mid可以的话，考虑<mid的数字
            if(check(bloomDay, m,k,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l<=r?l:-1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
