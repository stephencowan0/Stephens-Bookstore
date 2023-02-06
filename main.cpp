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
    cout << "T: Find book by title" << endl;
    cout << "A: Find book(s) by author" << endl;
    cout << "I: Find book by ID number" << endl;
    cout << "L: Find books by length (pages count)" << endl;
    cout << "R: Find books by rating" << endl;
    cout << "#: Find books by quantity in stock" << endl;
    cout << "S: Update quantity in stock for a book" << endl;
    cout << "!: Update rating for a book" << endl;
    cout << "D: Delete a book from inventory" << endl;
    cout << "~: Save changes made to inventory" << endl;
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
            case 'L':
            {
                cout << "Welcome to search by length. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest length. F to find the book(s) with the lowest length" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";

                bool valid_length_command = false;
                string length_input;
                char length_command;
                while (valid_length_command == false)
                {
                    getline(cin, length_input);
                    if (length_input == "H" || length_input == "F" || length_input == "G" || length_input == "L")
                    {
                        valid_length_command = true;
                    }
                    else
                    {
                        cout << "Invalid command!" << endl;
                        cout << "H to find the book(s) with the highest length. F to find the book(s) with the lowest length" << endl;
                        cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                    }
                }
                length_command = length_input[0];
                switch (length_command)
                {
                case 'H':
                {
                    vector<Book> highest = highest_length(inventory);
                    cout << "The book(s) with the highest length is:" << endl;
                    for (int i = 0; i < highest.size(); i++)
                    {
                        cout << highest[i].return_title() << " with a length of " << highest[i].return_length() << endl;
                    }
                    break;
                }
                case 'F':
                {
                    vector<Book> failures = lowest_length(inventory);
                    cout << "The book(s) with the lowest length is:" << endl;
                    for (int i = 0; i < failures.size(); i++)
                    {
                        cout << failures[i].return_title() << " with a length of " << failures[i].return_length() << endl;
                    }
                    break;
                }
                default:
                {
                    vector<Book> Books = find_by_length(inventory, length_command);
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                }
                break;
            }
            case 'R':
            {
                cout << "Welcome to search by rating. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest rating. F to find the book(s) with the lowest rating" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";

                bool valid_rating_command = false;
                string rating_input;
                char rating_command;
                while (valid_rating_command == false)
                {
                    getline(cin, rating_input);
                    if (rating_input == "H" || rating_input == "F" || rating_input == "G" || rating_input == "L")
                    {
                        valid_rating_command = true;
                    }
                    else
                    {
                        cout << "Invalid command!" << endl;
                        cout << "H to find the book(s) with the highest rating. F to find the book(s) with the lowest rating" << endl;
                        cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                    }
                }
                rating_command = rating_input[0];
                switch (rating_command)
                {
                case 'H':
                {
                    vector<Book> highest = highest_rating(inventory);
                    cout << "The book(s) with the highest rating is:" << endl;
                    for (int i = 0; i < highest.size(); i++)
                    {
                        cout << highest[i].return_title() << " with a rating of " << highest[i].return_rating() << endl;
                    }
                    break;
                }
                case 'F':
                {
                    vector<Book> failures = lowest_rating(inventory);
                    cout << "The book(s) with the lowest rating is:" << endl;
                    for (int i = 0; i < failures.size(); i++)
                    {
                        cout << failures[i].return_title() << " with a rating of " << failures[i].return_rating() << endl;
                    }
                    break;
                }
                default:
                {
                    vector<Book> Books = find_by_rating(inventory, rating_command);
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
                }
                }
                break;
            }
            case '#':
            {
                cout << "Welcome to search by quantity. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest quantity. F to find the book(s) with the lowest quantity" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";

                bool valid_quantity_command = false;
                string quantity_input;
                char quantity_command;
                while (valid_quantity_command == false)
                {
                    getline(cin, quantity_input);
                    if (quantity_input == "H" || quantity_input == "F" || quantity_input == "G" || quantity_input == "L")
                    {
                        valid_quantity_command = true;
                    }
                    else
                    {
                        cout << "Invalid command!" << endl;
                        cout << "H to find the book(s) with the highest quantity. F to find the book(s) with the lowest quantity" << endl;
                        cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                    }
                }
                quantity_command = quantity_input[0];
                switch (quantity_command)
                {
                case 'H':
                {
                    vector<Book> highest = highest_quantity(inventory);
                    cout << "The book(s) with the highest quantity is:" << endl;
                    for (int i = 0; i < highest.size(); i++)
                    {
                        cout << highest[i].return_title() << " with a quantity of " << highest[i].return_quantity() << endl;
                    }
                    break;
                }
                case 'F':
                {
                    vector<Book> failures = lowest_quantity(inventory);
                    cout << "The book(s) with the lowest quantity is:" << endl;
                    for (int i = 0; i < failures.size(); i++)
                    {
                        cout << failures[i].return_title() << " with a quantity of " << failures[i].return_quantity() << endl;
                    }
                    break;
                }
                default:
                {
                    vector<Book> Books = find_by_quantity(inventory, quantity_command);
                    for (int i = 0; i < Books.size(); i++)
                    {
                        cout << "Found the following book(s):" << endl;
                        Books[i].display_book_information();
                    }
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
            case 'D':
            {
                cout << "Enter the ID of the book that you would like to delete from inventory: ";
                int index = find_by_BookID(inventory);
                if (index != -1)
                {
                    inventory.erase(inventory.begin() + index);
                    cout << "Book successfully deleted from inventory." << endl;
                }
                break;
            }
            case '~':
            {
                rewrite_inventory_file(inventory);
                break;
            }
            case 'Q':
            {
                cout << "You are about to exit the program. Would you like to save before exiting? Type Y to save, type N to exit without saving: ";
                bool exit_okay = false;
                string user_input;
                while (exit_okay == false)
                {
                    getline(cin, user_input);
                    if (user_input == "Y")
                    {
                        rewrite_inventory_file(inventory);
                        exit_okay = true;
                    }
                    else if (user_input == "N")
                    {
                        exit_okay = true;
                    }
                    else
                    {
                        cout << "Invalid input! Type Y to save, type N to exit without saving: ";
                    }
                }
                break;
            }

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