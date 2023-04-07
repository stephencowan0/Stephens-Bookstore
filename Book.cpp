#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.hpp"
using namespace std;
Book::Book()
{
}
Book::Book(string new_title, string new_author, int new_book_id, int new_length, float new_rating, int new_quantity)
{
    title = new_title;
    author = new_author;
    book_id = new_book_id;
    length = new_length;
    rating = new_rating;
    quantity = new_quantity;
}
string Book::return_title()
{
    return title;
}
string Book::return_author()
{
    return author;
}
int Book::return_bookid()
{
    return book_id;
}
int Book::return_length()
{
    return length;
}
float Book::return_rating()
{
    return rating;
}
int Book::return_quantity()
{
    return quantity;
}
void Book::display_book_information()
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Book ID#: " << book_id << endl;
    cout << "Length: " << length << " pages long" << endl;
    cout << "Average Rating: " << rating << endl;
    cout << "Quantity In Stock: " << quantity << endl;
}
// Takes user input, positive numbers increase quantity and negatives decrease it
void Book::update_quantity()
{
    cout << "Enter the quantity of books that you would like to change this books stock by: ";
    int change;
    cin >> change;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid number of books to change quantity in stock by: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> change;
    }
    cin.clear();
    cin.ignore(256, '\n');
    quantity = quantity + change;
    cout << title << " now has an in-stock quantity of: " << quantity << endl;
}
// Takes user input and updates a book's rating to that number (Must be a float between 0 and 10)
void Book::update_rating()
{
    float new_rating;
    bool valid_rating = false;
    while (valid_rating == false)
    {
        cout << "What would you like the new rating for this book to be: ";
        cin >> new_rating;
        while (cin.fail())
        {
            cout << "That is not a number! Please enter a number between 0 and 10: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> new_rating;
        }
        if (new_rating <= 10 && new_rating >= 0)
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
    rating = new_rating;
    cout << title << " now has a rating of: " << rating << endl;
}