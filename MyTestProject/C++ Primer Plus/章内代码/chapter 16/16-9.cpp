// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "test.h"
// constants
// function prototype
using namespace std;
struct Review
{
	string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
bool operator<(const Review &r1, const Review &r2);
bool worseThan(const Review &r1, const Review &r2);
int main(void)
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "Sorted by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
bool FillReview(Review & rr)
{
	cout << "Enter book title(quit to quit):";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review & rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}

bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title&&r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
	if(r1.rating < r2.rating)
		return true;
	else
		return false;
}



