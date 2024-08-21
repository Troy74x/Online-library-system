#include "UserList.h"

UserList::UserList()
{
	usersCount = 0;
	capacity = 0;
}

UserList::UserList(int capacity)
{
	usersCount = 0;
	this->capacity = capacity;
	users = new User[capacity];

	User::count -= capacity; //user when array was created incremented count of users capacity times
}

void UserList::addUser(User& user)
{
	if (usersCount < capacity)
	{
		users[usersCount] = user;
		usersCount++;
	}
	else
	{
		cout << "List is full" << el;
	}
}

User* UserList::searchUser(string name)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (name == users[i].getName())
		{
			return &users[i];
		}
	}
	return nullptr;
}

User* UserList::searchUser(int id)
{

	for (int i = 0; i < usersCount; i++)
	{
		if (id == users[i].getId())
		{
			return &users[i];
		}
	}
	return nullptr;
}

void UserList::deleteUser(int id)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (id == users[i].getId())
		{
			for (int j = i; j < usersCount-1; j++)
			{
				users[j] = users[j + 1];

				users[j].setId(users[j].getId() - 1);
				User::count--;
			}
			usersCount--;
			capacity--;
			break;
		}
	}
}

UserList::~UserList()
{
	delete[] users;
}

ostream& operator<<(ostream& output, const UserList& userlist)
{
	for (int i = 0; i < userlist.usersCount; i++)
	{
		output << userlist.users[i];
	}
	return output;
}
