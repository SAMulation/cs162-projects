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

    get_book(book2);

    print_book(book1);
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
    cin >> b.title;
    cout << "Author's first name: ";
    cin >> b.author_first;
    cout << "Author's last name: ";
    cin >> b.author_last;
    cout << "Publish Year: ";
    cin >> b.pub_year;
    cout << "Genre: "; 
    cin >> b.genre;
    cout << "Price: "; 
    cin >> b.price;

    cout << endl;

    return;
}