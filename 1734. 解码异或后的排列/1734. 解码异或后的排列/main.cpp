//
//  main.cpp
//  1734. 解码异或后的排列
//
//  Created by dsy on 2021/5/11.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>perm;
        int size=static_cast<int>(encoded.size());
        perm.reserve(size+1);
        int total=1;
        for(int i=2;i<=size+1;i++){
            total^=i;
        }
        for(int i=1;i<size;i+=2){
            total^=encoded[i];
        }
        perm.push_back(total);
        for(int i=0;i<size;i++){
            perm.push_back(encoded[i]^perm[i]);
        }
        return perm;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
