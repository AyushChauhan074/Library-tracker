// ============================================
//  library.cpp — Library Book Tracker (Day 1)
//  Core structure: Book struct, globals, menu loop
// ============================================

#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    int    year;
    bool   available; // true = on shelf, false = issued
};

// ── Global book array and count ──
Book library[MAX_BOOKS];
int  bookCount = 0;

void showMenu() {
    cout << "\n======================================";
    cout << "\n       LIBRARY BOOK TRACKER";
    cout << "\n======================================";
    cout << "\n 1. Add a book (coming soon)";
    cout << "\n 2. Remove a book (coming soon)";
    cout << "\n 3. Search by title (coming soon)";
    cout << "\n 4. Search by author (coming soon)";
    cout << "\n 5. Display all books (coming soon)";
    cout << "\n 6. Issue / Return a book (coming soon)";
    cout << "\n 0. Exit";
    cout << "\n--------------------------------------";
    cout << "\nEnter your choice: ";
}

int main() {
    int choice;
    cout << "\nWelcome to the Library Book Tracker!\n";

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                cout << "\nFeature coming soon!\n";
                break;
            case 0:
                cout << "\nGoodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}
