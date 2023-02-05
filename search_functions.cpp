#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include "functions.hpp"
using namespace std;

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

vector<Book> find_by_title(vector<Book> inventory, string title)
{
    // Remove whitespace from title
    int l = title.length();
    int c = count(title.begin(), title.end(), ' ');
    remove(title.begin(), title.end(), ' ');
    title.resize(l - c);
    // Make all characters lowercase
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    vector<Book> Books;
    for (int i = 0; i < inventory.size(); i++)
    {
        string current_title = inventory[i].return_title();
        // Remove whitespace from title
        int l = current_title.length();
        int c = count(current_title.begin(), current_title.end(), ' ');
        remove(current_title.begin(), current_title.end(), ' ');
        current_title.resize(l - c);
        // Make all characters lowercase
        transform(current_title.begin(), current_title.end(), current_title.begin(), ::tolower);

        if (current_title == title)
        {
            Books.push_back(inventory[i]);
        }
    }
    return Books;
}

vector<Book> find_by_author(vector<Book> inventory, string author)
{
    // Remove whitespace from author
    int l = author.length();
    int c = count(author.begin(), author.end(), ' ');
    remove(author.begin(), author.end(), ' ');
    author.resize(l - c);
    // Make all characters lowercase
    transform(author.begin(), author.end(), author.begin(), ::tolower);
    vector<Book> Books;
    for (int i = 0; i < inventory.size(); i++)
    {
        string current_author = inventory[i].return_author();
        // Remove whitespace from author
        int l = current_author.length();
        int c = count(current_author.begin(), current_author.end(), ' ');
        remove(current_author.begin(), current_author.end(), ' ');
        current_author.resize(l - c);
        // Make all characters lowercase
        transform(current_author.begin(), current_author.end(), current_author.begin(), ::tolower);

        if (current_author == author)
        {
            Books.push_back(inventory[i]);
        }
    }
    return Books;
}

Book *find_by_BookID(vector<Book> inventory)
{
    int BookID;
    cin >> BookID;
    while (cin.fail())
    {
        cout << "That is not a number! Please enter a valid book ID number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> BookID;
    }
    cin.clear();
    cin.ignore(256, '\n');
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_bookid() == BookID)
        {
            return &inventory[i];
        }
    }
    cout << "No book was found with an ID Number of: " << BookID << endl;
    static Book nothing = Book();
    return &nothing;
}

vector<Book> find_by_length(vector<Book> inventory, int length, char type)
{
    vector<Book> Books;
    if (type == 'G')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_length() >= length)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else if (type == 'L')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_length() <= length)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else
    {
        cout << "YOU BROKE IT!!! YOUR BROKE MY PROGRAM!!!! WHAT HAVE YOU DONE??????????" << endl;
    }
    return Books;
}

vector<Book> find_by_rating(vector<Book> inventory, float rating, char type)
{
    vector<Book> Books;
    if (type == 'G')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_rating() >= rating)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else if (type == 'L')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_rating() <= rating)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else
    {
        cout << "YOU BROKE IT!!! YOUR BROKE MY PROGRAM!!!! WHAT HAVE YOU DONE??????????" << endl;
    }
    return Books;
}

vector<Book> find_by_quantity(vector<Book> inventory, int quantity, char type)
{
    vector<Book> Books;
    if (type == 'G')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_quantity() >= quantity)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else if (type == 'L')
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].return_quantity() <= quantity)
            {
                Books.push_back(inventory[i]);
            }
        }
    }
    else
    {
        cout << "YOU BROKE IT!!! YOUR BROKE MY PROGRAM!!!! WHAT HAVE YOU DONE??????????" << endl;
    }
    return Books;
}