#include <iostream>
#include <string.h>

#define el "\n"

using namespace std;

class User 
{
private:
    int age, id;
    string name, email, password;

public:
    static int count;


    User();
    User(string name, int age, string email, string password);
    User(const User&);
  

    void setName(string);
    string getName() const;
    void setPassword(string);
    string getPassword()const;
    void setEmail(string);
    string getEmail()const;
    void setAge(int);
    int getAge()const;
    void setId(int);
    int getId()const;
    int getCount()const;
    void setCount(int);


    void DisplayInfo();


    bool operator==(const User&);
    friend ostream& operator<<(ostream&, const User&);
    friend istream& operator>>(istream&, User&);
};