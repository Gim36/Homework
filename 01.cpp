// https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka3/pecine

#include <bits/stdc++.h>

using namespace std;

void dfsR(int i, vector<map<int, int>>& branches, vector<int>& heights, int& min) {
    for (auto x : branches[i]) {
        heights[x.first] = heights[i] + x.second;
        min = std::min(heights[x.first], min);
        dfsR(x.first, branches, heights, min);
    }
}

int main() {
    int height, n;
    cin >> height >> n;
    vector<map<int, int>> branches(n);

    for (int i = 1; i <= n - 1; i++) {
        int r, k, h;
        cin >> r >> k >> h;
        branches[r][k] = h;
    }

    vector<int> heights(n);
    heights[0] = height;

    int min = height;
    dfsR(0, branches, heights, min);

    cout << min << endl;
    return 0;
}