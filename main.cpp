#include <iostream>
#include "Book.hpp"
#include <vector>

using namespace std;

int main() {

    int bookAmt{1};
    cout << "***************************************************" << endl;
    cout << "Welcome to your custom library software" << endl;
    cout << "***************************************************" << endl;
    cout << "How many books would you like to add? (Default 1)" << endl;
    cin >> bookAmt;
    cin.ignore();

    //Book books[bookAmt];
    //this is bad cause c++ base doesnt support dynamic assisngment like this, using a vector instead

    vector<Book> books(bookAmt);

    for (int i = 0; i < bookAmt; i++) {
        cout << "Enter details for book " << i+1 << endl;
        cout << "Title: " << endl;
        cin.ignore(); // clears bugger before using getline
        getline(cin, books[i].title);
        cout << "Author of book:"<< endl;
        getline(cin, books[i].author);
        cout << "Year published: " << endl;
        cin >> books[i].year_published;

    };

    sortBooksByYear(books.data(), bookAmt);

    cout << "Books sorted by publish date:" << endl;
    for (int i = 0; i < bookAmt; i++) {
        output(books[i].title, books[i].author, books[i].year_published);
    };



    return 0;
}
