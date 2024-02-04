// https://petlja.org/biblioteka/r/Zbirka2/minesweeper_otvaranje

#include <bits/stdc++.h>

using namespace std;

#define N 10

pair<int, int> shift[8] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

bool isField(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

void dfsR(int i, int j, int numBombs[][N], int result[][N]) {
    result[i][j] = numBombs[i][j];
    if (result[i][j] == 0) {
        for (auto x : shift) {
            int iNext = i + x.first;
            int jNext = j + x.second;
            if (isField(iNext, jNext) && result[iNext][jNext] == -1 && numBombs[iNext][jNext] != -1) {
                dfsR(iNext, jNext, numBombs, result);
            }
        }
    }
}

int main() {
    int bombs[N][N];
    string input;

    for (auto i = 0; i < N; i++) {
        cin >> input;
        for (auto j = 0; j < N; j++) {
            bombs[i][j] = int(input[j] - '0');
        }
    }

    int numBombs[N][N];
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            if (bombs[i][j] != 1) {
                int bombsAround = 0;
                for (auto x : shift) {
                    int iNext = i + x.first;
                    int jNext = j + x.second;
                    if (isField(iNext, jNext) && bombs[iNext][jNext] == 1) {
                        bombsAround++;
                    }
                }
                numBombs[i][j] = bombsAround;
            } else {
                numBombs[i][j] = -1;
            }
        }
    }

    int r, k;
    cin >> r >> k;
    if (bombs[r][k] == 1) {
        cout << "boom";
        return 0;
    }

    int result[N][N];
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            result[i][j] = -1;
        }
    }

    dfsR(r, k, numBombs, result);

    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            if (result[i][j] == -1) {
                cout << "x";
            } else if (result[i][j] == 0) {
                cout << ".";
            } else {
                cout << result[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}