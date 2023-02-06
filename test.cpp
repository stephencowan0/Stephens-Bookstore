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
        vector<Book> shortest = lowest_length(inventory);
        cout << "The book(s) with the lowest length is:" << endl;
        for (int i = 0; i < shortest.size(); i++)
        {
            cout << shortest[i].return_title() << " with a length of " << shortest[i].return_length() << endl;
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

vector<Book> find_by_length(vector<Book> inventory, char type)
{
    cout << "Please enter a length value between 0 and 10: ";
    int length;
    bool valid_length = false;
    while (valid_length == false)
    {
        cin >> length;
        while (cin.fail())
        {
            cout << "That is not a number! Please enter a number between 0 and 10: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> length;
        }
        else
        {
            cout << "Invalid length. Please enter a number between 0 and 10: ";
        }
    }
    cin.clear();
    cin.ignore(256, '\n');
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
        if (Books.size() == 0)
        {
            cout << "No books were found with a length greater than or equal to: " << length << endl;
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
        if (Books.size() == 0)
        {
            cout << "No books were found with a length less than or equal to: " << length << endl;
        }
    }
    else
    {
        cout << "YOU BROKE IT!!! YOUR BROKE MY PROGRAM!!!! WHAT HAVE YOU DONE??????????" << endl;
    }
    return Books;
}

vector<Book> lowest_length(vector<Book> inventory)
{
    double lowest = inventory[0].return_length();
    vector<Book> shortest;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_length() < lowest)
        {
            lowest = inventory[i].return_length();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_length() == lowest)
        {
            shortest.push_back(inventory[i]);
        }
    }
    return shortest;
}

vector<Book> highest_length(vector<Book> inventory)
{
    double highest = inventory[0].return_length();
    vector<Book> longest;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_length() > highest)
        {
            highest = inventory[i].return_length();
        }
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].return_length() == highest)
        {
            longest.push_back(inventory[i]);
        }
    }
    return longest;
}