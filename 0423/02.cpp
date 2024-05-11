// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/korensko_drvo

#include <bits/stdc++.h>

using namespace std;

void dfsR(int i, vector<vector<int>>& branches, map<int, set<int>>& result) {
    for (auto x : branches[i]) {
        if (result[x].empty()) {
            result[i].insert(x);
            dfsR(x, branches, result);
        }
    }
}

int main() {
    int n, root;
    cin >> n;
    vector<vector<int>> branches(n);

    for (int i = 1; i <= n - 1; i++) {
        int r, k;
        cin >> r >> k;
        branches[r].push_back(k);
        branches[k].push_back(r);
    }

    cin >> root;
    map<int, set<int>> result;
    dfsR(root, branches, result);

    for (auto x : result) {
        for (auto y : x.second) {
            cout << x.first << " " << y << endl;
        }
    }

    return 0;
}