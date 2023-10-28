#include "Header1.h"

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
    HW.clear();
}

float Student::Vid() {
    return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size();
}

float Student::Med() {
    std::sort(HW.begin(), HW.end());
    size_t n = HW.size();
    return (n % 2 == 0) ? (HW[n / 2 - 1] + HW[n / 2]) / 2.0 : HW[n / 2];
}

void Student::Result(char pas) {
    if (pas == 'v') {
        Rez = 0.4 * Vid() + 0.6 * Exam;
    }
    else {
        Rez = 0.4 * Med() + 0.6 * Exam;
    }
}

void Student::printas() const {
    cout << std::setw(15) << std::left << Surname << " " << std::setw(15) << Name << " ";
    cout << std::fixed << std::setprecision(2) << Rez << endl;
}

std::istream& operator>>(std::istream& in, Student& S) {
    S.HW.clear();
    in >> S.Name >> S.Surname;

    int ndPazymys;
    while (in >> ndPazymys) {
        S.HW.push_back(ndPazymys);
    }

    if (S.HW.size() > 0) {
        S.Exam = S.HW.back();
        S.HW.pop_back();
    }
    else {
        S.Exam = 0;
    }

    S.Result('v');

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& S) {
    out << std::setw(15) << std::left << S.Surname << " "
        << std::setw(15) << S.Name << " "
        << std::setw(20) << std::fixed << std::setprecision(2) << S.Rez << std::endl;
    return out;
}

bool operator<(const Student& a, const Student& b) {
    return a.Surname < b.Surname;
}

void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Student>& Grupe) {
    std::ifstream in(failoPavadinimas);
    if (!in) {
        std::cerr << "Negalima atidaryti failo skaitymui: " << failoPavadinimas << std::endl;
        throw std::runtime_error("Negalima atidaryti failo skaitymui.");
    }

    std::string eilute;
    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        Student S;
        iss >> S;
        Grupe.push_back(S);
    }

    in.close();
}
