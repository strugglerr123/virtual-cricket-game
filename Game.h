#include<cstdlib>
#include<climits>
#include<ctime>
#include<limits>
#include<unistd.h>
#include "Team.h"

class Game{
public:
	int playerperteam;
	int maxballs;
	int totalplayers;
	std::string players[11];

	bool isfirstinnings;
	Tteam teamA,teamB;
	Tteam *battingteam,*bowlingteam;
	Player *batsman,*bowler;
	Game();
	void instruction();
	void press_enter();
	void show_player();
	int take_integer_input();
	void select_player();
	void show_teams();
	void toss();
	void choose(Tteam);
	void print_first_inning();
	void initialise_player();
	void play_inning();
	void bat();
	bool check_innings();

};
