#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "functions.hpp"
using namespace std;

Book add_book_from_input()
{
    string title;
    cout << "Title: ";
    getline(cin, title);

    string author;
    cout << "Author: ";
    getline(cin, author);

    int book_id;
    cout << "ID Number: ";
    cin >> book_id;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid book ID number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> book_id;
    }

    int length;
    cout << "Number of Pages: ";
    cin >> length;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid number of pages: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> length;
    }

    float rating;
    bool valid_rating = false;
    while (valid_rating == false)
    {
        cout << "Average Rating: ";
        cin >> rating;
        while (cin.fail())
        {
            cout << "That is not a number! Please enter a number between 0 and 10: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> rating;
        }
        if (rating <= 10 && rating >= 0)
        {
            valid_rating = true;
        }
        else
        {
            cout << "Invalid rating. Please enter a number between 0 and 10: ";
        }
    }

    int quantity;
    cout << "Quantity in Stock: ";
    cin >> quantity;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid number of books in stock: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> quantity;
    }
    ofstream myfile;
    myfile.open("current_inventory.csv", ios_base::app);
    myfile << title << "," << author << "," << book_id << "," << length << "," << rating << "," << quantity << endl;
    myfile.close();

    Book new_book = Book(title, author, book_id, length, rating, quantity);
    return new_book;
}