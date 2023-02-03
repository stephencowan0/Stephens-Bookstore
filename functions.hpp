#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Class that stores information on each book
class Book
{
private:
    string title;
    string author;
    int book_id;
    int length;
    float rating;
    int quantity;

public:
    Book(string new_title, string new_author, int new_book_id, int new_length, float new_rating, int new_quantity);
    string return_title();
    string return_author();
    int return_bookid();
    int return_length();
    float return_rating();
    int return_quantity();
    void display_book_information();
};

// Initialization Functions
vector<string> read_data();
Book create_classes(string string_of_data);

// Inventory Management Functions
Book add_book_from_input();

// Search Functions
vector<Book> lowest_rating(vector<Book> inventory);
vector<Book> highest_rating(vector<Book> inventory);
vector<Book> lowest_quantity(vector<Book> inventory);
vector<Book> highest_quantity(vector<Book> inventory);