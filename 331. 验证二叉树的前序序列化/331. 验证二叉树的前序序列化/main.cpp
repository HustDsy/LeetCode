//
//  main.cpp
//  331. 验证二叉树的前序序列化
//
//  Created by dsy on 2021/3/12.
//

#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string>s;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            string temp;
            while(i<n&&preorder[i]!=','){
                temp.push_back(preorder[i++]);
            }
            s.push(temp);
            while(s.size()>=3){
                string top=s.top();
                s.pop();
                string top1=s.top();
                s.pop();
                string top2=s.top();
                s.pop();
                if(top=="#"&&top1=="#"&&top2!="#"){
                    s.push("#");
                }else{
                    s.push(top2);
                    s.push(top1);
                    s.push(top);
                    break;
                }
            }
        }
        return s.size()==1&&s.top()=="#";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s("9,#,92,#,#");
    Solution ss;
    ss.isValidSerialization(s);
    std::cout << "Hello, World!\n";
    return 0;
}
