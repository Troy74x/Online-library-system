#include <iostream>
#include <string>
#include "BookList.h"
#define el "\n"
using namespace std;

void print_separator() {
    cout << "================================================================================" << el;
}

void print_header(const string& title) {
    print_separator();
    cout << "                                " << title << "                                " << el;
    print_separator();
}

void main_menu()
{
    print_header("MAIN MENU");
    cout << " [1] Users Menu" << el;
    cout << " [2] Books Menu" << el;
    cout << " [3] Exit" << el;
    print_separator();
    cout << "Enter your choice: ";
}

void users_menu()
{
    print_header("USERS MENU");
    cout << " [1] Create a new user" << el;
    cout << " [2] Search for a user" << el;
    cout << " [3] Display all users" << el;
    cout << " [4] Delete a user" << el;
    cout << " [5] Back to Main Menu" << el;
    print_separator();
    cout << "Enter your choice: ";
}

void book_menu()
{
    print_header("BOOKS MENU");
    cout << " [1] Create a new book" << el;
    cout << " [2] Search for a book" << el;
    cout << " [3] Display all books" << el;
    cout << " [4] Delete a book" << el;
    cout << " [5] Rate book" << el;
    cout << " [6] Set book author" << el;
    cout << " [7] Get all books by an author" << el;
    cout << " [8] Back to Main Menu" << el;
    print_separator();
    cout << "Enter your choice: ";
}

int main()
{
    cout << "*********************************** Welcome to the Online Library System ***********************************" << el << el;

    cout << "How many users would you like to add? ";
    int number_of_users; cin >> number_of_users;
    cout << el;

    cout << "How many books would you like to add? ";
    int number_of_books; cin >> number_of_books;
    cout << el;

    UserList ul(number_of_users);
    BookList bl(number_of_books);

    while (true)
    {
        main_menu();
        int mainChoice; cin >> mainChoice;
        cout << el;

        if (mainChoice == 1)
        {
            while (true)
            {
                users_menu();
                int userChoice; cin >> userChoice;
                cout << el;

                if (userChoice == 1)
                {
                    User u; cin >> u;
                    ul.addUser(u);
                    cout << "User added successfully!" << el << el;
                }
                else if (userChoice == 2)
                {
                    cout << "Enter User ID: ";
                    int id; cin >> id;
                    cout << el;
                    if (ul.searchUser(id) == nullptr)
                    {
                        cout << "User not found." << el << el;
                    }
                    else
                    {
                        cout << "User found." << el << el;
                    }
                }
                else if (userChoice == 3)
                {
                    cout << "Displaying all users:" << el;
                    cout << ul << el;
                }
                else if (userChoice == 4)
                {
                    cout << "Enter User ID to delete: ";
                    int id; cin >> id;
                    cout << el;
                    if (ul.searchUser(id) == nullptr)
                    {
                        cout << "User not found." << el << el;
                    }
                    else
                    {
                        ul.deleteUser(id);
                        cout << "User deleted successfully." << el << el;
                    }
                }
                else if (userChoice == 5)
                {
                    cout << "Returning to the Main Menu..." << el << el;
                    break;
                }
                else
                {
                    cout << "ERROR: Invalid choice. Please select a valid option." << el << el;
                }
            }
        }
        else if (mainChoice == 2)
        {
            while (true)
            {
                book_menu();
                int bookChoice; cin >> bookChoice;
                cout << el;

                if (bookChoice == 1)
                {
                    Book book; cin >> book;
                    bl.addBook(book);
                    cout << "Book added successfully!" << el << el;
                }
                else if (bookChoice == 2)
                {
                    cout << "Enter Book ID: ";
                    int id; cin >> id;
                    cout << el;
                    if (bl.searchBook(id) == nullptr)
                    {
                        cout << "Book not found." << el << el;
                    }
                    else
                    {
                        cout << "Book found." << el << el;
                    }
                }
                else if (bookChoice == 3)
                {
                    cout << "Displaying all books:" << el;
                    cout << bl << el;
                }
                else if (bookChoice == 4)
                {
                    cout << "Enter Book ID to delete: ";
                    int id; cin >> id;
                    cout << el;
                    if (bl.searchBook(id) == nullptr)
                    {
                        cout << "Book not found." << el << el;
                    }
                    else
                    {
                        bl.deleteBook(id);
                        cout << "Book deleted successfully." << el << el;
                    }
                }
                else if (bookChoice == 5)
                {
                    cout << "Enter Book ID: ";
                    int id; cin >> id;
                    cout << el;

                    if (bl.searchBook(id) == nullptr)
                    {
                        cout << "Book not found." << el << el;
                    }
                    else
                    {
                        cout << "Enter book rating (1:5): ";
                        double rating; cin >> rating;
                        cout << el;

                        if (rating > 5 || rating < 1)
                        {
                            cout << "Invalid rating. Please enter a value between 1 and 5." << el << el;
                        }
                        else
                        {
                            bl[id - 1].rateBook(rating);
                            cout << "Book rated successfully!" << el << el;
                        }
                    }
                }
                else if (bookChoice == 6)
                {
                    cout << "Enter Book ID: ";
                    int id; cin >> id;
                    cout << el;

                    if (bl.searchBook(id) == nullptr)
                    {
                        cout << "Book not found." << el << el;
                    }
                    else
                    {
                        cout << "Enter Author ID: ";
                        int authorId; cin >> authorId;
                        cout << el;

                        if (ul.searchUser(authorId) == nullptr)
                        {
                            cout << "Author not found." << el << el;
                        }
                        else
                        {
                            bl[id - 1].setAuthor(ul[authorId - 1]);
                            cout << "Author set successfully!" << el << el;
                        }
                    }
                }
                else if (bookChoice == 7)
                {
                    cout << "Enter Author ID : ";
                    int id; cin >> id;
                    cout << el;
                    bl.getBooksForUser(ul[id - 1]);
                }
                else if (bookChoice == 8)
                {
                    cout << "Returning to the Main Menu..." << el << el;
                    break;
                }
                else
                {
                    cout << "ERROR: Invalid choice. Please select a valid option." << el << el;
                }
            }
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting the system. Goodbye!" << el;
            return 0;
        }
        else
        {
            cout << "ERROR: Invalid choice. Please select a valid option." << el << el;
        }
    }
}