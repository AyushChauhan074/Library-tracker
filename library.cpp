// ============================================
//  library.cpp — Library Book Tracker
//  Concepts used: structs, arrays, functions,
//  loops, conditionals, string comparison
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

// ── Helper: print a divider line ──
void divider() {
    cout << "\n--------------------------------------\n";
}

void printBook(int index) {
    cout << "\n[" << index + 1 << "] " << library[index].title;
    cout << "\n    Author : " << library[index].author;
    cout << "\n    Year   : " << library[index].year;
    cout << "\n    Status : " << (library[index].available ? "Available" : "Issued");
    cout << "\n";
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "\nLibrary is full. Cannot add more books.\n";
        return;
    }

    Book b;
    cout << "\nEnter title  : "; cin.ignore(); getline(cin, b.title);
    cout << "Enter author : "; getline(cin, b.author);
    cout << "Enter year   : "; cin >> b.year;
    b.available = true;

    library[bookCount] = b;
    bookCount++;

    cout << "\nBook added successfully!\n";
}

void removeBook() {
    if (bookCount == 0) {
        cout << "\nNo books in the library.\n";
        return;
    }

    string target;
    cout << "\nEnter title to remove: "; cin.ignore(); getline(cin, target);

    int foundAt = -1;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == target) {
            foundAt = i;
            break;
        }
    }

    if (foundAt == -1) {
        cout << "\nBook not found.\n";
        return;
    }

    // Shift remaining books left to fill the gap
    for (int i = foundAt; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;

    cout << "\nBook removed successfully!\n";
}

void searchByTitle() {
    if (bookCount == 0) {
        cout << "\nNo books in the library.\n";
        return;
    }

    string keyword;
    cout << "\nEnter title to search: "; cin.ignore(); getline(cin, keyword);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        // Check if keyword appears anywhere in the title
        if (library[i].title.find(keyword) != string::npos) {
            printBook(i);
            found = true;
        }
    }

    if (!found) cout << "\nNo books found with that title.\n";
}

void searchByAuthor() {
    if (bookCount == 0) {
        cout << "\nNo books in the library.\n";
        return;
    }

    string keyword;
    cout << "\nEnter author name to search: "; cin.ignore(); getline(cin, keyword);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].author.find(keyword) != string::npos) {
            printBook(i);
            found = true;
        }
    }

    if (!found) cout << "\nNo books found by that author.\n";
}

void displayAll() {
    if (bookCount == 0) {
        cout << "\nNo books in the library.\n";
        return;
    }

    cout << "\nAll Books (" << bookCount << " total):";
    divider();
    for (int i = 0; i < bookCount; i++) {
        printBook(i);
    }
}

// ── Issue / Return a book ──
void toggleAvailability() {
    if (bookCount == 0) {
        cout << "\nNo books in the library.\n";
        return;
    }

    string target;
    cout << "\nEnter title to issue/return: "; cin.ignore(); getline(cin, target);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == target) {
            library[i].available = !library[i].available;
            cout << "\nStatus updated: "
                 << (library[i].available ? "Returned to shelf." : "Issued out.")
                 << "\n";
            return;
        }
    }

    cout << "\nBook not found.\n";
}

void showMenu() {
    cout << "\n======================================";
    cout << "\n       LIBRARY BOOK TRACKER";
    cout << "\n======================================";
    cout << "\n 1. Add a book";
    cout << "\n 2. Remove a book";
    cout << "\n 3. Search by title";
    cout << "\n 4. Search by author";
    cout << "\n 5. Display all books";
    cout << "\n 6. Issue / Return a book";
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
            case 1: addBook();             break;
            case 2: removeBook();          break;
            case 3: searchByTitle();       break;
            case 4: searchByAuthor();      break;
            case 5: displayAll();          break;
            case 6: toggleAvailability();  break;
            case 0:
                cout << "\nGoodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}
