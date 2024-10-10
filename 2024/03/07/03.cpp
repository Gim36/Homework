// https://petlja.org/biblioteka/r/Zbirka2/najduzi_put_nizbrdo

#include <bits/stdc++.h>

using namespace std;

pair<int, int> shift[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isField(int i, int j, int nv, int nk) {
    return i >= 0 && i < nv && j >= 0 && j < nk;
}

int goDown(int i, int j, pair<int, int> end, vector<vector<int>>& height, vector<vector<int>>& calculated) {
    if (i == end.first && j == end.second) return 1;
    if (calculated[i][j] != -1) return calculated[i][j];

    int maxPath = 0;
    for (auto x : shift) {
        int iNext = i + x.first;
        int jNext = j + x.second;
        if (isField(iNext, jNext, height.size(), height[0].size()) && height[iNext][jNext] < height[i][j]) {
            int path = goDown(iNext, jNext, end, height, calculated);
            // + 1 jer računamo i trenutnu raskrsnicu
            if (path > 0) maxPath = max(maxPath, path + 1);
        }
    }

    return calculated[i][j] = maxPath;
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> start, end;
    vector<vector<int>> height(n, vector<int>(m));
    // calculated[i][j] je vrednost najdužeg puta koji počinje od (i, j)
    vector<vector<int>> calculated(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> height[i][j];
        }
    }
    cin >> start.first >> start.second >> end.first >> end.second;

    int result = goDown(start.first, start.second, end, height, calculated);
    if (!result) {
        cout << "ne postoji" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}