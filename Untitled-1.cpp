#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Structure to store student information
struct Student
{
    int id;
    string firstName;
    string middleName;
    string lastName;
    char gender;
    float mathScore;
    float programmingScore;
    float physicsScore;
};

// Function prototypes
void fillData(vector<Student>& students);
void displayData(const vector<Student>& students);
void searchByName(const vector<Student>& students);
void displayAverageByID(const vector<Student>& students);

int main()
{
    vector<Student> students(10); // Vector to hold 10 students
    int choice;

    do
    {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Fill all students' data\n";
        cout << "2. Display all students' data\n";
        cout << "3. Search for a student by name\n";
        cout << "4. Display average score by student ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                fillData(students);
                break;
            case 2:
                displayData(students);
                break;
            case 3:
                searchByName(students);
                break;
            case 4:
                displayAverageByID(students);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to fill data for 10 students
void fillData(vector<Student>& students)
{
    for (int i = 0; i < students.size(); ++i)
    {
        cout << "\nEnter data for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cout << "First Name: ";
        cin >> students[i].firstName;
        cout << "Middle Name: ";
        cin >> students[i].middleName;
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Gender (M/F): ";
        cin >> students[i].gender;
        cout << "Math Score: ";
        cin >> students[i].mathScore;
        cout << "Programming Score: ";
        cin >> students[i].programmingScore;
        cout << "Physics Score: ";
        cin >> students[i].physicsScore;
    }
}

// Function to display all students' data
void displayData(const vector<Student>& students)
{
    cout << "\nStudent Data:\n";
    cout << setw(5) << "ID" << setw(15) << "Name" << setw(8) << "Gender"
         << setw(10) << "Math" << setw(12) << "Programming" << setw(8) << "Physics" << endl;
    cout << string(58, '-') << endl;

    for (const auto& student : students) {
        cout << setw(5) << student.id
             << setw(15) << (student.firstName + " " + student.middleName + " " + student.lastName)
             << setw(8) << student.gender
             << setw(10) << student.mathScore
             << setw(12) << student.programmingScore
             << setw(8) << student.physicsScore << endl;
    }
}

// Function to search for a student by name
void searchByName(const vector<Student>& students)
{
    string name;
    cout << "Enter the student's first name to search: ";
    cin >> name;

    bool found = false;
    for (const auto& student : students) {
        if (student.firstName == name)
        {
            cout << "\nStudent found:\n";
            cout << "ID: " << student.id << "\n"
                 << "Name: " << student.firstName << " " << student.middleName << " " << student.lastName << "\n"
                 << "Gender: " << student.gender << "\n"
                 << "Math Score: " << student.mathScore << "\n"
                 << "Programming Score: " << student.programmingScore << "\n"
                 << "Physics Score: " << student.physicsScore << "\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with the name \"" << name << "\" not found.\n";
    }
}

// Function to display average score by student ID
void displayAverageByID(const vector<Student>& students)
{
    int id;
    cout << "Enter the student ID to calculate the average score: ";
    cin >> id;

    bool found = false;
    for (const auto& student : students) {
        if (student.id == id)
        {
            float average = (student.mathScore + student.programmingScore + student.physicsScore) / 3.0;
            cout << "Average score for student ID " << id << ": " << average << "\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with ID " << id << " not found.\n";
    }
}