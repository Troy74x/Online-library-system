#include "User.h"

int User::count = 0;

User::User()
{
	count++;
	id = count;

	age = 0;
	name = email = password = "";
}

User::User(string name ,int age,string email,string password)
{
	count++;
	id = count;

	this->name = name;
	this->age = age;
	this->email = email;
	this->password = password;
}

User::User(const User& user)
{
	name = user.name;
	age = user.age;
	id = user.id;
	email = user.email;
	password = user.password;
}

void User::setName(string n)
{
	name = n;
}
string User::getName() const
{
	return name;
}

void User::setPassword(string p)
{
	password = p;
}
string User::getPassword() const
{
	return password;
}

void User::setEmail(string e)
{
	email = e;
}
string User::getEmail() const
{
	return email;
}

void User::setAge(int a)
{
	age = a;
}
int User::getAge() const
{
	return age;
}

void User::setId(int i)
{
	id = i;
}

int User::getId() const
{
	return id;
}

void User::DisplayInfo()
{
	cout << "========================User " << id << " info========================"<<el;
	cout << "Name : " << name << " | ";
	cout << "Age : " << age<< " | ";
	cout << "Email : " << email <<el;
	cout << "============================================================" << el;
}

bool User::operator==(const User& user)
{
	return name == user.name && age == user.age && id == user.id && email == user.email && password == user.password;
}

ostream& operator<<(ostream& output , const User& user)
{
	output << "========================User " << user.id << " info========================" << el;
	output << "Name : " << user.name << " | ";
	output << "Age : " << user.age << " | ";
	output << "Email : " << user.email << el;
	cout << "============================================================" << el;
	return output;
}

istream& operator>>(istream& input, User& user)
{
	cout << "Enter user information in this order" << el;
	cout << "Name Age Email Password" << el;
	input >> user.name >> user.age >> user.email >> user.password;
	return input;
}

