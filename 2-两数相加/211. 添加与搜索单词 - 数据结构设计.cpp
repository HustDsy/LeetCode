#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
   public:
    vector<WordDictionary*> v;
    bool isend;
    WordDictionary() {
        isend = false;
        v = vector<WordDictionary*>(26, nullptr);
    }

    void addWord(string word) {
        int l = word.length();
        WordDictionary* ptr = this;
        for (int i = 0; i < l; i++) {
            int cur = word.at(i) - 'a';
            if (!ptr->v[cur]) {
                ptr->v[cur] = new WordDictionary();
            }
            ptr = ptr->v[cur];
        }
        ptr->isend = true;
    }

    bool search(string word) {
        int l = word.length();
        WordDictionary* ptr = this;
        for (int i = 0; i < l; i++) {
            if (word[i] == '.') {
                string w = word.substr(i + 1);
                for (int j = 0; j < 26; j++) {
                    if (ptr->v[j]) {
                        if (ptr->v[j]->search(w)) {
                            return true;
                        };
                    }
                }
                return false;
            } else {
                int cur = word.at(i) - 'a';
                if (!ptr->v[cur]) {
                    return false;
                }
                ptr = ptr->v[cur];
            }
        }
        return ptr->isend;
    }
};

int main() {
    int a = 0, b = 0;
    return 0;
}