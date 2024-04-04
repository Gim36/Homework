// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>

using namespace std;

tuple<int, int, char> shift[4] = {
    {1, 0, 'D'}, {0, 1, 'R'}, {-1, 0, 'U'}, {0, -1, 'L'}};

bool isField(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool bfs(vector<vector<char>> &matrix, vector<vector<bool>> &visited,
         vector<vector<char>> &dir, pair<int, int> cur, pair<int, int> end) {
    int n = matrix.size(), m = matrix[0].size();
    queue<tuple<int, int>> toDo;
    toDo.push({cur.first, cur.second});

    while (!toDo.empty()) {
        int i = get<0>(toDo.front());
        int j = get<1>(toDo.front());
        toDo.pop();
        visited[i][j] = true;
        if (i == end.first && j == end.second) {
            return true;
        }

        for (auto x : shift) {
            int iNext = i + get<0>(x);
            int jNext = j + get<1>(x);
            if (isField(iNext, jNext, n, m) && !visited[iNext][jNext] &&
                matrix[iNext][jNext] == '.') {
                dir[iNext][jNext] = get<2>(x);
                visited[iNext][jNext] = true;
                toDo.push({iNext, jNext});
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    char input;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input;
            switch (input) {
                case 'A': {
                    start = {i, j};
                    matrix[i].push_back('.');
                    break;
                }
                case 'B': {
                    end = {i, j};
                    matrix[i].push_back('.');
                    break;
                }
                default:
                    matrix[i].push_back(input);
            }
        }
    }

    vector<vector<char>> dir(n, vector<char>(m, 0));
    bool result = bfs(matrix, visited, dir, start, end);

    if (result) {
        string path;
        for (auto at = end; at != start;) {
            char c = dir[at.first][at.second];
            path += c;
            switch (c) {
                case 'U':
                    at.first++;
                    break;
                case 'D':
                    at.first--;
                    break;
                case 'L':
                    at.second++;
                    break;
                case 'R':
                    at.second--;
            }
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}