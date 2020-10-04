//
//  main.cpp
//  211. 添加与搜索单词 - 数据结构设计
//
//  Created by 董深育 on 2020/10/4.
//

#include <iostream>
#include<vector>
using namespace std;
class WordDictionary {
public:
    bool isend;
    WordDictionary*next[26];
    /** Initialize your data structure here. */
    WordDictionary() {
        isend=false;
        memset(next, 0, sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary*p=this;
        for(char c:word){
            if(p->next[c-'a']==nullptr){
                p->next[c-'a']=new WordDictionary();
            }
            p=p->next[c-'a'];
        }
        p->isend=true;
    }
    bool searchWord(WordDictionary* node, string word) {
           if(word.size()==1) {  //边界
               if(isalpha(word[0])) {
                   if(node->next[word[0]-'a'] && node->next[word[0]-'a']->isend)
                       return true;
                   return false;
               }
               else {
                   for(int i=0; i<26; i++)
                       if(node->next[i] && node->next[i]->isend)
                           return true;
                   return false;
               }
           }
           else {
               if(isalpha(word[0])) {
                   if(node->next[word[0]-'a'])
                       return searchWord(node->next[word[0]-'a'], word.substr(1, word.size()-1));
                   else
                       return false;
               }
               else {
                   bool b;
                   for(int i=0; i<26; i++) {
                       if(node->next[i]){
                           b = searchWord(node->next[i], word.substr(1, word.size()-1));
                           if(b)   return true;
                       }
                   }
                   return false;
               }
           }
       }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(this, word);
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
