#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "functions.hpp"
using namespace std;

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