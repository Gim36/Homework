// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/provera_ciklusa

#include <bits/stdc++.h>

using namespace std;

bool dfs(int start, vector<vector<int>>& branches, vector<bool>& visited) {
    stack<int> toDo;
    toDo.push(start);

    while (!toDo.empty()) {
        int node = toDo.top();
        toDo.pop();

        for (auto x : branches[node]) {
            if (!visited[x]) {
                visited[x] = true;
                toDo.push(x);
            } else if (x == start) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> branches(v);

        for (int j = 1; j <= e; j++) {
            int a, b;
            cin >> a >> b;
            branches[a].push_back(b);
        }

        bool flag = true;
        vector<bool> flags(v);
        for (int j = 0; j < v; j++) {
            flags[j] = true;
            if (dfs(j, branches, flags)) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "ne" : "da") << endl;
    }

    return 0;
}