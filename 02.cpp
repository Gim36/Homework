// https://petlja.org/biblioteka/r/Zbirka2/padajuce_loptice

#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    vector<string> matrix;
    while (getline(cin, line)) {
        matrix.push_back(line);
    }

    int n = matrix.size();
    int m = matrix[0].size();
    // grid[i][j] = 0 - zaglavljena
    // grid[i][j] = 1 - izlazi
    // grid[i][j] = 2 - ne znamo
    // grid[i][j] = 3 - zid
    vector<int> grid(m, 0);

    for (int j = 0; j < m; j++) {
        grid[j] = (matrix[n - 1][j] == '.') ? 1 : 3;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                switch (grid[j]) {
                    int k;
                    case 1:
                        k = j - 1;
                        while (k >= 0 && grid[k] == 2) {
                            grid[k] = 1;
                            k--;
                        }
                        break;
                    case 3:
                        grid[j] = (j > 0 && grid[j - 1] == 1) ? 1 : 2;
                        break;
                    default:
                        grid[j] = 0;
                        k = j - 1;
                        while (k >= 0 && grid[k] == 2) {
                            grid[k] = 0;
                            k--;
                        }
                }
            } else {
                grid[j] = 3;
                int k = j - 1;
                while (k >= 0 && grid[k] == 2) {
                    grid[k] = 0;
                    k--;
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        cout << ((grid[j] == 1) ? 1 : 0);
    }

    cout << endl;
    return 0;
}
