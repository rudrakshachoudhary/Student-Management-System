#include "../include/Student.h"

int main()
{
    welcomeScreen();
    vector<Student> students;

      loadFromFile(students);

    int choice;

    while(true)
    {

        cout << "=======================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM\n";
        cout << "=======================================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Student Statistics\n";
        cout << "7: Sort Students\n";
        cout << "8. Exit\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                deleteStudent(students);
                break;

            case 5:
                updateStudent(students);
                break;

            case 6:
                studentStatistics(students);
                break;

            case 7:
                sortStudents(students);
                break;

            case 8:
                saveToFile(students);
                cout << "\nThank you for using Student Management System!\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }

    
}