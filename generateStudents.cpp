#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>

void generateStudents(const std::string& filename, int count) {
    std::ofstream file(filename);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    if (!file) {
        std::cerr << "Negalima atidaryti failo: " << filename << std::endl;
        return;
    }

    int nameWidth = 15;
    int scoreWidth = 8;

    file << std::left << std::setw(nameWidth) << "Pavarde"
         << std::setw(nameWidth) << "Vardas"
         << std::setw(scoreWidth) << "ND1"
         << std::setw(scoreWidth) << "ND2"
         << std::setw(scoreWidth) << "ND3"
         << std::setw(scoreWidth) << "ND4"
         << std::setw(scoreWidth) << "ND5"
         << std::setw(scoreWidth) << "Egzaminas" << std::endl;

    for (int i = 1; i <= count; ++i) {
        std::ostringstream pavarde, vardas;
        pavarde << "Pavarde" << i;
        vardas << "Vardas" << i;

        file << std::left
             << std::setw(nameWidth) << pavarde.str()
             << std::setw(nameWidth) << vardas.str()
             << std::setw(scoreWidth) << dis(gen)
             << std::setw(scoreWidth) << dis(gen)
             << std::setw(scoreWidth) << dis(gen)
             << std::setw(scoreWidth) << dis(gen)
             << std::setw(scoreWidth) << dis(gen)
             << std::setw(scoreWidth) << dis(gen) << std::endl;
    }

    file.close();
    std::cout << "Sukurtas failas: " << filename << " su " << count << " irasais." << std::endl;
}

int main() {
    generateStudents("1000_studentu.txt", 1000);
    generateStudents("10000_studentu.txt", 10000);
    generateStudents("100000_studentu.txt", 100000);
    generateStudents("1000000_studentu.txt", 1000000);

    return 0;
}
