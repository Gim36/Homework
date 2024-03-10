// https://petlja.org/biblioteka/r/Zbirka2/cilindricna_matrica

#include <bits/stdc++.h>

using namespace std;

int min_path(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int result = INT_MAX;
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = min_path(matrix);
    cout << result << endl;
    return 0;
}