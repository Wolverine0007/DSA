#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    char title[100];
    char author[50];
    int copies;

    void insert();
    void Delete(Book books[], int &n);
    void display();
    void update(int search_id);
};

void Book::insert() {
    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Title: ";
    cin.getline(title, 100);
    cout << "Enter Author: ";
    cin.getline(author, 50);
    cout << "Enter Number of Copies: ";
    cin >> copies;
    cout << endl;
}

void Book::Delete(Book books[], int &n) {
    int delete_id;
    cout << "Enter Book ID to DELETE: ";
    cin >> delete_id;

    int i;
    for (i = 0; i < n; i++) {
        if (books[i].id == delete_id) {
            cout << "Book Found. Deleting...\n";
            break;
        }
    }
    if (i == n) {
        cout << "Book not found!\n";
        return;
    }

    for (int j = i; j < n - 1; j++) {
        books[j] = books[j + 1];
    }
    n--;
    cout << "Book Deleted Successfully!\n";
}

void Book::display() {
    cout << "\nBook ID: " << id;
    cout << "\nTitle: " << title;
    cout << "\nAuthor: " << author;
    cout << "\nCopies Available: " << copies << "\n";
}

void Book::update(int search_id) {
    if (id != search_id) {
        return;
    }

    int ch;
    cout << "1. Update Title\n";
    cout << "2. Update Author\n";
    cout << "3. Update Number of Copies\n";
    cout << "4. Update Nothing\n";
    cout << "Enter Your Choice: ";
    cin >> ch;

    switch (ch) {
    case 1:
        cout << "Enter NEW Title: ";
        cin.ignore();
        cin.getline(title, 100);
        break;
    case 2:
        cout << "Enter NEW Author: ";
        cin.ignore();
        cin.getline(author, 50);
        break;
    case 3:
        cout << "Enter NEW Number of Copies: ";
        cin >> copies;
        break;
    case 4:
        cout << "No Updates Made.\n";
        break;
    default:
        cout << "INVALID CHOICE\n";
        break;
    }
} // Correctly closed the function

int main() {
    Book books[100];
    int choice, book_count = 0;
    int total = sizeof(books) / sizeof(books[0]);

    do {
        cout << "\tCOLLEGE LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Insert Book\n2. Display All Books\n3. Update Book\n4. Delete Book\n5. EXIT\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (book_count < total) {
                int entries;
                cout << "How many books to add: ";
                cin >> entries;

                for (int i = 0; i < entries && book_count < total; i++) {
                    books[book_count].insert();
                    book_count++;
                }
                if (book_count == total) {
                    cout << "No more space for new books.\n";
                }
            } else {
                cout << "No more space for new books.\n";
            }
            break;

        case 2:
            for (int i = 0; i < book_count; i++) {
                books[i].display();
            }
            break;

        case 3: {
            int search_id;
            cout << "Enter the Book ID to update: ";
            cin >> search_id;
            bool found = false;
            for (int i = 0; i < book_count; i++) {
                books[i].update(search_id);
                found = true;
            }
            if (!found) {
                cout << "Book not found!\n";
            }
            break;
        }

        case 4:
            books->Delete(books, book_count);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
            break;
        }

    } while (choice != 5);

    return 0;
}

