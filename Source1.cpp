#include "Header1.h"

int minimum(int a, int b) {
    return a < b ? a : b;
}

Student::Student() : Exam(0), Rez(0.0) {}

Student::Student(string N, string S, vector<int> H, int E) : Name(N), Surname(S), HW(H), Exam(E) {
    Result('v');
}

Student::Student(const Student& A) : Name(A.Name), Surname(A.Surname), HW(A.HW), Exam(A.Exam), Rez(A.Rez) {}

Student& Student::operator=(const Student& A) {
    if (this == &A) return *this;
    Name = A.Name;
    Surname = A.Surname;
    HW = A.HW;
    Exam = A.Exam;
    Rez = A.Rez;
    return *this;
}

Student::~Student() {
    Name.clear();
    Surname.clear();
    HW.clear();
    Exam = 0;
    Rez = 0;
}

float Student::Vid() {
    return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size() * 1.0;
}

float Student::Med() {
    std::sort(HW.begin(), HW.end());
    int n = HW.size() / 2;
    return
        (n % 2 == 1) ? HW[n] / 1.0 :
        (HW[n] + HW[n + 1]) / 2.0;
}

void Student::Result(char pas) {
    if (pas == 'v') {
        Rez = 0.4 * Vid() + 0.6 * Exam;
    }
    else {
        Rez = 0.4 * Med() + 0.6 * Exam;
    }
}

void Student::printas() {
    cout << std::setw(15) << std::left << Surname << " " << std::setw(15) << Name << " ";
    cout << std::fixed << std::setprecision(2) << Rez << endl;
}

std::istream& operator>>(std::istream& in, Student& S) {
    cout << "Iveskite studento varda: ";
    in >> S.Name;
    cout << "Iveskite studento pavarde: ";
    in >> S.Surname;

    cout << "Iveskite namu darbu pazymius (iveskite neigiama skaiciu, kad baigtumete): ";
    int ndPazymys;
    while (true) {
        in >> ndPazymys;
        if (ndPazymys < 0) break;
        S.HW.push_back(ndPazymys);
    }

    cout << "Iveskite egzamino pazymi: ";
    in >> S.Exam;

    char pasirinkimas;
    cout << "Ar norite skaiciuoti pagal vidurki (v) ar mediana (m)? ";
    in >> pasirinkimas;
    S.Result(pasirinkimas);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& S) {
    out << std::setw(15) << std::left << S.Surname << " " << std::setw(15) << S.Name << " ";
    out << std::fixed << std::setprecision(2) << S.Rez << endl;
    return out;
}
