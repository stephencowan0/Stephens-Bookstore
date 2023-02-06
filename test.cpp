case 'R':
{
    cout << "Welcome to search by rating. Search by rating finds all books with a rating either greater than/equal to or less than/equal to the inputted number." << endl;
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