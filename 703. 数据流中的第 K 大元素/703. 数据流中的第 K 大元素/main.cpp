//
//  main.cpp
//  703. 数据流中的第 K 大元素
//
//  Created by dsy on 2021/2/20.
//

#include <iostream>
#include<vector>
using namespace std;

class KthLargest {
public:
    vector<int>a;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        a=nums;
        sort(a.begin(), a.end(),greater<int>());
    }
    
    int add(int val) {
        if(a.size()==0){
            a.push_back(val);
        }
        for(int i=0;i<a.size();i++){
            if(val>=a[i]){
                a.insert(a.begin()+i, val);
                break;
            }
            a.push_back(val);
        }
        return  a[K-1];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>a={};
    KthLargest b(1,a);
    b.add(-3);
    b.add(-2);
    b.add(-4);
    b.add(0);
    b.add(4);
    return 0;
}
