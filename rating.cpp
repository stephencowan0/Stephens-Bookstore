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