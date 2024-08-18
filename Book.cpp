#include "Book.h"

int Book::count = 0;

Book::Book()
{
	count++;
	id = count;

	title = isbn = category = "";

	averageRating = 0.0;

	User author;
}

Book::Book(string title, string isbn, string category)
{
	count++;
	id = count;

	this->title = title;
	this->isbn = isbn;
	this->category = category;

	averageRating = 0.0;

	User author;
}

Book::Book(const Book& book)
{
	title = book.title;
	isbn = book.isbn;
	category = book.category;
	id = book.id;
	averageRating = book.averageRating;
	author = book.author;
}

void Book::setTitle(string t)
{
	title = t;
}
string Book::getTitle() const
{
	return title;
}

void Book::setIsbn(string i)
{
	isbn = i;
}
string Book::getIsbn() const
{
	return isbn;
}

void Book::setId(int i)
{
	id = i;
}
int Book::getId() const
{
	return id;
}

void Book::setCategory(string c)
{
	category = c;
}
string Book::getCategory() const
{
	return category;
}

void Book::setAuthor(const User& u)
{
	author = u;
}
User Book::getAuthor() const
{
	return author;
}

double Book::getAverageRating() const
{
	return averageRating;
}
