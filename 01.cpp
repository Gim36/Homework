// Vector into priority queue

#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &v, unsigned i, unsigned j) {
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void spusti(vector<int> &pQueue, unsigned i) {
    unsigned il = 2 * i + 1;
    unsigned ir = 2 * i + 2;
    bool flag = false;

    while (ir < pQueue.size()) {
        if (pQueue[i] >= pQueue[il] && pQueue[i] >= pQueue[ir]) {
            flag = true;
            break;
        }

        if (pQueue[il] >= pQueue[ir]) {
            swap(pQueue, il, i);
            i = il;
        } else {
            swap(pQueue, ir, i);
            i = ir;
        }
        il = 2 * i + 1;
        ir = 2 * i + 2;
    }

    if (!flag && ir == pQueue.size() && pQueue[i] < pQueue[il]) {
        swap(pQueue, il, i);
    }
}

int main() {
    int n, num;
    cin >> n;
    vector<int> pQueue;

    for (int i = 0; i < n; i++) {
        cin >> num;
        pQueue.push_back(num);
    }

    int i = (pQueue.size() + 1) / 2 - 1;
    while (i >= 0) {
        spusti(pQueue, i);
        i--;
    }

    for (int i = 0; i < pQueue.size(); i++) {
        cout << pQueue[i] << " ";
    }
    cout << endl;

    return 0;
}