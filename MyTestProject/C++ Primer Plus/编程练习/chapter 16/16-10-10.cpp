// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>
#include<cctype>
#include "test.h"
// constants
// function prototype
using namespace std;
struct Review
{
	string title;
	int rating;
	double price;
};
bool FillReview(shared_ptr<Review> & rr);
void ShowReview(const shared_ptr<Review> & rr);
bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThanPrice(const shared_ptr<Review> &r1, const shared_ptr<Review> & r2);
int main(void)
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);
	while (FillReview(temp))
	{
		books.push_back(temp);
		temp = shared_ptr<Review>(new Review);
	}
		
	if (books.size() > 0)
	{
		vector<shared_ptr<Review>> sbooks(books);
		sort(sbooks.begin(), sbooks.end());
		vector<shared_ptr<Review>> rbooks(books);
		sort(rbooks.begin(), rbooks.end(),worseThan);
		vector<shared_ptr<Review>> pbooks(books);
		sort(pbooks.begin(), pbooks.end(), worseThanPrice);
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n"
			<< "Rating\tBook\t\tPrice\n";
		for_each(books.begin(), books.end(), ShowReview);
		char ch;
		cout << "Enter the measure of sort\n";
		cout << "o to the old\t\ts to up string\t\tR to up rating\nr to down rating\tP to up price\t\tp to down price\n"
			<< "q to quit\n";
		cin >> ch;
		while (tolower(ch) != 'q')
		{
			switch(ch)
			{
			case 'o':
				cout << "The original array:\nRating\tBook\t\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 's':
				cout << "The sorted by up string:\nRating\tBook\t\tPrice\n";
				for_each(sbooks.begin(), sbooks.end(), ShowReview);
				break;
			case 'R':
				cout << "The sorted by up rating:\nRating\tBook\t\tPrice\n";;
				for_each(rbooks.begin(), rbooks.end(), ShowReview);
				break;
			case 'r':
				cout << "The sorted by down rating:\nRating\tBook\t\tPrice\n";;
				for_each(rbooks.rbegin(), rbooks.rend(), ShowReview);
				break;
			case 'P':
				cout << "The sorted by up price:\nRating\tBook\t\tPrice\n";;
				for_each(pbooks.begin(), pbooks.end(), ShowReview);
				break;
			case 'p':
				cout << "The sorted by down price:\nRating\tBook\t\tPrice\n";;
				for_each(pbooks.rbegin(), pbooks.rend(), ShowReview);
				break;
			default:
				cout << "You have enter the wrong char! Try again!\n";
			}
			cout << "Enter the measure of sort\n";
			cout << "o to the old\t\ts to up string\t\tR to up rating\nr to down rating\tP to up price\t\tp to down price\n"
				<< "q to quit\n";
			cin >> ch;
		}
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
bool FillReview(shared_ptr<Review> & rr)
{
	cout << "Enter book title(quit to quit):";
	getline(cin, rr->title);
	if (rr->title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr->rating;
	if (!cin)
		return false;
	cout << "Enter book price: ";
	cin >> rr->price;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
	cout << rr->rating << "\t" << rr->title <<"\t"<<rr->price<< endl;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title&&r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThanPrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}



