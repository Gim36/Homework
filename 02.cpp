// Queue using linked list

#include <iostream>

using namespace std;

/*
u x - Push to the end
o   - Pop from the start
r   - Read from the start
*/

struct cvor {
    int c;
    cvor *prethodni;
    cvor *naredni;
};

cvor *napravi_cvor(char podatak, cvor *l, cvor *d) {
    cvor *novi = new cvor();
    novi->c = podatak;
    novi->prethodni = l;
    novi->naredni = d;
    return novi;
}

void izbaci_cvor(cvor *x) {
    (x->prethodni)->naredni = x->naredni;
    (x->naredni)->prethodni = x->prethodni;
    delete x;
}

void ubaci_iza(char podatak, cvor *x) {
    cvor *novi = napravi_cvor(podatak, x->prethodni, x);
    (x->prethodni)->naredni = novi;
    x->prethodni = novi;
}

int main() {
    cvor *sentinela = napravi_cvor(' ', nullptr, nullptr);
    sentinela->prethodni = sentinela;
    sentinela->naredni = sentinela;

    char c;
    int value;

    while (cin >> c) {
        if (c == 'u') {
            cin >> value;
            ubaci_iza(value, sentinela);
        } else if (c == 'o') {
            izbaci_cvor(sentinela->naredni);
        } else {
            cout << sentinela->naredni->c << endl;
        }
    }

    return 0;
}