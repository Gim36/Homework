#include <bits/stdc++.h>

using namespace std;

const float defaultZapremina = 100;
const float defaultStanje = 0;

class Rezervoar {
   private:
    float zapremina;
    float stanje;

   public:
    Rezervoar() {
        this->zapremina = defaultZapremina;
        this->stanje = defaultStanje;
    }

    Rezervoar(float zapremina) {
        this->setZapremina(zapremina, true);
        this->stanje = defaultStanje;
    }

    Rezervoar(float zapremina, float stanje) {
        this->setZapremina(zapremina, true);
        this->setStanje(stanje);
    }

    void setZapremina(float zapremina, bool defaultCase = false) {
        if (zapremina > 0 && (defaultCase || zapremina >= this->stanje)) {
            this->zapremina = zapremina;
        } else if (defaultCase) {
            this->zapremina = defaultZapremina;
        }
    }

    void setStanje(float stanje) {
        if (stanje < 0) {
            this->stanje = defaultStanje;
        } else if (stanje > this->zapremina) {
            this->stanje = this->zapremina;
        } else {
            this->stanje = stanje;
        }
    }

    float getZapremina() const {
        return this->zapremina;
    }

    float getStanje() const {
        return this->stanje;
    }

    float dopuni(float kolicina) {
        if (kolicina < 0) return 0;
        float stanje = this->stanje;
        float novoStanje = this->stanje + kolicina;

        this->stanje = (novoStanje > this->zapremina) ? this->zapremina : novoStanje;
        return this->stanje - stanje;
    }

    float istoci(float kolicina) {
        if (kolicina < 0) return 0;
        float stanje = this->stanje;
        float novoStanje = this->stanje - kolicina;

        this->stanje = (novoStanje < 0) ? 0 : novoStanje;
        return stanje - this->stanje;
    }

    float tankuj() {
        float kolicina = this->zapremina - this->stanje;
        this->stanje = this->zapremina;
        return kolicina;
    }

    float isprazni() {
        float kolicina = this->stanje - 0;
        this->stanje = 0;
        return kolicina;
    }

    float kapacitetPunjenja() {
        return this->zapremina - this->stanje;
    }
};

void printRezervoar(Rezervoar rezervoar) {
    cout << rezervoar.getStanje() << " / " << rezervoar.getZapremina() << ", " << rezervoar.kapacitetPunjenja() << endl;
}

int main() {
    Rezervoar rezervoar;
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar = Rezervoar(100);
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar = Rezervoar(100, 60);
    printRezervoar(rezervoar);  // 60 / 100, 40

    rezervoar = Rezervoar(100, -123);
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar = Rezervoar(100, 123);
    printRezervoar(rezervoar);  // 100 / 100, 0

    rezervoar = Rezervoar(100, 60);
    cout << rezervoar.dopuni(30) << " " << rezervoar.getStanje() << endl;  // 30 90

    rezervoar = Rezervoar(100, 60);
    cout << rezervoar.dopuni(50) << " " << rezervoar.getStanje() << endl;  // 40 100

    rezervoar = Rezervoar(100, 30);
    cout << rezervoar.istoci(20) << " " << rezervoar.getStanje() << endl;  // 20 10

    rezervoar = Rezervoar(100, 30);
    cout << rezervoar.istoci(50) << " " << rezervoar.getStanje() << endl;  // 30 0

    rezervoar = Rezervoar(100, 30);
    cout << rezervoar.tankuj() << " " << rezervoar.getStanje() << endl;  // 70 100

    rezervoar = Rezervoar(100, 30);
    cout << rezervoar.isprazni() << " " << rezervoar.getStanje() << endl;  // 30 0

    rezervoar = Rezervoar(-100);
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar = Rezervoar(0, 1);
    printRezervoar(rezervoar);  // 1 / 100, 99

    rezervoar.setZapremina(-100);
    printRezervoar(rezervoar);  // 1 / 100, 99

    rezervoar.setZapremina(0);
    printRezervoar(rezervoar);  // 1 / 100, 99

    rezervoar = Rezervoar(100, 60);
    cout << rezervoar.dopuni(-100) << " " << rezervoar.getStanje() << endl;  // 0 60

    rezervoar = Rezervoar(100, 30);
    cout << rezervoar.istoci(-100) << " " << rezervoar.getStanje() << endl;  // 0 30

    rezervoar = Rezervoar(20, 30);
    printRezervoar(rezervoar);  // 20 / 20, 0

    rezervoar.setZapremina(10);
    printRezervoar(rezervoar);  // 20 / 20, 0

    rezervoar = Rezervoar(200, 100);
    rezervoar.setZapremina(50);
    printRezervoar(rezervoar);  // 100 / 200, 100

    return 0;
}