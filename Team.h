#include<vector>
#include "Player.h"


class Tteam{
public:
	std::string name;
	int totalrunscored;
	int wicketslost;
	int wicketstaken;
	int totalballsbowled;
	std::vector<Player>player;
	Tteam();

};
