#include <iostream>
#include <string>

#include "BookList.h"

#define el "\n"

using namespace std;


int main()
{

	BookList bl(5);
	Book b1, b2, b3;

	b1.rateBook(1);
	b2.rateBook(2);
	b3.rateBook(3);

	bl.addBook(b1);
	bl.addBook(b2);
	bl.addBook(b3);

	Book hrb = bl.getTheHighestRatedBook();

	cout << hrb;
}