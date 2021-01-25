//
//  main.cpp
//  989. 数组形式的整数加法
//
//  Created by dsy on 2021/1/22.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
//    vector<int> addToArrayForm(vector<int>& A, int K) {
//        vector<int>B;
//        if(K==0) return  A;
//        while(K!=0){
//            int temp=K%10;
//            K/=10;
//            B.insert(B.begin(), temp);
//        }
//        int lA=A.size()-1;
//        int lB=B.size()-1;
//        vector<int>ans;
//        //B加到A
//        int cur=0;
//        int next=0;
//        while(lA>=0||lB>=0){
//            int p=lA>=0?A[lA]:0;
//            int q=lB>=0?B[lB]:0;
//            lA--;
//            lB--;
//            cur=(p+q+next)%10;
//            next=(p+q+next)/10;
//            ans.insert(ans.begin(), cur);
//        }
//        if(next!=0){
//            ans.insert(ans.begin(), next);
//        }
//        return  ans;
//    }
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int>ans;
        int n=static_cast<int>(A.size())-1;
        int p=0;
        int q=0;
        for(int i=n;i>=0;i--){
            p=(A[i]+K%10+q)%10;
            q=(A[i]+K%10+q)/10;
            ans.emplace_back(p);
            K=K/10;
        }
        K=K+q;
        for (; K > 0; K /= 10) {
            ans.push_back(K % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
