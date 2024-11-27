#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 15;

class Student {
public:
    int rollNo;
    string name;
    float sgpa;
    string department;

    Student() : rollNo(0), name(""), sgpa(0.0), department("") {}
    Student(int r, string n, float s, string d) : rollNo(r), name(n), sgpa(s), department(d) {}
};

class StudentDatabase {
private:
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentDatabase() : count(0) {}

    void addStudent() {
        if (count < MAX_STUDENTS) {
            int rollNo;
            string name;
            float sgpa;
            string department;

            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name (single word): ";
            cin >> name;
            cout << "Enter SGPA: ";
            cin >> sgpa;
            cout << "Enter Department (single word): ";
            cin >> department;

            students[count++] = Student(rollNo, name, sgpa, department);
        } else {
            cout << "Database is full!" << endl;
        }
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
                 << ", SGPA: " << students[i].sgpa << ", Department: " << students[i].department << endl;
        }
    }

    // a) Bubble Sort - Sort by Roll Number
    void sortByRollNo() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (students[j].rollNo > students[j + 1].rollNo) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    // b) Insertion Sort - Sort by Name
    void sortByName() {
        for (int i = 1; i < count; i++) {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && students[j].name > key.name) {
                students[j + 1] = students[j];
                j--;
            }
            students[j + 1] = key;
        }
    }

    // c) Quick Sort - Sort by SGPA to find top 10
    int partition(int low, int high) {
        float pivot = students[high].sgpa;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (students[j].sgpa > pivot) {
                i++;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        return i + 1;
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void displayTop10() {
        quickSort(0, count - 1);
        for (int i = 0; i < 10 && i < count; i++) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
                 << ", SGPA: " << students[i].sgpa << endl;
        }
    }

    // d) Linear Search by SGPA
    void searchBySGPA(float sgpa) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i].sgpa == sgpa) {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
                     << ", Department: " << students[i].department << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No student found with SGPA " << sgpa << endl;
        }
    }

    // e) Binary Search by Name
    int binarySearchByName(string name) {
        int low = 0, high = count - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (students[mid].name == name) {
                return mid;
            } else if (students[mid].name < name) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    void searchByName(string name) {
        sortByName();
        int index = binarySearchByName(name);
        if (index != -1) {
            cout << "Roll No: " << students[index].rollNo << ", Name: " << students[index].name
                 << ", SGPA: " << students[index].sgpa << ", Department: " << students[index].department << endl;
        } else {
            cout << "No student found with name " << name << endl;
        }
    }

    // f) Fibonacci Search by Department
    bool fibonacciSearchByDepartment(string department) {
        int fib2 = 0, fib1 = 1;
        int fibM = fib2 + fib1;
        while (fibM < count) {
            fib2 = fib1;
            fib1 = fibM;
            fibM = fib2 + fib1;
        }
        int offset = -1;
        while (fibM > 1) {
            int i = min(offset + fib2, count - 1);
            if (students[i].department < department) {
                fibM = fib1;
                fib1 = fib2;
                fib2 = fibM - fib1;
                offset = i;
            } else if (students[i].department > department) {
                fibM = fib2;
                fib1 = fib1 - fib2;
                fib2 = fibM - fib1;
            } else {
                return true;
            }
        }
        return (fib1 && students[offset + 1].department == department);
    }
};

int main() {
    StudentDatabase db;
    int numOfStudents;

    cout << "Enter the number of students to add (up to " << MAX_STUDENTS << "): ";
    cin >> numOfStudents;

    for (int i = 0; i < numOfStudents; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        db.addStudent();
    }

    cout << "\nOriginal List:" << endl;
    db.display();

    cout << "\nSorted by Roll Number:" << endl;
    db.sortByRollNo();
    db.display();

    cout << "\nSorted by Name:" << endl;
    db.sortByName();
    db.display();

    cout << "\nTop 10 Students by SGPA:" << endl;
    db.displayTop10();

    cout << "\nSearching by SGPA 8.9:" << endl;
    db.searchBySGPA(8.9);

    cout << "\nSearching by Name 'Charlie':" << endl;
    db.searchByName("Charlie");

    cout << "\nChecking if any student is in Computer department:" << endl;
    if (db.fibonacciSearchByDepartment("Computer")) {
        cout << "Student(s) found in Computer department" << endl;
    } else {
        cout << "No student found in Computer department" << endl;
    }

    return 0;
}
