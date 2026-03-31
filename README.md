# 📚 Library Book Tracker

> A terminal-based library management system built in C++.

---

## What it does

- Add books (title, author, year)
- Remove a book by title
- Search books by title or author name
- Display all books with their status
- Issue and return books (toggle availability)

---

## Project Structure

```
library-tracker/
│
├── library.cpp     # All code in one file
└── README.md
```

---

## How to Run

**Compile:**
```bash
g++ library.cpp -o library
```

**Run:**
```bash
./library        # Mac/Linux
library.exe      # Windows
```

---

## Concepts Used

- Structs
- Arrays
- Functions
- Loops and conditionals
- String operations (`find`, `getline`)
- Boolean flags

---

## Sample Output

```
======================================
       LIBRARY BOOK TRACKER
======================================
 1. Add a book
 2. Remove a book
 3. Search by title
 4. Search by author
 5. Display all books
 6. Issue / Return a book
 0. Exit
--------------------------------------
Enter your choice:
```

---

*Built as a 2nd semester CSE project using only core C++ concepts.*
