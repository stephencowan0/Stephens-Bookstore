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
    vector<Book> inventory;
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
            case 'Q':
                break;
            default:
                cout << "Invalid command input, please try again using one of the listed commands." << endl;
                break;
            }
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}