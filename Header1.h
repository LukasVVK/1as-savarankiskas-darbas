#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Student {
    string Name, Surname;
    vector<int> HW;
    int Exam;
    float Rez;

public:
    Student() : Exam(0), Rez(0.0) {}
    Student(string N, string S, vector<int> H, int E);
    Student(const Student& A);
    Student& operator=(const Student& A);
    ~Student();

    float Vid();
    float Med();
    void Result(char pas);
    void printas() const;

    friend std::istream& operator>>(std::istream& in, Student& S);
    friend std::ostream& operator<<(std::ostream& out, const Student& S);
    friend bool operator<(const Student& a, const Student& b);
};

int minimum(int a, int b);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Student>& Grupe);
