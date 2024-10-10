// https://petlja.org/biblioteka/r/Zbirka2/najduzi_prohodan_put

#include <bits/stdc++.h>

using namespace std;

pair<int, int> shift[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int maxSteps = -1;

bool isField(int i, int j, int nv, int nk) {
    return i >= 0 && i < nv && j >= 0 && j < nk;
}

void dfsR(vector<vector<int>>& fields, vector<vector<bool>>& visited, pair<int, int> cur, pair<int, int> end, int steps) {
    if (cur == end) {
        maxSteps = max(maxSteps, steps);
        return;
    }

    for (auto x : shift) {
        int iNext = cur.first + x.first;
        int jNext = cur.second + x.second;

        if (isField(iNext, jNext, fields.size(), fields[0].size()) && !visited[iNext][jNext] && fields[iNext][jNext] == 0) {
            visited[iNext][jNext] = true;
            dfsR(fields, visited, {iNext, jNext}, end, steps + 1);
            // Ako dfsR završi, nastavi sa poljem na kom je pozvana, radi provere svakog puta
            visited[iNext][jNext] = false;
        }
    }
}

int main() {
    int nv, nk;
    cin >> nv >> nk;

    vector<vector<int>> fields(nv, vector<int>(nk));
    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < nk; j++) {
            cin >> fields[i][j];
        }
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    vector<vector<bool>> visited(nv, vector<bool>(nk, false));
    visited[start.first][start.second] = true;

    dfsR(fields, visited, start, end, 0);
    cout << (maxSteps == -1 ? -1 : maxSteps) << endl;

    return 0;
}
