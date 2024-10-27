#include <bits/stdc++.h>

using namespace std;

enum paket {
    CLASSIC,
    GOLD,
    VIP
};

const paket defaultVrstaRacuna = CLASSIC;
const float defaultStanje = 0;

class Racun {
   private:
    string vlasnikIme;
    string vlasnikPrezime;
    paket vrstaRacuna;
    float stanje;

   public:
    Racun(string vlasnikIme, string vlasnikPrezime) {
        this->setVlasnikIme(vlasnikIme);
        this->setVlasnikPrezime(vlasnikPrezime);
        this->vrstaRacuna = defaultVrstaRacuna;
        this->stanje = defaultStanje;
    }

    Racun(string vlasnikIme, string vlasnikPrezime, paket vrstaRacuna) {
        this->setVlasnikIme(vlasnikIme);
        this->setVlasnikPrezime(vlasnikPrezime);
        this->setVrstaRacuna(vrstaRacuna);
        this->stanje = defaultStanje;
    }

    Racun(string vlasnikIme, string vlasnikPrezime, paket vrstaRacuna, float stanje) {
        this->setVlasnikIme(vlasnikIme);
        this->setVlasnikPrezime(vlasnikPrezime);
        this->setVrstaRacuna(vrstaRacuna);
        this->setStanje(stanje);
    }

    void setVlasnikIme(string vlasnikIme) {
        size_t start = vlasnikIme.find_first_not_of(' ');
        if (start == std::string::npos) {
            this->vlasnikIme = "";
        } else {
            size_t end = vlasnikIme.find_last_not_of(' ');
            this->vlasnikIme = vlasnikIme.substr(start, end - start + 1);
        }

        if (this->vlasnikIme.length() > 20) this->vlasnikIme = this->vlasnikIme.substr(0, 20);
    }

    void setVlasnikPrezime(string vlasnikPrezime) {
        size_t start = vlasnikPrezime.find_first_not_of(' ');
        if (start == std::string::npos) {
            this->vlasnikPrezime = "";
        } else {
            size_t end = vlasnikPrezime.find_last_not_of(' ');
            this->vlasnikPrezime = vlasnikPrezime.substr(start, end - start + 1);
        }

        if (this->vlasnikPrezime.length() > 30) this->vlasnikPrezime = this->vlasnikPrezime.substr(0, 30);
    }

    void setVrstaRacuna(paket vrstaRacuna) {
        this->vrstaRacuna = vrstaRacuna;
    }

    void setStanje(float stanje) {
        this->stanje = (stanje < 0) ? defaultStanje : stanje;
    }

    string getVlasnikIme() const {
        return this->vlasnikIme;
    }

    string getVlasnikPrezime() const {
        return this->vlasnikPrezime;
    }

    paket getVrstaRacuna() const {
        return this->vrstaRacuna;
    }

    float getStanje() const {
        return this->stanje;
    }

    void uplata(float suma) {
        if (suma > 0) this->stanje += suma;
    }

    void isplata(float suma) {
        if (suma < 0) return;
        if (suma >= this->stanje) {
            switch (this->vrstaRacuna) {
                case CLASSIC:
                    this->stanje -= this->stanje * 0.9;
                    break;

                case GOLD:
                    this->stanje -= this->stanje * 0.95;
                    break;

                case VIP:
                    this->stanje = 0;
            }
        } else {
            this->stanje -= suma;
        }
    }

    void stampa() {
        string vrstaRacuna;
        switch (this->vrstaRacuna) {
            case CLASSIC:
                vrstaRacuna = "CLASSIC";
                break;

            case GOLD:
                vrstaRacuna = "GOLD";
                break;

            case VIP:
                vrstaRacuna = "VIP";
        }
        cout << this->vlasnikIme << " " << this->vlasnikPrezime << " – " << vrstaRacuna << " – " << this->stanje << endl;
    }
};

int main() {
    Racun racun = Racun("   PetarPetarPetarPetarPetarPetarPetarPetarPetarPetarPetar                                                                              ", "                                                                             PetrovicPetrovicPetrovicPetrovicPetrovicPetrovicPetrovicPetrovic      ");
    racun.uplata(123);
    racun.stampa();  // PetarPetarPetarPetar PetrovicPetrovicPetrovicPetrov - CLASSIC - 123

    racun = Racun("                                                   ", "PetrovicPetrovicP      ");
    racun.stampa();  //  PetrovicPetrovicP - CLASSIC - 0

    racun = Racun("", "      PetrovicPetrovicP");
    racun.stampa();  //  PetrovicPetrovicP - CLASSIC - 0

    racun = Racun("PetarPetarPetarPetarPetarPetarPetarPetarPetarPetarPetar", "PetrovicPetrovicPetrovicPetrovicPetrovicPetrovicPetrovicPetrovic");
    racun.stampa();  // PetarPetarPetarPetar PetrovicPetrovicPetrovicPetrov - CLASSIC - 0

    racun = Racun("Petar", "Petrovic", CLASSIC);
    racun.uplata(-123);
    racun.stampa();  // Petar Petrovic - CLASSIC - 0

    racun = Racun("Petar", "Petrovic", GOLD, 123);
    racun.isplata(23);
    racun.stampa();  // Petar Petrovic - GOLD - 100

    racun = Racun("Petar", "Petrovic", VIP, -123);
    cout << racun.getVlasnikIme() << " " << racun.getVlasnikPrezime() << " - " << racun.getVrstaRacuna() << " - " << racun.getStanje() << endl;  // Petar Petrovic - 2 - 0

    racun.setVrstaRacuna(CLASSIC);
    racun.setStanje(10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 1000

    racun.setVrstaRacuna(GOLD);
    racun.setStanje(10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 500

    racun.setVrstaRacuna(VIP);
    racun.setStanje(10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 0

    racun = Racun("Petar", "Petrovic");
    racun.stampa();  // Petar Petrovic - CLASSIC - 0

    racun = Racun("Petar", "Petrovic", GOLD);
    racun.stampa();  // Petar Petrovic - GOLD - 0

    racun = Racun("Petar", "Petrovic", VIP, 123);
    racun.stampa();  // Petar Petrovic - VIP - 123

    racun = Racun("Petar", "Petrovic");
    racun.setStanje(-123);
    cout << racun.getVlasnikIme() << " " << racun.getVlasnikPrezime() << " - " << racun.getVrstaRacuna() << " - " << racun.getStanje() << endl;
    // Petar Petrovic - 0 - 0

    racun = Racun("Petar", "Petrovic", CLASSIC, 0);
    racun.uplata(123);
    cout << racun.getStanje() << endl;  // 123

    racun = Racun("Petar", "Petrovic", CLASSIC, 0);
    racun.uplata(-123);
    cout << racun.getStanje() << endl;  // 0

    racun = Racun("Petar", "Petrovic", CLASSIC, 123);
    racun.isplata(23);
    cout << racun.getStanje() << endl;  // 100

    racun = Racun("Petar", "Petrovic", CLASSIC, 10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 1000

    racun = Racun("Petar", "Petrovic", GOLD, 10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 500

    racun = Racun("Petar", "Petrovic", VIP, 10000);
    racun.isplata(11000);
    cout << racun.getStanje() << endl;  // 0

    racun = Racun("Petar", "Petrovic", VIP, 100);
    racun.isplata(-100);
    cout << racun.getStanje() << endl;  // 100

    racun = Racun("Petar", "Petrovic", GOLD, 100);
    racun.isplata(0);
    cout << racun.getStanje() << endl;  // 100

    return 0;
}