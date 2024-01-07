#include "list.h"
#include <iterator>

int main() {
    Timer timer;
    std::list<Student> Grupe;
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
    Grupe.sort();
    cout << "Laikas, praleistas rikiavimui: " << timer.elapsed() << " ms" << endl;

    timer.reset();
    std::list<Student> vargsiukai, kietiakiai;
    for (const auto& studentas : Grupe) {
        if (studentas.getRez() < 5.0) vargsiukai.push_back(studentas);
        else kietiakiai.push_back(studentas);
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
    for (const auto& k : kietiakiai) kietiakiaiFile << k;
    vargsiukaiFile.close();
    kietiakiaiFile.close();
    cout << "Laikas, praleistas rasant i failus: " << timer.elapsed() << " ms" << endl;

    return 0;
}
