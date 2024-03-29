#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "functions.hpp"
using namespace std;

// Gets user input via the terminal, then creates a Book class object from it
Book add_book_from_input()
{
    // Asks the user for the book's title (No restrictions)
    string title;
    cout << "Title: ";
    getline(cin, title);
    while (title == "")
    {
        cout << "Title: ";
        getline(cin, title);
    }
    // Asks the user for the book's author (No restrictions)
    string author;
    cout << "Author: ";
    getline(cin, author);
    while (author == "")
    {
        cout << "Author: ";
        getline(cin, author);
    }
    // Asks the user for the book's ID number (Must be an int)
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
    cin.clear();
    cin.ignore(256, '\n');
    // Asks the user for the book's page length (Must be an int)
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
    cin.clear();
    cin.ignore(256, '\n');
    // Asks the user for the book's rating (Must be a float between 0 and 10)
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
    cin.clear();
    cin.ignore(256, '\n');
    // Asks the user for the quantity in stock of the book (Must be an int)
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
    cin.clear();
    cin.ignore(256, '\n');

    Book new_book = Book(title, author, book_id, length, rating, quantity);
    return new_book;
}
// Updates the .csv file by rewriting it with the current inventory vector
void rewrite_inventory_file(vector<Book> inventory)
{
    ofstream myfile;
    myfile.open("current_inventory.csv", ios_base::trunc);
    for (int i = 0; i < inventory.size(); i++)
    {
        myfile << inventory[i].return_title() << ",";
        myfile << inventory[i].return_author() << ",";
        myfile << inventory[i].return_bookid() << ",";
        myfile << inventory[i].return_length() << ",";
        myfile << inventory[i].return_rating() << ",";
        myfile << inventory[i].return_quantity() << endl;
    }
    myfile.close();
    cout << "Update complete! Currenty inventory state saved to file." << endl;
}