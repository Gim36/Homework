// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/svi_najkraci_putevi_retko

#include <bits/stdc++.h>

using namespace std;

#define Node pair<double, int>
const double INF = numeric_limits<double>::infinity();

void dijkstra(int i, vector<vector<Node>> &branches, vector<double> &fakeMin) {
  vector<bool> visited(branches.size());
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  pq.push({0, i});
  fakeMin[i] = 0;

  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();

    if (!visited[node.second]) {
      visited[node.second] = true;
      for (auto x : branches[node.second]) {
        double nextTime = node.first + x.first;
        if (!visited[x.second] && fakeMin[x.second] > nextTime) {
          fakeMin[x.second] = nextTime;
          pq.push({fakeMin[x.second], x.second});
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ifstream cin("/home/xceptional/dev/Cpp/input.txt");

  int n, m;
  cin >> n >> m;
  vector<vector<Node>> branches(n);

  for (int i = 1; i <= m; i++) {
    int a, b, time;
    cin >> a >> b >> time;
    branches[a].push_back({time, b});
  }

  double result = 0;
  for (int i = 0; i < n; i++) {
    vector<double> fakeMin(n, INF);
    dijkstra(i, branches, fakeMin);
    for (auto x : branches[i]) {
      result = max(result, x.first - fakeMin[x.second]);
    }
  }

  cout << result << endl;
  return 0;
}
