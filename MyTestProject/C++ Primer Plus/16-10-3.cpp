// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include "test.h"
// constants
// function prototype
using namespace std;
//const int NUM = 26;
vector<string> wordlist;
void ReadWord();
//const string wordlist[NUM] = { "apiary","beetle","cereal","danger","ensign","florid",
//"garage","health","insult","jackal" ,"keeper","loaner","manage","nonce","onset",
//"plaid","quilt","remote","stolid","train","useful","valid","whence","xenon","yearn",
//"zippy" };

int main(void)
{
	srand(time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	ReadWord();
	while (play == 'y')
	{
		string target = wordlist[rand() % wordlist.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret woed. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n>";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void ReadWord()
{
	ifstream in;
	string temp;
	in.open("test.txt");
	if (in.is_open() == false)
	{
		cout << "File open error!\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		while (in)
		{
			in >> temp;
			wordlist.push_back(temp);
		}		
	}
	in.close();
}
