#include "BookList.h"

BookList::BookList()
{
	capacity = 0;
	booksCount = 0;
}

BookList::BookList(int capacity)
{
	this->capacity = capacity;
	booksCount = 0;
	books = new Book[capacity];

	Book::count -= capacity; //book when array was created incremented count of books capacity times
}

void BookList::addBook(const Book& book)
{
	if (booksCount < capacity)
	{
		books[booksCount] = book;
		booksCount++;
	}
	else
	{
		cout << "List is full" << el;
	}
}

Book* BookList::searchBook(string title)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getTitle() == title)
		{
			return &books[i];
		}
	}
	return nullptr;
}

Book* BookList::searchBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id)
		{
			return &books[i];
		}
	}
	return nullptr;
}

void BookList::deleteBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (id == books[i].getId())
		{
			for (int j = i; j < booksCount - 1; j++)
			{
				books[j] = books[j + 1];

				books[j].setId(books[j].getId() - 1);
				Book::count--;
			}
			booksCount--;
			capacity--;
			break;
		}
	}
}

void BookList::getBooksForUser(const User& user)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAuthor() == user)
		{
			cout << books[i];
		}
	}
}

Book& BookList::operator[](int position)
{
	if (position >= 0 && position < booksCount)
	{
		return books[position];
	}
	else
	{
		cout << "Position error" << el;
		exit(1);
	}
}

BookList::~BookList()
{
	delete[] books;
}

ostream& operator<<(ostream& output, const BookList& booklist)
{
	for (int i = 0; i < booklist.booksCount; i++)
	{
		output << booklist.books[i];
	}
	return output;
}
