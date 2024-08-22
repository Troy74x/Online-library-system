#include <iostream>
#include <string.h>

#include"User.h"

#define el "\n"

using namespace std;

class Book
{
private:
	string title, isbn, category;

	int id;
	double averageRating,numRates,sumRates;

	User author;

public:
	static int count;

	Book();
	Book(string title, string isbn, string category);
	Book(const Book&);

	void setTitle(string);
	string getTitle() const;
	void setIsbn(string);
	string getIsbn() const;
	void setId(int);
	int getId() const;
	void setCategory(string);
	string getCategory()const;
	void setAuthor(const User&);
	User getAuthor() const;

	void rateBook(double);
	double getAverageRating() const;

	bool operator==(const Book&);
	friend ostream& operator<<(ostream&, const Book&);
	friend istream& operator>>(istream&, Book&);
};

