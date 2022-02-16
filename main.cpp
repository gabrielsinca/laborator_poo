#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Forme {
    public:
        float h;
        string f;
        float gem;
        float frisca;
//        bool stop;
        Forme(float h, string f, float gem, float frisca) {
            this->h = h;
            this->f = f;
            this->gem = gem;
            this->frisca = frisca;
        }
};

Forme* rez[100];
int c = 0;
void add(float h, string f) {
    float frisca = 0, gem = 0;
    Forme* forma = new Forme(h, f, gem, frisca);
    if (f == "cerc") {
        float r;
        cin >> r;
        frisca = M_PI * r * r;
        gem = frisca * forma->h;
    } else if (f == "patrat") {
        float l;
        cin >> l;
        frisca = l * l;
        gem = frisca * forma->h;
    } else if (f == "dreptunghi") {
        float lun, lat;
        cin >> lun >> lat; // lungime, latime
        frisca = lun * lat;
        gem = frisca * forma->h;
    } else if (f == "triunghi") {
        float c1, c2;
        cin >> c1 >> c2;
        frisca = c1 * c2;
        gem = frisca * forma->h;
    }
    forma->gem = gem;
    forma->frisca = frisca;
    c++;
}

int main() {
    float h, gem = 0, frisca = 0;
    string f;
    bool s = true;
    cin >> h;
    cin >> f;
//    Forme forma(h, f, gem, frisca, s);

    cout << frisca << ' ' << gem;

    while (s) {
        string cmd;
        cin >> cmd;
        if (cmd == "STOP")
            s = false;
        if (cmd == "ADD") {
//            add();
        }
    }


    return 0;
}
