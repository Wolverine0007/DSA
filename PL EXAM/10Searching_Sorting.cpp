#include <bits/stdc++.h>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
    string department;

    Student(int r, string n, float s, string d) : rollNo(r), name(n), sgpa(s), department(d) {}
};

// Function to implement Bubble Sort based on Roll Number
void bubbleSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Function to implement Insertion Sort based on Student Names (Alphabetical Order)
void insertionSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Quick Sort Helper Functions (For Sorting by SGPA)
int partition(vector<Student>& students, int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (students[j].sgpa >= pivot) {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

// Linear Search to find students by SGPA
void linearSearchBySGPA(const vector<Student>& students, float searchSGPA) {
    bool found = false;
    for (const auto& student : students) {
        if (student.sgpa == searchSGPA) {
            found = true;
            cout << "Student Name: " << student.name << ", Roll No: " << student.rollNo << ", SGPA: " << student.sgpa << ", Department: " << student.department << endl;
        }
    }
    if (!found) {
        cout << "No students found with SGPA: " << searchSGPA << endl;
    }
}

// Binary Search to find a student by Name (Non-Recursive)
void binarySearchByName(vector<Student>& students, const string& searchName) {
    int low = 0, high = students.size() - 1;
    bool found = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].name == searchName) {
            found = true;
            cout << "Student found: " << students[mid].name << ", Roll No: " << students[mid].rollNo << ", SGPA: " << students[mid].sgpa << ", Department: " << students[mid].department << endl;
            break;
        } else if (students[mid].name < searchName) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        cout << "Student with name " << searchName << " not found." << endl;
    }
}

// Fibonacci Search to check if student belongs to a specific department
void fibonacciSearch(const vector<Student>& students, const string& department) {
    int n = students.size();
    int fibM_minus_2 = 0; // (m-2)th Fibonacci number
    int fibM_minus_1 = 1; // (m-1)th Fibonacci number
    int fibM = fibM_minus_2 + fibM_minus_1; // mth Fibonacci number

    while (fibM < n) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_2 + fibM_minus_1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM_minus_2, n - 1);

        if (students[i].department < department) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        } else if (students[i].department > department) {
            fibM = fibM_minus_2;
            fibM_minus_1 -= fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        } else {
            cout << "Student " << students[i].name << " is from the " << department << " department." << endl;
            return;
        }
    }

    if (fibM_minus_1 && offset + 1 < n && students[offset + 1].department == department) {
        cout << "Student " << students[offset + 1].name << " is from the " << department << " department." << endl;
        return;
    }

    cout << "No students found in the " << department << " department." << endl;
}

int main() {
    // Student records
    vector<Student> students = {
        Student(1, "Alice", 8.5, "Computer"),
        Student(2, "Bob", 9.1, "Electrical"),
        Student(3, "Charlie", 7.9, "Computer"),
        Student(4, "David", 8.2, "Mechanical"),
        Student(5, "Eve", 9.3, "Computer"),
        Student(6, "Frank", 8.0, "Electrical"),
        Student(7, "Grace", 7.8, "Mechanical"),
        Student(8, "Hannah", 9.0, "Civil"),
        Student(9, "Ivy", 8.4, "Computer"),
        Student(10, "Jack", 8.6, "Electrical"),
        Student(11, "Kevin", 7.5, "Mechanical"),
        Student(12, "Liam", 9.2, "Computer"),
        Student(13, "Mona", 8.8, "Civil"),
        Student(14, "Nina", 9.4, "Electrical"),
        Student(15, "Oscar", 7.7, "Mechanical")
    };

    // 1. Roll Call List - Bubble Sort by Roll Number
    cout << "Roll Call List (Sorted by Roll No):" << endl;
    bubbleSort(students);
    for (const auto& student : students) {
        cout << student.rollNo << " " << student.name << " " << student.sgpa << " " << student.department << endl;
    }

    // 2. Alphabetical List - Insertion Sort by Name
    cout << "\nAlphabetical List (Sorted by Name):" << endl;
    insertionSort(students);
    for (const auto& student : students) {
        cout << student.name << " " << student.rollNo << " " << student.sgpa << " " << student.department << endl;
    }

    // 3. Top Ten Toppers - Quick Sort by SGPA
    cout << "\nTop Ten Toppers (Sorted by SGPA):" << endl;
    quickSort(students, 0, students.size() - 1);
    for (int i = 0; i < 10 && i < students.size(); i++) {
        cout << students[i].name << " " << students[i].sgpa << " " << students[i].department << endl;
    }

    // 4. Search by SGPA (Linear Search)
    cout << "\nSearch Students by SGPA (Enter SGPA to search): ";
    float searchSGPA;
    cin >> searchSGPA;
    linearSearchBySGPA(students, searchSGPA);


    // 5. Search by Name (Binary Search)
    cout << "\nSearch Student by Name (Enter Name to search): ";
    string searchName;
    cin >> searchName;
    binarySearchByName(students, searchName);

    // 6. Fibonacci Search for 'Computer' Department
    cout << "\nCheck if student belongs to Computer Department (Enter department): ";
    string department;
    cin >> department;
    fibonacciSearch(students, department);

    return 0;
}

