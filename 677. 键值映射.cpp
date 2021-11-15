#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<node*> v;
    bool end;
    string world;
    node() : end(false), v(26, nullptr), world("") {}
};

class MapSum {
   public:
    unordered_map<string, int> m;
    node* n;
    MapSum() { n = new node(); }

    void insert(string key, int val) {
        if (m.count(key)) {
            m[key] = val;
            return;
        }
        m[key] = val;
        node* temp = n;
        int l = key.length();
        for (int i = 0; i < l; i++) {
            int cur = key[i] - 'a';
            if (!temp->v[cur]) {
                temp->v[cur] = new node();
            }
            temp = temp->v[cur];
        }
        temp->end = true;
        temp->world = key;
    }

    int dfs(node* cur) {
        if (!cur) {
            return 0;
        }
        int res = 0;
        if (cur->end) {
            res += m[cur->world];
        }
        for (int i = 0; i < 26; i++) {
            if (cur->v[i]) {
                res += dfs(cur->v[i]);
            }
        }
        return res;
    }
    int sum(string prefix) {
        node* temp = n;
        int l = prefix.length();
        for (int i = 0; i < l; i++) {
            int cur = prefix[i] - 'a';
            if (temp->v[cur]) {
                temp = temp->v[cur];
            } else {
                return 0;
            }
        }
        // dfs开始遍历
        return dfs(temp);
    }
};

int main() { 
    vector<int> v;
    v = vector<int>(26, 0);
    for (int i : v) {
        cout << i << endl;
    }
    return 0;
}