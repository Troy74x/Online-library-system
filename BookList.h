#include "UserList.h"

class BookList 
{
private:
	Book* books;
	int capacity;
	int booksCount;

public:
	BookList();
	BookList(int);

	void addBook(const Book&);
	Book* searchBook(string);
	Book* searchBook(int);
	void deleteBook(int); 
	void getBooksForUser(const User&); 

	Book& operator[] (int);

	friend ostream& operator<<(ostream&, const BookList&); 

	~BookList();
};