#include "Header1.h"

int main() {
    vector<Student> Grupe;
    int studentuSkaicius;

    cout << "Kiek studentu norite ivesti? ";
    cin >> studentuSkaicius;

    for (int i = 0; i < studentuSkaicius; i++) {
        Student Laikinas;
        cin >> Laikinas;
        Grupe.push_back(Laikinas);
    }

    cout << std::setw(15) << std::left << "Pavarde" << " " << std::setw(15) << "Vardas" << " " << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (const auto& duom : Grupe) {
        cout << duom;
    }

    return 0;
}
