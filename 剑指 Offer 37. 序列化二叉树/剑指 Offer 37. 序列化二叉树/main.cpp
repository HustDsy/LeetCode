//
//  main.cpp
//  剑指 Offer 37. 序列化二叉树
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<string>
#include<queue>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string s("");
            string empty="null";
            TreeNode*null=nullptr;
            if(!root) return s;
            s="[";
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int size=q.size();
                while(size){
                    TreeNode*temp=q.front();
                    q.pop();
                     size--;
                    if(!temp){
                          s+=empty;
                          s+=",";
                          continue;
                    }
                    s+=to_string(temp->val);
                    s+=",";
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            s=s.substr(0, s.length()-1);
            s="]";
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            TreeNode*root;
            queue<string>datas;
            string temp("");
            for(int i=1;i<=data.size()-2;i++){
                if(data[i]==','){
                    datas.push(temp);
                    temp="";
                }else{
                    temp+=data[i];
                }
            }
            datas.push(temp);
            if(datas.size()==0)return nullptr;
             queue<TreeNode*>q;
            string head=datas.front();
            datas.pop();
            root=new TreeNode(stoi(head));
            q.push(root);
            int currsize;
            while(!datas.empty()){
                currsize=q.size();
                for(int i=0;i<currsize;i++){
                    string left=datas.front();
                    datas.pop();
                    string right=datas.front();
                    datas.pop();
                    TreeNode*tt=q.front();
                    q.pop();
                    if(left!="null"){
                        tt->left=new TreeNode(stoi(left));
                        q.push(tt->left);
                    }
                     if(right!="null"){
                        tt->right=new TreeNode(stoi(right));
                        q.push(tt->right);
                    }

                }
            }
            return root;
        }
};


int main(int argc, const char * argv[]) {
    Codec c;
    c.deserialize("[1,2,3,null,null,4,5]");
    return 0;
}
