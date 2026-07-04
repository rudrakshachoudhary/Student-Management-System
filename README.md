# 🎓 Student Management System

A menu-driven **Student Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts. The application allows users to efficiently manage student records through an interactive console interface.

---

## ✨ Features

- ➕ Add Student
- 📋 Display Students (Professional Table Format)
- 🔍 Search Student
  - By Roll Number
  - By Name (Case-insensitive & Partial Search)
- ✏️ Update Student Details
- ❌ Delete Student (with Confirmation)
- 📊 Student Statistics
  - Total Students
  - Highest CGPA
  - Lowest CGPA
  - Average CGPA
- 📂 File Handling (Data saved in `students.txt`)
- 🔃 Sort Students
  - Roll Number (Ascending / Descending)
  - Name (A-Z)
  - CGPA (Ascending / Descending)
- ✅ Duplicate Roll Number Validation
- ✅ CGPA Input Validation

---

## 🛠 Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- File Handling (`fstream`)
- Vectors
- Sorting Algorithms
- Modular Programming

---

## 📁 Project Structure

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

## 🚀 How to Run

### Clone the repository

```bash
git clone https://github.com/rudrakshachoudhary/Student-Management-System.git
```

### Go to the project folder

```bash
cd Student-Management-System
```

### Compile

```bash
g++ src/main.cpp src/Student.cpp -o StudentManagementSystem
```

### Run

```bash
./StudentManagementSystem
```

> On Windows PowerShell:

```powershell
.\StudentManagementSystem.exe
```

---

## 🎯 Future Improvements

- GUI Version
- Login Authentication
- Database Integration
- Export Reports (PDF / CSV)
- Attendance Management
- Student Performance Analytics

---

## 👨‍💻 Author

**Rudraksha Choudhary**

GitHub: https://github.com/rudrakshachoudhary

---

## ⭐ If you like this project

Please consider giving it a ⭐ on GitHub.