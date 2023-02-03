#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.hpp"
using namespace std;

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