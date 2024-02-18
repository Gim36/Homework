// Stack using vector

#include <bits/stdc++.h>

using namespace std;

/*
u x   push
o     pop
r     read
*/

int main() {
    vector<int> v;
    char c;
    int value;

    while (cin >> c) {
        if (c == 'u') {
            cin >> value;
            v.push_back(value);
        } else if (c == 'o')
            v.pop_back();
        else {
            cout << v[v.size() - 1] << endl;
        }
    }

    return 0;
}