#include "Book.h"

class UserList
{
private:
    User* users;
    int capacity; //size
    int usersCount; //idx

public:
    UserList();
    UserList(int);

    void addUser(User&);
    User* searchUser(string);
    User* searchUser(int);
    void deleteUser(int);

    friend ostream& operator<<(ostream&, const UserList&);
    User& operator[] (int);

    ~UserList();
};

