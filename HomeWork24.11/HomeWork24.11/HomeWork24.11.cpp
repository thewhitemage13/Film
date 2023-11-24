#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct MoveInformation {

	string namefilm[10];
	string creatorfilm[10];
	string genrefilm[10];
	
	string symbol;
	string cr;
	string gen;
	int grade[10];
	int userchoice;
};

void Minfo(MoveInformation& s) {

	string filmname[10] = { "Mechanic: Resurrection", "Slenderman", "Gentlemen", "The Fugitive", "Operation Rescue", "Battle with the Devil", "Parker", "Ninja 2", "Legion", "Kickback" };
	string creator[10] = { "Dennis Ganzel", "Victor Surge", "Guy Ritchie", "Rick Roman Waugh", "Sam Hargrave", "Yuval Adler", "Taylor Hackford", "Isaac Florentine", "Brian Knappenberger", "Terry Miles" };
	string genre[10] = { "thriller","survival horror","crime","detective movie","thriller","fiction","action thriller","action thriller","documentary","comedy" };

	for (int i = 0; i < 10; i++)
	{
		s.namefilm[i] = filmname[i];
		s.creatorfilm[i] = creator[i];
		s.genrefilm[i] = genre[i];
		s.grade[i] = rand() % 10 + 2;
	}
}

void printinfo( MoveInformation& s) {

	for (int i = 0; i < 10; i++)
	{
		cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Grade: " << s.grade[i] << "\n";
		cout << s.creatorfilm[i] << "\n\n";
	}
}

void search(MoveInformation& s)
{
	cout << "Enter search system:1-name/2-creator/3-genre/4-show the most popular movies: ";
	cin >> s.userchoice;

	switch (s.userchoice)
	{
	case 1:
	{
		cout << "Enter film name: ";
		cin.ignore();
		getline(cin, s.symbol);

		for (int i = 0; i < 10; i++)
		{
			if (s.namefilm[i] == s.symbol)
			{
				cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Grade: " << s.grade[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
		break;
	}
	case 2:
	{
		cout << "Enter film creator: ";
		cin.ignore();
		getline(cin, s.cr);

		for (int i = 0; i < 10; i++)
		{
			if (s.creatorfilm[i] == s.cr)
			{
				cout << s.creatorfilm[i] << " " << s.namefilm[i] << " " << s.genrefilm[i] << "  Grade: " << s.grade[i] << "\n";

			}
		}
		break;
	}
	case 3:
	{
		cout << "Enter film genre: ";
		cin.ignore();
		cin >> s.gen;

		for (int i = 0; i < 10; i++)
		{
			if (s.genrefilm[i] == s.gen)
			{
				cout << s.genrefilm[i] << " " << s.namefilm[i] << " " << "  Grade: " << s.grade << " " << s.genrefilm[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
		break;
	}
	case 4:
	{
		cout << " the most popular movies: " << "\n";
		for (int i = 0; i < 10; i++)
		{
			if (s.grade[i] >= 10)
			{
				cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Grade: " << s.grade[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
	}
	}
}

int main()
{
	srand(time(NULL));
	MoveInformation now;
	Minfo(now);
	printinfo(now);
	search(now);
}