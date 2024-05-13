// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/kruzni_autobusi

#include <bits/stdc++.h>

using namespace std;

int bfs(int start, int end, vector<vector<int>>& lines, map<int, vector<int>>& stations) {
    int counter = 0;
    vector<int> visitedLines(lines.size(), false);
    map<int, bool> visitedStations;
    queue<int> toDoCurrent, toDoNext;
    toDoCurrent.push(start);
    visitedStations[start] = true;

    while (!toDoCurrent.empty()) {
        int station = toDoCurrent.front();
        toDoCurrent.pop();
        if (station == end) return counter;

        for (auto l : stations[station]) {
            if (!visitedLines[l]) {
                visitedLines[l] = true;
                for (auto s : lines[l]) {
                    if (!visitedStations[s]) {
                        visitedStations[s] = true;
                        toDoNext.push(s);
                    }
                }
            }
        }

        if (toDoCurrent.empty()) {
            swap(toDoCurrent, toDoNext);
            counter++;
        }
    }

    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> lines(n);
    map<int, vector<int>> stations;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            lines[i].push_back(temp);
            stations[temp].push_back(i);
        }
    }

    int start, end;
    cin >> start >> end;

    int result = bfs(start, end, lines, stations);
    cout << result << endl;

    return 0;
}