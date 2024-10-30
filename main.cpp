#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int year_published;
};

void sortBooksByYear();

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

int main() {
    int bookAmt{1};
    cout << "***************************************************" << endl;
    cout << "Welcome to your custom library software" << endl;
    cout << "***************************************************" << endl;
    cout << "How many books would you like to add? (Default 1)" << endl;
    cin >> bookAmt;
    Book books[bookAmt];

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

    sortBooksByYear(books, 3);

    cout << "Books sorted by publish date:" << endl;
    for (int i = 0; i < bookAmt; i++) {
        output(books[i].title, books[i].author, books[i].year_published);
    };



    return 0;
}
