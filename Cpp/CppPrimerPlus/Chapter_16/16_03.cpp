#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	char play;

	std::ifstream ifs;
	ifs.open("data.txt", std::ifstream::in);
	std::string word;
	std::vector<string> wordlist;
	if (ifs.good())
	{
		while (ifs >> word)
			wordlist.push_back(word);
	}
	int length = wordlist.size();
	cout << "Will you play a word game? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % wordlist.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess" << endl
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses." << endl;
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again" << endl;
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!" << endl;
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!" << endl;
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
				cout << guesses << " bad guesses left" << endl;
			}
		}
		if (guesses > 0)
			cout << "That's right!" << endl;
		else
			cout << "Sorry, the word is " << target << endl;
		cout << "Will you play another? <y/n>";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye" << endl;
	ifs.close();

	system("pause");
	return 0;
}