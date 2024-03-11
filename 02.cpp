// https://petlja.org/biblioteka/r/Zbirka2/padajuce_loptice

#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    vector<string> matrix;
    while (getline(cin, line)) {
        if (line != "") {
            matrix.push_back(line);
        } else {
            break;
        }
    }

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> grid(n, vector<int>(m, -1));

    for (int j = m - 1; j >= 0; j--) {
        if (matrix[n - 1][j] == '.') {
            grid[n - 1][j] = 1;
        } else {
            grid[n - 1][j] = 3;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        // for (int k = 0; k < n; k++) {
        //     for (int l = 0; l < m; l++) {
        //         cout << grid[k][l];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == '.') {
                if (grid[i + 1][j] == 1) {
                    grid[i][j] = 1;
                } else {
                    if (grid[i + 1][j] == 3) {
                        if (j < m - 1 && grid[i][j + 1] == 1)
                            grid[i][j] = 1;
                        else
                            grid[i][j] = 2;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            } else {
                grid[i][j] = 3;
            }

            if ((grid[i][j] != 2 && j < m - 1) || j == 0) {
                int k = j + 1, num = 0;
                if (j == 0 && grid[i][j] == 2) {
                    grid[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    num = 1;
                } else {
                    num = 0;
                }
                while (grid[i][k] == 2) {
                    grid[i][k] = num;
                    k++;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 3) {
            cout << 0;
        } else {
            cout << grid[0][j];
        }
    }

    return 0;
}
