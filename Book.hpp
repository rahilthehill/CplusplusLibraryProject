#pragma once

#include <string>

struct Book {
    std::string title;
    std::string author;
    int year_published;
};

//Legit just the first line of classes
void output(const std::string &title, const std::string &author,const int &year);
void sortBooksByYear(Book books[], int size);
void exportImport(Book books[], int size);
int calculateAverage(Book books[], int size);
void addBook(std::vector<Book>& books, int& bookAmt, const std::string& name);
