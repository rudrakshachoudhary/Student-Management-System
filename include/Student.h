#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

class Student
{
public:
    int rollNo;
    string fullname;
    string branch;
    float cgpa;
};

// Comparator Functions
bool compareRollAscending(Student a, Student b);
bool compareRollDescending(Student a, Student b);
bool compareCGPAAscending(Student a, Student b);
bool compareCGPADescending(Student a, Student b);
bool compareName(Student a, Student b);

// Helper Functions
string toLowerCase(string text);
void welcomeScreen();
void displayStudentDetails(Student student);

// File Handling
void saveToFile(vector<Student>& students);
void loadFromFile(vector<Student>& students);

// Main Features
void addStudent(vector<Student>& students);
void displayStudents(vector<Student>& students);
void searchStudent(vector<Student>& students);
void searchByRollNumber(vector<Student>& students);
void searchByName(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void updateStudent(vector<Student>& students);
void studentStatistics(vector<Student>& students);
void sortStudents(vector<Student>& students);

#endif