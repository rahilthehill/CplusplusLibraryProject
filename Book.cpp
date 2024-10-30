#include "Book.hpp"
#include <iostream>
using namespace std;

void output(const string &title, const string &author,const int &year) {
    cout << "-----------------------------------"  << endl;
    cout << "Title of book: " << title << endl;
    cout << "Author of book: " << author << endl;
    cout << "Year published: "<< year << endl;
}

void sortBooksByYear(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].year_published > books[j + 1].year_published) {

                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}