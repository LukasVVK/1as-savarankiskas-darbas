#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int minimum(int a, int b);

class Student {
    string Name, Surname;
    vector<int> HW;
    int Exam;
    float Rez;

public:
    Student();
    Student(string N, string S, vector<int> H, int E);
    Student(const Student& A);
    Student& operator=(const Student& A);
    ~Student();

    float Vid();
    float Med();
    void Result(char pas);
    void printas();

    friend std::istream& operator>>(std::istream& in, Student& S);
    friend std::ostream& operator<<(std::ostream& out, const Student& S);
};
