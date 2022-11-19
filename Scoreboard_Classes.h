#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Team
{
	private:

		string name;
		bool home;
		int score;

	public:

		// Constructors.

		Team() { name = "Default_Team_Name"; home = true; score = 0; }

		// Mutator Methods

		void Set_Name(string n) { name = n; }
		void Set_Home(bool h) { home = h; }
		void Set_Score(int s) { score = s; }

		// Accessor Methods

		string Get_Name() const { return name; }
		bool Get_Home() const { return home; }
		int Get_Score() const { return score; }

		// Destructors.

		~Team() { ; }
};

class Scoreboard
{
	private:

		Team team1;
		Team team2;

		short down;
		short togo;
		short quarter;

	public:

		// Constructors.

		Scoreboard() { quarter = 1; down = 1; togo = 10; }

		// Mutator Methods

		void Set_Team1(Team& t1) { team1 = t1; }
		void Set_Team2(Team& t2) { team2 = t2; }
		void Set_Down(short d) { down = d; }
		void Set_Togo(short y) { togo = y; }
		void Set_Quarter() { ++quarter; }

		// Accessor Methods

		Team Get_Team1() const { return team1; }
		Team Get_Team2() const { return team2; }
		short Get_Down() const { return down; }
		short Get_Togo() const { return togo; }
		short Get_Quarter() const { return quarter; }

		// Destructors.

		~Scoreboard() { ; }
};
