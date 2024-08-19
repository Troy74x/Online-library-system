#include "Book.h"

int Book::count = 0;

Book::Book()
{
	count++;
	id = count;

	title = isbn = category = "";

	averageRating = 0.0;

	User author;
	author.setCount(author.getCount() - 2); //user when called in book.h and book.cpp incremented count of users 2 times

	numRates = 0;
	sumRates = 0.0;
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

	numRates = 0;
	sumRates = 0.0;
}

Book::Book(const Book& book)
{
	title = book.title;
	isbn = book.isbn;
	category = book.category;
	id = book.id;
	averageRating = book.averageRating;
	author = book.author;

	numRates = book.numRates;
	sumRates = book.sumRates;
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

void Book::rateBook(double rate)
{
	numRates++;
	sumRates += rate;
	averageRating = sumRates / numRates;
}

double Book::getAverageRating() const
{
	return averageRating;
}

bool Book::operator==(const Book& book)
{
	return title == book.title && isbn==book.isbn && category==book.category && id==book.id && averageRating==book.averageRating && author==book.author;
}

ostream& operator<<(ostream& output, const Book& book)
{
	output << "========================book " << book.id << " info========================" << el;

	output << "Title : " << book.title << " | ";
	output << "Isbn : " << book.isbn << " | ";
	output << "Category : " << book.category << " | ";
	output << "AvgRating: " << book.averageRating << el;

	////////////////////////////////////////////////////////////
	if (book.author.getName() != "")
	{
		cout << book.author;
	}
	////////////////////////////////////////////////////////////

	cout << "============================================================" << el;
	return output;
}

istream& operator>>(istream& input, Book& book)
{
	cout << "Enter book information in this order : Title Isbn Cateogry" << el;
	input >> book.title >> book.isbn >> book.id;
	return input;
}
