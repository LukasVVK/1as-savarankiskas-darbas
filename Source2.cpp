#include "Header1.h"

int main() {
    std::vector<Student> Grupe;
    std::string failoPavadinimas;

    std::cout << "Iveskite failo pavadinima: ";
    std::getline(std::cin, failoPavadinimas);

    try {
        skaitytiIsFailo(failoPavadinimas, Grupe);
    }
    catch (std::exception& e) {
        std::cerr << "Klaida nuskaitant duomenis is failo: " << e.what() << std::endl;
        return 1;
    }

    std::sort(Grupe.begin(), Grupe.end());

    std::cout << std::setw(15) << std::left << "Pavardė" << " "
        << std::setw(15) << "Vardas" << " "
        << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    for (const auto& studentas : Grupe) {
        std::cout << studentas;
    }

    return 0;
}

int minimum(int a, int b) {
    return a < b ? a : b;
}
