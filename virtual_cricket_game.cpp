#include "Game.h"
using namespace std;

int main(){
	Game g;
	g.instruction();
	g.press_enter();
	g.show_player();
//	g.take_integer_input();
	g.select_player();
	g.show_teams();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	g.press_enter();
	g.toss();

	Tteam winner;

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	g.print_first_inning();
	g.play_inning();

	return 0;
}
