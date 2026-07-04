# Student Management System

A menu-driven Student Management System developed in **C++** to practice **Object-Oriented Programming (OOP)**, **STL**, and **File Handling** concepts.

This project allows users to manage student records through a simple console-based interface. Student information is stored in a text file, ensuring that data is preserved even after the program is closed.

---

## Project Objective

The objective of this project was to strengthen my understanding of C++ programming by implementing a real-world console application using Object-Oriented Programming, STL, file handling, searching, sorting, and modular programming concepts.

---

## Features

- Add New Student
- Display All Students
- Search Student
  - By Roll Number
  - By Name (Case-insensitive & Partial Search)
- Update Student Details
- Delete Student (with Confirmation)
- Sort Students
  - Roll Number (Ascending / Descending)
  - Name (A-Z)
  - CGPA (Ascending / Descending)
- Student Statistics
  - Total Students
  - Highest CGPA
  - Lowest CGPA
  - Average CGPA
- Duplicate Roll Number Validation
- CGPA Validation
- Persistent Data Storage using File Handling

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- File Handling (`fstream`)
- Vectors
- Custom Comparator Functions
- Modular Programming
- Git & GitHub

---

## Project Structure

```text
Student-Management-System
│
├── data
│   └── students.txt
│
├── include
│   └── Student.h
│
├── src
│   ├── Student.cpp
│   └── main.cpp
│
├── README.md
└── .gitignore
```

---

## How to Run

### Clone the repository

```bash
git clone https://github.com/rudrakshachoudhary/Student-Management-System.git
```

### Navigate to the project directory

```bash
cd Student-Management-System
```

### Compile the project

```bash
g++ src/main.cpp src/Student.cpp -o StudentManagementSystem
```

### Run the application

**Windows (PowerShell)**

```powershell
.\StudentManagementSystem.exe
```

---

## What I Learned

Through this project, I gained practical experience in:

- Object-Oriented Programming in C++
- Classes and Objects
- Header Files and Source Files
- Modular Programming
- File Handling using `fstream`
- STL Vectors
- Searching and Sorting Algorithms
- Custom Comparator Functions
- Input Validation
- Using Git and GitHub for Version Control

---

## Future Improvements

- Graphical User Interface (GUI)
- Database Integration
- Login Authentication
- Export Reports (CSV/PDF)
- Student Attendance Management

---

## Author

**Rudraksha Choudhary**

GitHub: https://github.com/rudrakshachoudhary