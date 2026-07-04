#include "../include/Student.h"

void welcomeScreen()
{
    cout << "\n";
    cout << "==============================================================\n";
    cout << "             STUDENT MANAGEMENT SYSTEM\n";
    cout << "==============================================================\n";
    cout << " Version      : 1.0\n";
    cout << " Developed By : Rudraksha Choudhary\n";
    cout << " Language     : C++\n";
    cout << " Features     : CRUD | Sorting | Statistics | File Handling\n";
    cout << "==============================================================\n";

    cout << "\nLoading Student Database...\n";

    cout << "\nPress Enter to Continue...";
    cin.ignore();
    cin.get();
}

bool compareRollAscending(Student a, Student b)
{
    return a.rollNo < b.rollNo;
}

bool compareRollDescending(Student a, Student b)
{
    return a.rollNo > b.rollNo;
}

bool compareCGPAAscending(Student a, Student b)
{
    return a.cgpa < b.cgpa;
}

bool compareCGPADescending(Student a, Student b)
{
    return a.cgpa > b.cgpa;
}

bool compareName(Student a, Student b)
{
    return a.fullname < b.fullname;
}

string toLowerCase(string text)
{
    for(int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }

    return text;
}

void displayStudentDetails(Student student)
{
    cout << "\n=========================================\n";
    cout << "          STUDENT DETAILS\n";
    cout << "=========================================\n";

    cout << left << setw(15) << "Roll Number" << ": " << student.rollNo << endl;
    cout << left << setw(15) << "Full Name"   << ": " << student.fullname << endl;
    cout << left << setw(15) << "Branch"      << ": " << student.branch << endl;
    cout << left << setw(15) << "CGPA"        << ": " << fixed << setprecision(2) << student.cgpa << endl;

    cout << "=========================================\n";
}

void saveToFile(vector<Student> &students)
{
    ofstream file("../data/students.txt");

    for(int i=0;i<students.size();i++)
    {
        file<<students[i].rollNo<<endl;
        file<<students[i].fullname<<endl;
        file<<students[i].branch<<endl;
        file<<students[i].cgpa<<endl;
    }

    file.close();
}

void loadFromFile(vector<Student> &students)
{
    ifstream file("../data/students.txt");

    Student temp;

    while(file>>temp.rollNo)
    {
        file.ignore();

        getline(file,temp.fullname);

        getline(file,temp.branch);

        file>>temp.cgpa;

        file.ignore();

        students.push_back(temp);
    }

    file.close();
}

void addStudent(vector<Student> &students)
{
    Student newStudent;
    bool exists = false;

    while(true)
    {
        exists = false;

        cout << "Enter Roll Number : ";
        cin >> newStudent.rollNo;

        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].rollNo == newStudent.rollNo)
            {
                exists = true;
                break;
            }
        }

        if(exists)
        {
            cout << "\n=====================================\n";
            cout << "Roll Number Already Exists!\n";
            cout << "Please Enter Another Roll Number.\n";
            cout << "=====================================\n";
        }
        else
        {
            break;
        }
    }

    cin.ignore();

    cout << "Enter Full Name : ";
    getline(cin, newStudent.fullname);

    cout << "Enter Branch : ";
    getline(cin, newStudent.branch);

    while(true)
    {
        cout << "Enter CGPA : ";
        cin >> newStudent.cgpa;

        if(newStudent.cgpa >= 0 && newStudent.cgpa <= 10)
        {
            break;
        }

        cout << "\n=====================================\n";
        cout << "Invalid CGPA!\n";
        cout << "CGPA must be between 0 and 10.\n";
        cout << "Please Enter Again.\n";
        cout << "=====================================\n";
    }

    students.push_back(newStudent);
    saveToFile(students);

    cout << "\n================================\n";
    cout << "Student Added Successfully!\n";
    cout << "Total Students : " << students.size() << endl;
    cout << "================================\n";
}

void displayStudents(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\n=============================================\n";
        cout << "No Students Found!\n";
        cout << "=============================================\n";
        return;
    }

    cout << "\n====================================================================================================\n";
    cout << left
         << setw(12) << "Roll No"
         << setw(30) << "Full Name"
         << setw(20) << "Branch"
         << setw(10) << "CGPA" << endl;

    cout << "====================================================================================================\n";

    for (int i = 0; i < students.size(); i++)
    {
        cout << left
             << setw(12) << students[i].rollNo
             << setw(30) << students[i].fullname
             << setw(20) << students[i].branch
             << fixed << setprecision(2)
             << setw(10) << students[i].cgpa
             << endl;
    }

    cout << "====================================================================================================\n";

    cout << "\nTotal Students : " << students.size() << endl;
}

void searchByRollNumber(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\n=====================================\n";
        cout << "No Students Found!\n";
        cout << "=====================================\n";
        return;
    }

    int targetRollNo;
    bool found = false;

    cout << "\nEnter Roll Number to Search : ";
    cin >> targetRollNo;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].rollNo == targetRollNo)
        {
            cout << "\nStudent Found!\n";

            displayStudentDetails(students[i]);

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}

void searchByName(vector<Student> &students)
{
    string name;
    bool found = false;
    int count = 0;

    cin.ignore();

    cout << "\nEnter Full Name or Part of Name : ";
    getline(cin, name);

    name = toLowerCase(name);

    cout << "\nSearching...\n\n";

    for(int i = 0; i < students.size(); i++)
    {
        string studentName = toLowerCase(students[i].fullname);

        if(studentName.find(name) != string::npos)
        {
            count++;

            displayStudentDetails(students[i]);

            found = true;
        }
    }

    if(found)
    {
        cout << "\n=====================================\n";
        cout << count << " Student(s) Found!\n";
        cout << "=====================================\n";
    }

    if(!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}

void searchStudent(vector<Student> &students)
{
    if(students.empty())
    {
        cout << "\n=====================================\n";
        cout << "No Students Found!\n";
        cout << "=====================================\n";
        return;
    }

    int choice;

    cout << "\n=====================================\n";
    cout << "         SEARCH MENU\n";
    cout << "=====================================\n";
    cout << "1. Search by Roll Number\n";
    cout << "2. Search by Full Name\n";
    cout << "3. Back\n";
    cout << "=====================================\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
    case 1:

        searchByRollNumber(students);

        break;

    case 2:

        searchByName(students);

        break;

    case 3:

        return;

    default:

        cout << "\nInvalid Choice!\n";
    }
}

void deleteStudent(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\n=====================================\n";
        cout << "No Students Found!\n";
        cout << "=====================================\n";
        return;
    }

    int deleteRollNo;
    bool found = false;

    cout << "\nEnter Roll Number to Delete : ";
    cin >> deleteRollNo;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].rollNo == deleteRollNo)
        {
            found = true;

            cout << "\nStudent Found!\n";

            displayStudentDetails(students[i]);
            
            char confirm;

            cout << "\nAre you sure you want to delete this student? (Y/N): ";
            cin >> confirm;

            if(confirm == 'Y' || confirm == 'y')
            {
                students.erase(students.begin() + i);

                saveToFile(students);

                cout << "\nStudent Deleted Successfully!\n";
                cout << "Total Students : " << students.size() << endl;
            }
            else
            {
                cout << "\nDeletion Cancelled.\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}

void updateStudent(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\n=====================================\n";
        cout << "No Students Found!\n";
        cout << "=====================================\n";
        return;
    }

    int updateRollNo;
    bool found = false;

    cout << "\nEnter Roll Number to Update : ";
    cin >> updateRollNo;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].rollNo == updateRollNo)
        {
            found = true;

            cout << "\nStudent Found!\n";

            displayStudentDetails(students[i]);

            int updateChoice;

            cout << "\n=====================================\n";
            cout << "          UPDATE MENU\n";
            cout << "=====================================\n";
            cout << "1. Update Full Name\n";
            cout << "2. Update Branch\n";
            cout << "3. Update CGPA\n";
            cout << "4. Update All Details\n";
            cout << "5. Cancel\n";
            cout << "=====================================\n";

            cout << "Enter your choice : ";
            cin >> updateChoice;

            cin.ignore();

            switch(updateChoice)
            {
            case 1:

                cout << "\nEnter New Full Name : ";
                getline(cin, students[i].fullname);

                saveToFile(students);

                cout << "\nFull Name Updated Successfully!\n";

                displayStudentDetails(students[i]);

                break;

            case 2:

                cout << "\nEnter New Branch : ";
                getline(cin, students[i].branch);

                saveToFile(students);

                cout << "\nBranch Updated Successfully!\n";

                displayStudentDetails(students[i]);

                break;

            case 3:

                while(true)
                {
                    cout << "\nEnter New CGPA : ";
                    cin >> students[i].cgpa;

                    if(students[i].cgpa >= 0 && students[i].cgpa <= 10)
                    {
                        break;
                    }

                    cout << "\n=====================================\n";
                    cout << "Invalid CGPA!\n";
                    cout << "CGPA must be between 0 and 10.\n";
                    cout << "Please Enter Again.\n";
                    cout << "=====================================\n";
                }

                saveToFile(students);

                cout << "\nCGPA Updated Successfully!\n";

                displayStudentDetails(students[i]);

                break;

            case 4:

                cout << "\nEnter New Full Name : ";
                getline(cin, students[i].fullname);

                cout << "Enter New Branch : ";
                getline(cin, students[i].branch);

                while(true)
                {
                    cout << "\nEnter New CGPA : ";
                    cin >> students[i].cgpa;

                    if(students[i].cgpa >= 0 && students[i].cgpa <= 10)
                    {
                        break;
                    }

                    cout << "\n=====================================\n";
                    cout << "Invalid CGPA!\n";
                    cout << "CGPA must be between 0 and 10.\n";
                    cout << "Please Enter Again.\n";
                    cout << "=====================================\n";
                }

                saveToFile(students);

                cout << "\nAll Details Updated Successfully!\n";

                displayStudentDetails(students[i]);

                break;

            case 5:

                cout << "\nUpdate Cancelled.\n";
                return;

            default:

                cout << "\nInvalid Choice!\n";
                return;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}

void studentStatistics(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "\n=========================================\n";
        cout << "No Students Found!\n";
        cout << "=========================================\n";
        return;
    }

    float highestCGPA = students[0].cgpa;
    float lowestCGPA = students[0].cgpa;
    float totalCGPA = 0;

    int highestIndex = 0;
    int lowestIndex = 0;

    for(int i = 0; i < students.size(); i++)
    {
        totalCGPA += students[i].cgpa;

        if(students[i].cgpa > highestCGPA)
        {
            highestCGPA = students[i].cgpa;
            highestIndex = i;
        }

        if(students[i].cgpa < lowestCGPA)
        {
            lowestCGPA = students[i].cgpa;
            lowestIndex = i;
        }
    }

    float averageCGPA = totalCGPA / students.size();

    cout << "\n=========================================\n";
    cout << "         STUDENT STATISTICS\n";
    cout << "=========================================\n";

    cout << "Total Students : " << students.size() << endl;

    cout << "\nHighest CGPA : " << highestCGPA << endl;
    cout << "\nTopper Details\n";
    displayStudentDetails(students[highestIndex]);

    cout << "\nLowest CGPA  : " << lowestCGPA << endl;
    cout << "\nLowest CGPA Student Details\n";
    displayStudentDetails(students[lowestIndex]);

    cout << "\nAverage CGPA : " << fixed << setprecision(2) << averageCGPA << endl;

    cout << "=========================================\n";
}

void sortStudents(vector<Student> &students)
{
    if(students.empty())
    {
        cout << "\n=====================================\n";
        cout << "No Students Found!\n";
        cout << "=====================================\n";
        return;
    }

    int sortChoice;

    cout << "\n=====================================\n";
    cout << "          SORT MENU\n";
    cout << "=====================================\n";
    cout << "1. Sort by Roll Number\n";
    cout << "2. Sort by Full Name\n";
    cout << "3. Sort by CGPA\n";
    cout << "4. Back\n";
    cout << "=====================================\n";

    cout << "Enter your choice : ";
    cin >> sortChoice;

    switch(sortChoice)
    {
        case 1:
            int orderChoice;

            cout << "\n=====================================\n";
            cout << "        SORT ORDER\n";
            cout << "=====================================\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "3. Back\n";
            cout << "=====================================\n";

            cout << "Enter your choice : ";
            cin >> orderChoice;

            switch(orderChoice)
            {
                case 1:

                    cout << "\nSorting Roll Numbers in Ascending Order...\n";

                    sort(students.begin(), students.end(), compareRollAscending);

                    saveToFile(students);

                    cout << "\nStudents Sorted Successfully!\n";

                    displayStudents(students);

                    break;

                case 2:

                    cout << "\nSorting Roll Numbers in Descending Order...\n";

                    sort(students.begin(), students.end(), compareRollDescending);

                    saveToFile(students);

                    cout << "\nStudents Sorted Successfully!\n";

                    displayStudents(students);

                    break;

                case 3:

                    break;

                default:

                    cout << "\nInvalid Choice!\n";
            }

            break;

        case 2:

            cout << "\nSorting Students Alphabetically...\n";

            sort(students.begin(), students.end(), compareName);

            saveToFile(students);

            cout << "\nStudents Sorted Alphabetically!\n";

            displayStudents(students);

            break;

        case 3:
            int cgpaChoice;

            cout << "\n=====================================\n";
            cout << "        SORT ORDER\n";
            cout << "=====================================\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "3. Back\n";
            cout << "=====================================\n";

            cout << "Enter your choice : ";
            cin >> cgpaChoice;

            switch(cgpaChoice)
            {
                case 1:

                    cout << "\nSorting CGPA in Ascending Order...\n";

                    sort(students.begin(), students.end(), compareCGPAAscending);

                    saveToFile(students);

                    cout << "\nStudents Sorted Successfully!\n";

                    displayStudents(students);

                    break;

                case 2:

                    cout << "\nSorting CGPA in Descending Order...\n";

                    sort(students.begin(), students.end(), compareCGPADescending);

                    saveToFile(students);

                    cout << "\nStudents Sorted Successfully!\n";

                    displayStudents(students);

                    break;

                case 3:

                    break;

                default:

                    cout << "\nInvalid Choice!\n";
            }


            break;

        case 4:

            return;

        default:

            cout << "\nInvalid Choice!\n";
    }
}