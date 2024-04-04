// https://petlja.org/biblioteka/r/Zbirka2/isplata_sa_najmanje_novcica

#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) cin >> coins[i];
    // minCoins[i] je minimalna količina novčića potrebna za vrednost i
    vector<int> minCoins(s + 1, s + 1);  // popunjeno sa s + 1 jer je veće od svake vrednosti novčića
    minCoins[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= s; j++) {
            minCoins[j] = min(minCoins[j], minCoins[j - coins[i]] + 1);
        }
    }

    cout << (minCoins[s] <= s ? minCoins[s] : -1) << endl;
    return 0;
}
