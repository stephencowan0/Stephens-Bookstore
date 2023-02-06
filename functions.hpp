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
void rewrite_inventory_file(vector<Book> inventory);

// Search Functions
vector<Book> lowest_length(vector<Book> inventory);
vector<Book> highest_length(vector<Book> inventory);
vector<Book> lowest_rating(vector<Book> inventory);
vector<Book> highest_rating(vector<Book> inventory);
vector<Book> lowest_quantity(vector<Book> inventory);
vector<Book> highest_quantity(vector<Book> inventory);
vector<Book> find_by_title(vector<Book> inventory, string title);
vector<Book> find_by_author(vector<Book> inventory, string author);
int find_by_BookID(vector<Book> inventory);
vector<Book> find_by_length(vector<Book> inventory, char type);
vector<Book> find_by_rating(vector<Book> inventory, char type);
vector<Book> find_by_quantity(vector<Book> inventory, int quantity, char type);