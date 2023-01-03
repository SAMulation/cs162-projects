/*************************
 * Name: Book Structures
 * Author: Sam Sarsten
 * Date: 12-29-2022
 * Purpose: Practicing C++ structures using a book model
 * 
**************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author_first;
    string author_last;
    int pub_year;
    string genre;
    double price;
};

void print_book(Book);
void get_book(Book&);
void author_fix(Book&);

int main() {
    Book book1 = {
        "Winnie the Pooh",
        "A.A.",
        "Milne",
        1926,
        "Childrens",
        9.99
    };

    Book book2;

    cout << "Please enter detail's for the second book..." << endl;
    get_book(book2);

    cout << "Here's the first book:" << endl;
    print_book(book1);

    
    cout << "Here's the second book:" << endl;
    print_book(book2);

    author_fix(book2);


    cout << "Here's the second book, fixed:" << endl;
    print_book(book2);
    
    return 0;
}

void print_book(Book b)
{
    cout << fixed << showpoint << setprecision(2);
    cout << left << setw(17) << "Title: " << b.title << endl;
    cout << setw(17) << "Author: " << b.author_first << " " << b.author_last << endl;
    cout << setw(17) << "Publish Year: " << b.pub_year << endl;
    cout << setw(17) << "Genre: " << b.genre << endl;
    cout << setw(17) << "Price: " << "$" << b.price << endl << endl;

    return;
}

void get_book(Book& b)
{
    cout << "Title: "; 
    getline(cin, b.title);
    cout << "Author's first name: ";
    getline(cin, b.author_first);
    cout << "Author's last name: ";
    getline(cin, b.author_last);
    cout << "Publish Year: ";
    cin >> b.pub_year;
    cin.ignore(80, '\n');
    cout << "Genre: "; 
    getline(cin, b.genre);
    cout << "Price: "; 
    cin >> b.price;
    cin.ignore(80, '\n');

    cout << endl;

    return;
}

void author_fix(Book& b)
{
    cout << "That is not the right author! Please fix..." << endl << endl;

    cout << "Author's first name: ";
    getline(cin, b.author_first);
    cout << "Author's last name: ";
    getline(cin, b.author_last);

    cout << endl;

    return;
}