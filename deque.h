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
#include <chrono>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Timer {
public:
    Timer() : start_(std::chrono::high_resolution_clock::now()) {}
    void reset() {
        start_ = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now() - start_).count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};

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
    float getRez() const { return Rez; }  // Getter for Rez

    friend std::istream& operator>>(std::istream& in, Student& S);
    friend std::ostream& operator<<(std::ostream& out, const Student& S);
    friend bool operator<(const Student& a, const Student& b);
};

int minimum(int a, int b);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::deque<Student>& Grupe);
