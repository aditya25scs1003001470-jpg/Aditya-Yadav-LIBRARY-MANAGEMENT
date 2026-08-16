#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string course;
    string department;
    float cgpa;
};

vector<Student> students;
const string FILE_NAME = "students.txt";

// Load students from file
void loadStudents()
{
    ifstream file(FILE_NAME);

    Student s;

    while (file >> s.id)
    {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);

        getline(file, s.department);

        file >> s.cgpa;

        students.push_back(s);
    }

    file.close();
}

// Save students to file
void saveStudents()
{
    ofstream file(FILE_NAME);

    for (const Student &s : students)
    {
        file << s.id << endl;
        file << s.name << endl;
        file << s.age << endl;
        file << s.course << endl;
        file << s.department << endl;
        file << s.cgpa << endl;
    }

    file.close();
}

// Add student
void addStudent()
{
    Student s;

    cout << "\n========== ADD STUDENT ==========\n";

    cout << "Enter Student ID: ";
    cin >> s.id;

    // Check for duplicate ID
    for (const Student &student : students)
    {
        if (student.id == s.id)
        {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter Department: ";
    getline(cin, s.department);

    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    students.push_back(s);

    saveStudents();

    cout << "\nStudent added successfully!\n";
}

// Display students
void displayStudents()
{
    cout << "\n========== STUDENT RECORDS ==========\n";

    if (students.empty())
    {
        cout << "No student records found.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Course"
         << setw(20) << "Department"
         << setw(10) << "CGPA"
         << endl;

    cout << string(95, '-') << endl;

    for (const Student &s : students)
    {
        cout << left
             << setw(10) << s.id
             << setw(25) << s.name
             << setw(10) << s.age
             << setw(20) << s.course
             << setw(20) << s.department
             << setw(10) << fixed << setprecision(2) << s.cgpa
             << endl;
    }
}

// Search student
void searchStudent()
{
    int id;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (const Student &s : students)
    {
        if (s.id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "-----------------------------\n";
            cout << "ID         : " << s.id << endl;
            cout << "Name       : " << s.name << endl;
            cout << "Age        : " << s.age << endl;
            cout << "Course     : " << s.course << endl;
            cout << "Department : " << s.department << endl;
            cout << "CGPA       : " << s.cgpa << endl;

            return;
        }
    }

    cout << "Student not found.\n";
}

// Update student
void updateStudent()
{
    int id;

    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for (Student &s : students)
    {
        if (s.id == id)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, s.course);

            cout << "Enter New Department: ";
            getline(cin, s.department);

            cout << "Enter New CGPA: ";
            cin >> s.cgpa;

            saveStudents();

            cout << "\nStudent updated successfully!\n";

            return;
        }
    }

    cout << "Student not found.\n";
}

// Delete student
void deleteStudent()
{
    int id;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->id == id)
        {
            students.erase(it);

            saveStudents();

            cout << "\nStudent deleted successfully!\n";

            return;
        }
    }

    cout << "Student not found.\n";
}

// Main function
int main()
{
    loadStudents();

    int choice;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "       STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank you for using the Student Management System!\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}