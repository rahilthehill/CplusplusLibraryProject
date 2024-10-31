#include "Book.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>

using namespace std;

void output(const string &title, const string &author,const int &year) {
    cout << "-----------------------------------"  << endl;
    cout << "Title of book: " << title << endl;
    cout << "Author of book: " << author << endl;
    cout << "Year published: "<< year << endl;
}

void sortBooksByYear(Book books[], int size) {
    if (size < 2) {
        cout << "Can't sort 1 book!" << endl;
        cout << "Try adding more!" << endl;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].year_published > books[j + 1].year_published) {

                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
        cout << "Sorted!" << endl;
    }
}

void exportImport(Book books[], int size) {
    fstream file;
    file.open("Library.txt", ios::out);
    if (file.is_open()) {
        file << "Library list" << endl;
        file << "_____________" << endl;
        for (int i = 0; i < size; i++) {
            file << "Title of book: " << books[i].title << endl;
            file << "Author of book: " << books[i].author << endl;
            file << "Year published: "<< books[i].year_published << endl;
            file << "*-*-*-*-*-*-*-*-*-*" << endl;
        }
        file.close();
    }

    file.open("Library.txt", ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}

int calculateAverage(Book books[], int size) {

    //assertions added here to validate parameters
    // assert(books != nullptr);
    // assert(size > 0);

    //inceptions and variants
    if (size <= 0) {
        throw invalid_argument("CAN'T HAVE A EMPTY LIBRARY");
    }
    if (books == nullptr) {
        throw invalid_argument("Books list is empty");
    }

    int temp{0};
    for(int i = 0; i < size; i++) {
        temp = books[i].year_published + temp;
    }

    return temp/size;
}

void addBook(vector<Book>& books, int& bookAmt, const string& name) {
    int booksToAdd;

    cout << "How many books would you like to add to " << name << "? (Minimum 1)" << endl;
    cin >> booksToAdd;//
    cin.ignore();

    bookAmt += booksToAdd;

    int currentSize = books.size();
    books.resize(currentSize + booksToAdd);

    for (int i = currentSize; i < currentSize + booksToAdd; i++) {
        cout << "Enter details for book " << (i - currentSize + 1) << endl;
        cout << "Title: " << endl;

        getline(cin, books[i].title);
        cout << "Author of book:"<< endl;

        getline(cin, books[i].author);
        cout << "Year published: " << endl;
        cin >> books[i].year_published;
        cin.ignore(); // clears bugger before using getline
    };

    cout << "Thanks for adding your books!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}