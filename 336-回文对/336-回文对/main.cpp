//
//  main.cpp
//  336-回文对
//
//  Created by 董深育 on 2020/8/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;




class Solution {
public:
    //暴力法 超时
    bool isTrue(string s){
        int left=0;
        int right=(int)s.length()-1;
        if(right==-1){
            return true;
        }
        while(left<right){
            if(s[right]==s[left]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
 
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ret;
        int size=(int)words.size();
        if(size==0||size==1){
            return {};
        }
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(j!=i){
                    string s=words[i]+words[j];
                    vector<int>temp(2,0);
                    if(isTrue(s)){
                        temp[0]=i;
                        temp[1]=j;
                        ret.push_back(temp);
                    }
                    s=words[j]+words[i];
                    if(isTrue(s)){
                        temp[0]=j;
                        temp[1]=i;
                        ret.push_back(temp);
                    }
                    
                }
            }
        }
        return ret;
    }
    
   
    //翻转字符串
    string reverse(string s){
        string ret="";
        int len=(int)s.length();
        for(int i=len-1;i>=0;i--){
            ret+=s[i];
        }
        return ret;
    }
    //判断是否为回文数
    bool isTrue_(string s,int left,int right){
        while(left<right){
            if(s[right]==s[left]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
    //字典树
    //节点
    struct node{
        int ch[26];
        int flag;
        node(){
            flag=-1;
            memset(ch, 0, sizeof(ch));
        }
    };
    //头节点
    vector<node>tree;
    
    //字典树的插入操作
   //这里是假设有一个头节点了
    void insert(string&s,int id){
        int p=0;
        int len = (int)s.length();
        for(int i=0;i<len;i++){
            int num=s[i]-'a';
            //在第0个node没找到的话
            if(tree[p].ch[num]==0){
                tree.emplace_back();
                tree[p].ch[num] = tree.size() - 1;
            }
            p = tree[p].ch[num];
        }
        tree[p].flag=id;
    }
    //finde函数
    int findWord(string& s, int left, int right) {
        int add = 0;
        for (int i = right; i >= left; i--) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                return -1;
            }
            add = tree[add].ch[x];
        }
        return tree[add].flag;
    }



    //找新方法
    vector<vector<int>> palindromePairs_new(vector<string>& words){
        tree.emplace_back(node());
          int size=(int)words.size();
        vector<vector<int>>ret;
        for(int i=0;i<size;i++){
            insert(words[i], i);
        }
      
        for(int i=0;i<size;i++){
            int m=(int)words[i].length();
            for(int j=0;j<=m;j++){
                //左边是回文串
                if(j&&isTrue_(words[i], 0, j-1)){
                    int right_id = findWord(words[i], j, m - 1);
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({right_id, i});
                    }
                }
                //右边是回文串
                if (isTrue_(words[i], j, m - 1)) {
                    int left_id = findWord(words[i], 0, j - 1);
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({i, left_id});
                    }
                }
            }
        }
        return ret;
    }
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    string s="12334";
    Solution sa;
    s=sa.reverse(s);
    cout<<s;
    return 0;
}
