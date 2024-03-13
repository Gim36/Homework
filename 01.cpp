// https://petlja.org/biblioteka/r/Zbirka2/cilindricna_matrica

#include <bits/stdc++.h>

using namespace std;

pair<int, int> minField(pair<int, int> fieldOne, pair<int, int> fieldTwo, vector<vector<int>>& grid) {
    return (grid[fieldOne.first][fieldOne.second] <= grid[fieldTwo.first][fieldTwo.second]) ? fieldOne : fieldTwo;
}

void printPath(int i, int j, vector<vector<int>>& grid, stack<pair<int, int>>& result) {
    if (j == 0) {
        while (!result.empty()) {
            pair<int, int> value = result.top();
            cout << value.first << " " << value.second << endl;
            result.pop();
        }
        return;
    }

    int up = (i - 1 + grid.size()) % grid.size();
    int down = (i + 1) % grid.size();
    pair<int, int> value = minField({i, j - 1}, minField({up, j - 1}, {down, j - 1}, grid), grid);
    result.push(value);
    printPath(value.first, value.second, grid, result);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Idemo po kolonama
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            // Ovako računamo i poslednju za prvu, i prvu za poslednju kolonu, jer je matrica cilindrična
            int up = (i - 1 + n) % n;
            int down = (i + 1) % n;
            grid[i][j] += min(grid[i][j - 1], min(grid[up][j - 1], grid[down][j - 1]));
        }
    }

    pair<int, int> minimum = {0, m - 1};
    for (int i = 1; i < n; i++) {
        if (grid[i][m - 1] < grid[minimum.first][minimum.second]) minimum = {i, m - 1};
    }
    cout << grid[minimum.first][minimum.second] << endl;

    stack<pair<int, int>> result;
    result.push({minimum.first, minimum.second});
    printPath(minimum.first, minimum.second, grid, result);

    return 0;
}