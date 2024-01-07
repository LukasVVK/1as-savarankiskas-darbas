#include "list.h"

int main() {
    Timer timer;
    std::list<Student> Grupe;  // Naudojamas std::list vietoj std::vector
    std::string failoPavadinimas;

    cout << "Iveskite failo pavadinima: ";
    getline(cin, failoPavadinimas);

    try {
        timer.reset();
        skaitytiIsFailo(failoPavadinimas, Grupe);
        cout << "Laikas, praleistas skaitymui is failo: " << timer.elapsed() << " ms" << endl;
    }
    catch (std::exception& e) {
        std::cerr << "Klaida nuskaitant duomenis is failo: " << e.what() << std::endl;
        return 1;
    }

    timer.reset();
    Grupe.sort();  // std::list turi savo sort() metodą
    cout << "Laikas, praleistas rikiavimui: " << timer.elapsed() << " ms" << endl;

    timer.reset();
    std::list<Student> vargsiukai;
    for (auto it = Grupe.begin(); it != Grupe.end(); ) {
        if (it->getRez() < 5.0) {
            vargsiukai.push_back(std::move(*it));
            it = Grupe.erase(it);
        } else {
            ++it;
        }
    }

    cout << "Laikas, praleistas grupiu atskyrimui: " << timer.elapsed() << " ms" << endl;

    timer.reset();
    std::ofstream vargsiukaiFile("vargsiukai.txt"), kietiakiaiFile("kietiakiai.txt");
    if (!vargsiukaiFile || !kietiakiaiFile) {
        std::cerr << "Nepavyko atidaryti isvesties failu." << std::endl;
        return 1;
    }
    std::cout << "Laikas, praleistas failu kurimui: " << timer.elapsed() << " ms" << std::endl;

    for (const auto& v : vargsiukai) vargsiukaiFile << v;
    for (const auto& k : Grupe) kietiakiaiFile << k;  // Dabar Grupe yra tik kietiakiai

    vargsiukaiFile.close();
    kietiakiaiFile.close();
    cout << "Laikas, praleistas rasant i failus: " << timer.elapsed() << " ms" << endl;

    return 0;
}
