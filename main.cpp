#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include "functions.hpp"
using namespace std;

int main()
{
    static vector<Book> inventory;
    vector<string> rows_of_data = read_data();
    for (int i = 0; i < rows_of_data.size(); i++)
    {
        Book new_book = create_classes(rows_of_data[i]);
        inventory.push_back(new_book);
    }

    string input;
    char command;
    cout << "Welcome to Stephen's Bookstore Inventory Management System!" << endl;
    cout << "This is the list of available commands:" << endl;
    cout << "N: Add a new book to the inventory catalog" << endl;
    cout << "L: Find the book(s) with the lowest rating" << endl;
    cout << "H: Find the book(s) with the highest rating" << endl;
    cout << "F: Find the book(s) with the lowest quantity in stock" << endl;
    cout << "M: Find the book(s) with the highest quantity in stock" << endl;
    cout << "T: Find book by title" << endl;
    cout << "A: Find book(s) by author" << endl;
    cout << "I: Find book by ID number" << endl;
    cout << "P: Find books by length (pages count)" << endl;
    cout << "R: Find books by rating" << endl;
    cout << "#: Find books by quantity in stock" << endl;
    cout << "S: Update quantity in stock for a book" << endl;
    cout << "!: Update rating for a book" << endl;
    cout << "Q: Quit and close the program" << endl;

    while (command != 'Q')
    {
        cout << "Please type in the letter of the command you wish to perform: ";
        getline(cin, input);

        if (input.size() != 1)
        {
            cout << "Invalid command input, please try again using one of the listed commands." << endl;
        }
        else
        {
            command = input[0];
            switch (command)
            {
            case 'N':
            {
                Book new_book = add_book_from_input();
                inventory.push_back(new_book);
                cout << "Added new book to our inventory with the following information:" << endl;
                new_book.display_book_information();
                break;
            }
            case 'L':
            {
                vector<Book> failures = lowest_rating(inventory);
                cout << "The book(s) with the lowest rating is:" << endl;
                for (int i = 0; i < failures.size(); i++)
                {
                    cout << failures[i].return_title() << " with a rating of " << failures[i].return_rating() << endl;
                }
                break;
            }
            case 'H':
            {
                vector<Book> highest = highest_rating(inventory);
                cout << "The book(s) with the lowest rating is:" << endl;
                for (int i = 0; i < highest.size(); i++)
                {
                    cout << highest[i].return_title() << " with a rating of " << highest[i].return_rating() << endl;
                }
                break;
            }
            case 'F':
            {
                vector<Book> fewest = lowest_quantity(inventory);
                cout << "The book(s) with the lowest quantity is:" << endl;
                for (int i = 0; i < fewest.size(); i++)
                {
                    cout << fewest[i].return_title() << " with a rating of " << fewest[i].return_quantity() << endl;
                }
                break;
            }
            case 'M':
            {
                vector<Book> most = highest_quantity(inventory);
                cout << "The book(s) with the lowest quantity is:" << endl;
                for (int i = 0; i < most.size(); i++)
                {
                    cout << most[i].return_title() << " with a rating of " << most[i].return_quantity() << endl;
                }
                break;
            }
            case 'T':
            {
                string title;
                cout << "What is the title of the book you are looking for: ";
                getline(cin, title);
                vector<Book> Books = find_by_title(inventory, title);
                if (Books.size() == 0)
                {
                    cout << "No books were found with the title: " << title << endl;
                }
                else
                {
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                break;
            }
            case 'A':
            {
                string author;
                cout << "What author would you like to search for: ";
                getline(cin, author);
                vector<Book> Books = find_by_author(inventory, author);
                if (Books.size() == 0)
                {
                    cout << "No books were found by author: " << author << endl;
                }
                else
                {
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                break;
            }
            case 'I':
            {
                cout << "What is the ID Number of the book you would like to search for: ";
                int index = find_by_BookID(inventory);
                if (index != -1)
                {
                    cout << "Found the following book:" << endl;
                    inventory[index].display_book_information();
                }
                break;
            }
            case 'P':
            {
                cout << "Welcome to search by length. Search by length finds all books with a page length either greater than/equal to or less than/equal to the inputted number.";
                int length;
                cin >> length;
                while (cin.fail())
                {
                    cout << "That is not a number! Please enter a number: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> length;
                }
                cin.clear();
                cin.ignore(256, '\n');
                cout << "G for a length equal to or greater than or L for a length equal to or less than: ";
                string binary_value;
                bool valid_type = false;
                while (valid_type == false)
                {
                    getline(cin, binary_value);
                    if (binary_value == "G" || binary_value == "L")
                    {
                        valid_type = true;
                    }
                    else
                    {
                        cout << "Invalid command! G for a length equal to or greater than or L for a length equal to or less than: ";
                    }
                }
                vector<Book> Books = find_by_length(inventory, length, binary_value[0]);
                if (Books.size() == 0)
                {
                    if (binary_value == "G")
                    {
                        cout << "No books were found with a length greater than or equal to: " << length << endl;
                    }
                    else if (binary_value == "L")
                    {
                        cout << "No books were found with a length less than or equal to: " << length << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                break;
            }
            case 'R':
            {
                cout << "Welcome to search by rating. Search by rating finds all books with a rating either greater than/equal to or less than/equal to the inputted number." << endl;
                cout << "Please enter a rating value between 0 and 10: ";
                float rating;
                bool valid_rating = false;
                while (valid_rating == false)
                {
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
                cout << "G for a rating equal to or greater than or L for a rating equal to or less than: ";
                string binary_value;
                bool valid_type = false;
                while (valid_type == false)
                {
                    getline(cin, binary_value);
                    if (binary_value == "G" || binary_value == "L")
                    {
                        valid_type = true;
                    }
                    else
                    {
                        cout << "Invalid command! G for a rating equal to or greater than or L for a rating equal to or less than: ";
                    }
                }
                vector<Book> Books = find_by_rating(inventory, rating, binary_value[0]);
                if (Books.size() == 0)
                {
                    if (binary_value == "G")
                    {
                        cout << "No books were found with a rating greater than or equal to: " << rating << endl;
                    }
                    else if (binary_value == "L")
                    {
                        cout << "No books were found with a rating less than or equal to: " << rating << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                break;
            }
            case '#':
            {
                cout << "Welcome to search by quantity. Search by quantity finds all books that we have in stock a quantity either greater than/equal to or less than/equal to the inputted number.";
                int quantity;
                cin >> quantity;
                while (cin.fail())
                {
                    cout << "That is not a number! Please enter a number: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> quantity;
                }
                cin.clear();
                cin.ignore(256, '\n');
                cout << "G for a quantity equal to or greater than or L for a quantity equal to or less than: ";
                string binary_value;
                bool valid_type = false;
                while (valid_type == false)
                {
                    getline(cin, binary_value);
                    if (binary_value == "G" || binary_value == "L")
                    {
                        valid_type = true;
                    }
                    else
                    {
                        cout << "Invalid command! G for a quantity equal to or greater than or L for a quantity equal to or less than: ";
                    }
                }
                vector<Book> Books = find_by_quantity(inventory, quantity, binary_value[0]);
                if (Books.size() == 0)
                {
                    if (binary_value == "G")
                    {
                        cout << "No books were found with a quantity greater than or equal to: " << quantity << endl;
                    }
                    else if (binary_value == "L")
                    {
                        cout << "No books were found with a quantity less than or equal to: " << quantity << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                break;
            }
            case 'S':
            {
                cout << "Enter the ID Number of the book that you would like to find and update inventory quantity for: ";
                int index = find_by_BookID(inventory);
                if (index != -1)
                {
                    cout << "The following book was found: " << endl;
                    inventory[index].display_book_information();
                    inventory[index].update_quantity();
                }
                break;
            }
            case '!':
            {
                cout << "Enter the ID Number of the book that you would like to find and update rating for: ";
                int index = find_by_BookID(inventory);
                if (index != -1)
                {
                    cout << "The following book was found: " << endl;
                    inventory[index].display_book_information();
                    inventory[index].update_rating();
                }
                break;
            }
            case 'Q':
                break;
            default:
                cout << "Invalid command input, please try again using one of the listed commands." << endl;
                break;
            }
        }
    }

    cout << "Goodbye!" << endl;

    string keep_open;
    cin >> keep_open;
    return 0;
}