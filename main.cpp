#include <iostream>
#include "Book.hpp"
#include <vector>
#include <cctype>

using namespace std;

int main() {
    int bookAmt{0};
    string libName{"User's Library"};

    cout << "***************************************************" << endl;
    cout << "Welcome to your custom library software" << endl;
    cout << "***************************************************" << endl;
    cout << "Name your new library!: " << endl;
    getline(cin, libName);


    //Book books[bookAmt];
    //this is bad cause c++ base doesnt support dynamic assisngment like this, using a vector instead

    vector<Book> books(bookAmt);
    addBook(books, bookAmt,libName);


    int choice{0};
    while (choice != 10) {
        cout << "What would you like to do next?" << endl;
        cout << "Your choice (1-10): " << endl;
        cout << "1 - Sort by published year" << endl << "2 - Show sorted List" << endl << "3 - Calculate average year published?" << endl;
        cout << "4 - Export To External File" << endl << "5 - Add more books to " << libName << endl << "6 - Emulate a try and catch exception! [for the dev :)]" << endl;
        cout << "7 - WIP" << endl << "8 - WIP" << endl << "9 - WIP" << endl << "10 - Exit"<< endl;
        cin >> choice;

        switch (choice) {
            case 1:
                sortBooksByYear(books.data(), bookAmt);
            break;
            case 2:
                cout << "Books sorted by publish date:" << endl;
            for (int i = 0; i < bookAmt; i++) {
                output(books[i].title, books[i].author, books[i].year_published);
            }
            break;
            case 3:
                cout << "Average year published of your books in your library: " << calculateAverage(books.data(), bookAmt) << endl;
            break;
            case 4: {
                string input{"y"};
                cout << "Would you like to save your library as an external file? (Default: 'y') ('n' to refuse)" << endl;
                cin >> input;
                if (input != "n") {
                    cout << "Saving your library as an external file..." << endl;
                    exportImport(books.data(), bookAmt);
                }
                break;
            }
            case 5:
                addBook(books, bookAmt,libName);
            break;

            case 6: {
                /**
     * Catching/testing a exception code (testing code)
     **/
                try { // it tries to see if a exception is triggered
                    // Assuming we have some books array and bookAmt is the number of books
                    vector<Book> books(3);
                    books[0] = {"Book One", "Author One", 2001};
                    books[1] = {"Book Two", "Author Two", 2005};
                    books[2] = {"Book Three", "Author Three", 2010};

                    // Intentionally use an invalid size to test exception handling
                    int avgYear = calculateAverage(books.data(), 0); // This should throw an exception
                    cout << "Average year published: " << avgYear << endl;
                } catch (const std::invalid_argument& e) { //if it is triggered, it jumps to print a error msg
                    // Catch the exception and print an error message
                    cout << "Error: " << e.what() << endl; //e.what() provides the error message in the throw argument
                }
                /**
                * Catching/testing a exception code (testing code)
                **/
            }
            break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10: {
                cout << "Closing..." << endl;
                cout << "Thank you for using the library system for: " << libName << " ! " << endl;
                cout << "------------------------!TERMINATED!------------------------" << endl;
            }

                break;
            default:
                cout << "Invalid choice or Work in progress option" << endl;
        }
    }


    return 0;
}
