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
        this->stanje = defaultStanje;
        this->zapremina = defaultZapremina;
    }

    Rezervoar(float zapremina) {
        this->setZapremina(zapremina);
        this->stanje = defaultStanje;
    }

    Rezervoar(float zapremina, float stanje) {
        this->setZapremina(zapremina);
        this->setStanje(stanje);
    }

    void setZapremina(float zapremina) {
        this->zapremina = (zapremina <= 0) ? defaultZapremina : zapremina;
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
        float stanje = this->stanje;
        float novoStanje = this->stanje + kolicina;

        // Ako je kolicina < 0? Ovde ću pretpostaviti da je input korektan jer zadatak ne definiše taj slučaj
        this->stanje = (novoStanje > this->zapremina) ? this->zapremina : novoStanje;
        return this->stanje - stanje;
    }

    float istoci(float kolicina) {
        float stanje = this->stanje;
        float novoStanje = this->stanje - kolicina;

        // Ako je kolicina < 0? Ovde ću pretpostaviti da je input korektan jer zadatak ne definiše taj slučaj
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
    Rezervoar rezervoar = Rezervoar();
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar.setStanje(60);
    cout << rezervoar.dopuni(30) << " " << rezervoar.getStanje() << endl;  // 30 90

    rezervoar.setStanje(60);
    cout << rezervoar.dopuni(50) << " " << rezervoar.getStanje() << endl;  // 40 100

    rezervoar = Rezervoar(-123);
    printRezervoar(rezervoar);  // 0 / 100, 100

    rezervoar.setStanje(30);
    cout << rezervoar.istoci(20) << " " << rezervoar.getStanje() << endl;  // 20 10

    rezervoar.setStanje(30);
    cout << rezervoar.istoci(50) << " " << rezervoar.getStanje() << endl;  // 30 0

    rezervoar = Rezervoar(1, -123);
    printRezervoar(rezervoar);  // 0 / 1, 1

    rezervoar.setZapremina(100);
    rezervoar.setStanje(30);
    cout << rezervoar.tankuj() << " " << rezervoar.getStanje() << endl;  // 70 100

    rezervoar = Rezervoar(1, 2);
    printRezervoar(rezervoar);  // 1 / 1, 0

    rezervoar.setZapremina(100);
    rezervoar.setStanje(30);
    cout << rezervoar.kapacitetPunjenja() << endl;                         // 70
    cout << rezervoar.isprazni() << " " << rezervoar.getStanje() << endl;  // 30 0

    return 0;
}