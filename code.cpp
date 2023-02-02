#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

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
    Book(string new_title, string new_author, int new_book_id, int new_length, float new_rating, int new_quantity)
    {
        title = new_title;
        author = new_author;
        book_id = new_book_id;
        length = new_length;
        rating = new_rating;
        quantity = new_quantity;
    }
    string return_title()
    {
        return title;
    }
    string return_author()
    {
        return author;
    }
    int return_bookid()
    {
        return book_id;
    }
    int return_length()
    {
        return length;
    }
    float return_rating()
    {
        return rating;
    }
    int return_quantity()
    {
        return quantity;
    }
    void display_book_information()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Book ID#: " << book_id << endl;
        cout << "Length: " << length << " pages long" << endl;
        cout << "Average Rating: " << rating << endl;
        cout << "Quantity In Stock: " << quantity << endl;
    }
};

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

Book add_book_from_input()
{
    string title;
    cout << "Title: ";
    getline(cin, title);

    string author;
    cout << "Author: ";
    getline(cin, author);

    int book_id;
    cout << "ID Number: ";
    cin >> book_id;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid book ID number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> book_id;
    }

    int length;
    cout << "Number of Pages: ";
    cin >> length;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid number of pages: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> length;
    }

    float rating;
    bool valid_rating = false;
    while (valid_rating == false)
    {
        cout << "Average Rating: ";
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

    int quantity;
    cout << "Quantity in Stock: ";
    cin >> quantity;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid number of books in stock: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> quantity;
    }
    ofstream myfile;
    myfile.open("current_inventory.csv", ios_base::app);
    myfile << title << "," << author << "," << book_id << "," << length << "," << rating << "," << quantity << endl;
    myfile.close();

    Book new_book = Book(title, author, book_id, length, rating, quantity);
    return new_book;
}

vector<Book> lowest_rating(vector<Book> inventory)
{
    double lowest = inventory[0].return_rating();
    vector<Book> failures;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_rating() < lowest)
        {
            lowest = inventory[i].return_rating();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_rating() == lowest)
        {
            failures.push_back(inventory[i]);
        }
    }
    return failures;
}

vector<Book> highest_rating(vector<Book> inventory)
{
    double highest = inventory[0].return_rating();
    vector<Book> successes;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_rating() > highest)
        {
            highest = inventory[i].return_rating();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_rating() == highest)
        {
            successes.push_back(inventory[i]);
        }
    }
    return successes;
}

vector<Book> lowest_quantity(vector<Book> inventory)
{
    double lowest = inventory[0].return_quantity();
    vector<Book> fewest;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_quantity() < lowest)
        {
            lowest = inventory[i].return_quantity();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_quantity() == lowest)
        {
            fewest.push_back(inventory[i]);
        }
    }
    return fewest;
}

vector<Book> highest_quantity(vector<Book> inventory)
{
    double highest = inventory[0].return_quantity();
    vector<Book> most;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_quantity() > highest)
        {
            highest = inventory[i].return_quantity();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_quantity() == highest)
        {
            most.push_back(inventory[i]);
        }
    }
    return most;
}

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