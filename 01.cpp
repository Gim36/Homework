// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/svi_najkraci_putevi_retko

#include <bits/stdc++.h>

using namespace std;

const double INF = numeric_limits<double>::infinity();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ifstream cin("/home/xceptional/dev/Cpp/input.txt");

  int n, m;
  cin >> n >> m;
  vector<vector<double>> branches(n, vector<double>(n, INF));

  for (int i = 1; i <= m; i++) {
    int a, b, time;
    cin >> a >> b >> time;
    branches[a][b] = time;
  }

  vector<vector<double>> distances = branches;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double nextTime = distances[i][k] + distances[k][j];
        if (distances[i][k] != INF && distances[k][j] != INF) {
          distances[i][j] = min(nextTime, distances[i][j]);
        }
      }
    }
  }

  double result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (branches[i][j] != INF && distances[i][j] != INF) {
        result = max(result, branches[i][j] - distances[i][j]);
      }
    }
  }

  cout << result << endl;
  return 0;
}
