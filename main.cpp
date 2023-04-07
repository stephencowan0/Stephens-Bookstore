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
    // Creates our Book inventory
    // This is done by calling our two initilization functions
    static vector<Book> inventory;
    vector<string> rows_of_data = read_data();
    // For every line of data in our .csv file, create one Book object and add it to our inventory vector
    for (int i = 0; i < rows_of_data.size(); i++)
    {
        Book new_book = create_classes(rows_of_data[i]);
        inventory.push_back(new_book);
    }
    // Create variables that will handle user input to run desired command
    string input;
    char command;
    // This is the menu, displays a welcome message and lists all of the commands available
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
    // Continually takes user input and runs the proper command
    // If the user inputs 'Q', then the loop quits and the closing command is run
    while (command != 'Q')
    {
        cout << "Please type in the letter of the command you wish to perform: ";
        getline(cin, input);
        // Makes sure that the user input is a single characater, so it can match our cases in the switch statement
        if (input.size() != 1)
        {
            cout << "Invalid command input, please try again using one of the listed commands." << endl;
        }
        else
        {
            command = input[0];
            switch (command)
            {
            // N: Add a new book to the inventory catalog
            case 'N':
            {
                Book new_book = add_book_from_input();
                inventory.push_back(new_book);
                cout << "Added new book to our inventory with the following information:" << endl;
                new_book.display_book_information();
                break;
            }
            // T: Find book by title
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
            // A: Find book(s) by author
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
            // I: Find book by ID number
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
            // L: Find books by length (pages count)
            case 'L':
            {
                cout << "Welcome to search by length. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest length. F to find the book(s) with the lowest length" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                // Check to make sure that the user input H, F, G, or L
                // If not, we reject their input and ask for input again
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
                // H to find the book(s) with the highest length
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
                // F to find the book(s) with the lowest length
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
                // G for a quantity equal to or greater than user input. L for a quantity equal to or less than user input
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
            // R: Find books by rating
            case 'R':
            {
                cout << "Welcome to search by rating. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest rating. F to find the book(s) with the lowest rating" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                // Check to make sure that the user input H, F, G, or L
                // If not, we reject their input and ask for input again
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
                // H to find the book(s) with the highest rating
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
                // F to find the book(s) with the lowest rating
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
                // G for a quantity equal to or greater than user input. L for a quantity equal to or less than user input
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
            // #: Find books by quantity in stock
            case '#':
            {
                cout << "Welcome to search by quantity. Here are the available commands:" << endl;
                cout << "H to find the book(s) with the highest quantity. F to find the book(s) with the lowest quantity" << endl;
                cout << "G for a quantity equal to or greater than. L for a quantity equal to or less than: ";
                // Check to make sure that the user input H, F, G, or L
                // If not, we reject their input and ask for input again
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
                // H to find the book(s) with the highest quantity
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
                // F to find the book(s) with the lowest quantity
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
                // G for a quantity equal to or greater than user input. L for a quantity equal to or less than user input
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
            // S: Update quantity in stock for a book
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
            // !: Update rating for a book
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
            // D: Delete a book from inventory
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
            // ~: Save changes made to inventory
            case '~':
            {
                rewrite_inventory_file(inventory);
                break;
            }
            // Q: Quit and close the program
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
            // If the input does not match any command, we simply don't use it and ask for input again
            default:
                cout << "Invalid command input, please try again using one of the listed commands." << endl;
                break;
            }
        }
    }

    cout << "Goodbye!" << endl;
    // Does nothing except keep the programming running, so it does not immediately close
    // Can also be used to testing/debugging purposes
    string keep_open;
    cin >> keep_open;
    return 0;
}