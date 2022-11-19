/*
	Ruben Cobos
	11/19/2022
	COSC-1437-58001
	Microsoft Visual Studio Community 2022 (64-bit)
	Unit 4 Assignment - Football Scoreboard
	-----------------------------------------------
 */

#include "Scoreboard_Classes.h"
#include "Input_Validation.h"

void Display_Scoreboard(Scoreboard&, int&, int&, string&, string&);
void Display_Menu();
void Process_Option(Scoreboard&);


int main()
{
	Scoreboard football;

	clock_t t1 = 0;
	clock_t t2 = 0;

	int minutes = 15;
	int seconds = 0;

	string color = "\x1b[47;1m";
	string reset = "\x1b[0m";

	while (true)
	{
		t1 = clock();

		Display_Scoreboard(football, minutes, seconds, color, reset);
		Display_Menu();

		// Ask for user input every minute.

		if (seconds == 0)
		{
			seconds = 60;
			--minutes;

			Process_Option(football);
		}

		// Wait a second.

		while (((t2 - t1) / CLOCKS_PER_SEC) < 1)
		{
			t2 = clock();
		}

		// Approximately 1 second has passed.

		--seconds;

		// End of quarter.

		if (minutes == 0 && seconds == 0 && football.Get_Quarter() < 4)
		{
			cout << '\a';
			football.Set_Quarter();
			minutes = 15;
			seconds = 0;
		}
		
		// End of game.

		if (minutes == 0 && seconds == 0 && football.Get_Quarter() == 4)
		{
			cout << '\a';
			system("clear");
			Display_Scoreboard(football, minutes, seconds, color, reset);
			Display_Menu();
			Process_Option(football);
			system("clear");
			Display_Scoreboard(football, minutes, seconds, color, reset);
			Display_Menu();
			break;
		}

		system("clear");

	}

	return 0;
}

void Display_Scoreboard(Scoreboard& f, int& m, int& s, string &c, string& r)
{
	cout << c;
	cout << setw(67) << setfill('=') << '=' << endl;
	cout << setw(24) << setfill(' ') << ' ';
	cout << "FOOTBALL SCOREBOARD";
	cout << setw(24) << setfill(' ') << ' ' << endl;
	cout << setw(67) << setfill('=') << '=' << endl;
	cout << setw(30) << setfill(' ') << left << "HOME";
	cout << "       ";
	cout << setw(30) << right << "VISITOR" << endl;
	cout << setw(30) << left << f.Get_Team1().Get_Name();
	cout << ' ' << setw(2) << setfill('0') << right << m;
	cout << ':';
	cout << setw(2) << setfill('0') << right << s << ' ';
	cout << setfill(' ');
	cout << setw(30) << right << f.Get_Team2().Get_Name() << endl;
	cout << setw(30) << left << f.Get_Team1().Get_Score();
	cout << " QTR " << f.Get_Quarter() << ' ';
	cout << setw(30) << right << f.Get_Team2().Get_Score() << endl;
	cout << "DWN " << f.Get_Down();
	cout << setw(60);
	cout << " YDS ";
	cout << setw(2) << right << f.Get_Togo() << endl;
	cout << setw(67) << setfill('=') << '=' << endl;
	cout << r;
}

void Display_Menu()
{
	cout << "\nMAIN MENU" << endl;
	cout << "---------" << endl;
	cout << "1.) Update Home Team" << endl;
	cout << "2.) Update Visitor Team" << endl;
	cout << "3.) Update Home Team Score" << endl;
	cout << "4.) Update Visitor Team Score" << endl;
	cout << "5.) Update Down" << endl;
	cout << "6.) Update Yards To Go" << endl;
	cout << "7.) Done" << endl;
	cout << "---------" << endl << endl;
}

void Process_Option(Scoreboard& s)
{
	int input = 0;
	int option = 0;
	string token = "";
	string name = "";

	Team t;

	do
	{
		name = "";

		cout << "Choose an option: ";
		option = Validate_Integer(option);

		switch (option)
		{
			case 1: // Update home team.
			{
				do
				{
					cout << "How many words is the team name (max 3)? : ";
					input = Validate_Integer(input);
				}
				while (input < 1 || input > 3);

				for (int i = 0; i < input; ++i)
				{
					cout << "Enter next word: ";
					token = Validate_Word(token);
					name.append(token);
					if (i != (input - 1))
					{
						name.append(" ");
					}
				}

				t.Set_Name(name);
				t.Set_Home(true);
				s.Set_Team1(t);

				break;
			}
			case 2: // Update visitor team.
			{
				do
				{
					cout << "How many words is the team name (max 3)? : ";
					input = Validate_Integer(input);
				}
				while (input < 1 || input > 3);

				for (int i = 0; i < input; ++i)
				{
					cout << "Enter next word: ";
					token = Validate_Word(token);
					name.append(token);
					if (i != (input - 1))
					{
						name.append(" ");
					}
				}

				t.Set_Name(name);
				t.Set_Home(false);
				s.Set_Team2(t);

				break;
			}
			case 3: // Update home team score.
			{
				do
				{
					cout << "Enter new score: ";
					input = Validate_Integer(input);
				}
				while (input < 0 || input > 1000);

				t = s.Get_Team1();
				t.Set_Score(input);
				s.Set_Team1(t);

				break;
			}
			case 4: // Update visitor team score.
			{
				do
				{
					cout << "Enter new score: ";
					input = Validate_Integer(input);
				}
				while (input < 0 || input > 1000);

				t = s.Get_Team2();
				t.Set_Score(input);
				s.Set_Team2(t);

				break;
			}
			case 5: // Update down.
			{
				do
				{
					cout << "Enter new down: ";
					input = Validate_Integer(input);
				}
				while (input < 1 || input > 4);

				s.Set_Down(input);

				break;
			}
			case 6: // Update yards to go.
			{
				do
				{
					cout << "Enter yards to go: ";
					input = Validate_Integer(input);
				}
				while (input < 0 || input > 10);

				s.Set_Togo(input);

				break;
			}
			case 7: // Done.
			{
				break;
			}
			default: // Invalid option.
			{
				cout << "Invalid option.\n";
			}
		}
	} while (option != 7);
}