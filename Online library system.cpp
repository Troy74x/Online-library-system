#include <iostream>
#include <string>

#include "UserList.h";

#define el "\n"

using namespace std;


int main()
{
	UserList U(5);
	User u1, u2, u3;

	
	U.addUser(u1);
	U.addUser(u2);
	U.addUser(u3);
	U.deleteUser(2);
	cout << U;
}