#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "functions.hpp"
using namespace std;

// Reads in the .csv file, where each line (book) is a string
vector<string> read_data()
{
    ifstream data_file("current_inventory.csv");
    vector<string> rows_of_data;
    if (data_file.is_open())
    {
        string row;
        while (getline(data_file, row))
        {
            rows_of_data.push_back(row);
        }
    }
    data_file.close();
    return rows_of_data;
}
// Takes in a book's data and transforms it into a Book class object
Book create_classes(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string title = class_data[0];
    string author = class_data[1];
    int book_id = stoi(class_data[2]);
    int length = stoi(class_data[3]);
    float rating = stof(class_data[4]);
    int quantity = stoi(class_data[5]);

    Book new_book = Book(title, author, book_id, length, rating, quantity);
    return new_book;
}