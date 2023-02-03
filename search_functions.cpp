#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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