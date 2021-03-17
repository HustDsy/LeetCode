//
//  main.cpp
//  剑指 Offer 31. 栈的压入、弹出序列
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
//    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//        stack<int>s;
//        int s1=pushed.size();
//        int s2=popped.size();
//        int i=0;
//        int j=0;
//        while(i<s1&&j<s2){
//            while(i<s1&&pushed[i]!=popped[j]){
//                s.push(pushed[i]);
//                i++;
//            }
//            if(i<s1&&pushed[i]==popped[j]){
//                s.push(pushed[i]);
//                i++;
//            }
//
//            while(j<s2&&!s.empty()&&s.top()==popped[j]){
//                s.pop();
//                j++;
//            }
//        }
//        return i==s1&&j==s2;
//    }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int s1=pushed.size();
        int s2=popped.size();
        int j=0;
        for(int i=0;i<s1;i++){
            s.push(pushed[i]);
            while(j<s1&&!s.empty()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return j==s1;
    }
};



int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> pushed={1,2,3,4,5};
    vector<int> popped={4,5,3,2,1};
    s.validateStackSequences(pushed,popped);
    return 0;
}
