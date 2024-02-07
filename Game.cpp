#include "Game.h"
using namespace std;


Game::Game(){

	int i=0;
	while(i<=20){
		if(i&1)cout<<"@"<<"-";
		else cout<<"#"<<"-";
		i++;
	}

	cout<<"\n";
	cout<<"|\t\t\t\t\t|\n|\t\"Welcome to virtual game\" \t|"<<"\n";
	cout<<"|\t\t\t\t\t|\n";


	i=0;
	while(i<=20){
		if(i&1)cout<<"@"<<"-";
		else cout<<"#"<<"-";
		i++;
	}



	playerperteam=4;
	maxballs=6;
	totalplayers=11;

	players[0]="Virat";
	players[1]="Rohit";
	players[2]="Dhawan";
	players[3]="Pant  ";
	players[4]="Karthik";
	players[5]="Klrahul";
	players[6]="Jadeja";
	players[7]="Hardik";
	players[8]="Bumrah";
	players[9]="Bkumar";
	players[10]="Ishant";


	isfirstinnings=false;
	teamA.name="Team-A";
	teamB.name="Team-B";

}

void Game::instruction(){
	cout<<endl<<endl;
	int i=0;
	while(i<=20){
		if(i&1)cout<<"$"<<"-";
		else cout<<"%"<<"-";
		i++;
	}
	cout<<endl;
	cout<<"|\t\t\t\t\t|\n|===========\"INSTRUCTIONS\"==============|"<<endl;
	cout<<"|\t\t\t\t\t|\n";
	cout<<"|->>1. Create a two teams with 4 players|\n";
	cout<<"|->>2. Lead the toss and decide the \t|\n";
	cout<<"|\t choice of play .\t\t|\n";
	cout<<"|->>3. Each inning is of 6 balls.\t|\n";
	cout<<"|\t\t\t\t\t|\n";

	i=0;
	while(i<=20){
		if(i&1)cout<<"$"<<"-";
		else cout<<"%"<<"-";
		i++;
	}
}

void Game::press_enter(){
	cout<<endl<<endl;
	cout << "\tPress Enter to Continue ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void Game::show_player(){
	cout<<endl<<endl;
	int i=0;
	while(i<=20){
		if(i&1)cout<<"$"<<"-";
		else cout<<"%"<<"-";
		i++;
	}
	cout<<endl;
	cout<<"|\t\t\t\t\t|\n|===========\"POOL OF PLAYERS\"===========|"<<endl;
	cout<<"|\t\t\t\t\t|\n";

	for(int i=0;i<11;i++){
		cout<<"|\t\t"<<i+1<<". "<<players[i]<<"\t\t|\n";
	}
	cout<<"|\t\t\t\t\t|\n";

	i=0;
	while(i<=20){
		if(i&1)cout<<"$"<<"-";
		else cout<<"%"<<"-";
		i++;
	}
}

int Game::take_integer_input(){
	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"|\tPlease enter valid numeric keyword "<<endl;
	}
	return n;
}

void Game::select_player(){

//	show_player();
	press_enter();

	cout<<endl<<endl;
	int i=0;
	while(i<=20){
		if(i&1)cout<<"$"<<"-";
		else cout<<"%"<<"-";
		i++;
	}
	cout<<endl;
	cout<<"|\t\t\t\t\t|\n|=========\"CREATE TEAM A AND B\"=========|"<<endl;
	cout<<"|\t\t\t\t\t|\n";

	vector<bool>check(11);

	for(int i=0;i<playerperteam;i++){
		team_selection:

		cout<<"|\tSelect the player "<<i+1<<" of Team-A -"<<flush;
		int playerindexteamA=take_integer_input();
		if(playerindexteamA<0||playerindexteamA>10){
			cout<<"|\tPlease enter the valid index "<<endl;
			goto team_selection;
		}
		else if(check[playerindexteamA]>=1){
			cout<<"|\tSorry you can't select this player "<<endl;
			goto team_selection;
		}

		else{
		check[playerindexteamA]=1;
		Player teamplayer;
		teamplayer.id=playerindexteamA;
		teamplayer.name=players[playerindexteamA];
		teamA.player.push_back(teamplayer);
		}

		teamB_selection:
		cout<<"|\tSelect the player "<<i+1<<" of Team-B -"<<flush;
		int playerindexteamB=take_integer_input();
		if(playerindexteamB<0||playerindexteamB>10){
			cout<<"|\tEnter the valid index "<<endl;
			goto teamB_selection;
		}
		else if(check[playerindexteamB]>=1){
			cout<<"|\tSorry you can't select this player "<<endl;
			goto teamB_selection;
		}
		else{
		check[playerindexteamB]=1;
		Player teamBplayer;
		teamBplayer.id=playerindexteamB;
		teamBplayer.name=players[playerindexteamB];
		teamB.player.push_back(teamBplayer);
		}
	}
}

void Game::show_teams(){
	cout<<endl<<endl;
	cout<<"-------------------------";      cout<<"\t\t-------------------------"<<endl;
	cout<<"|======= Team-A =========|";     cout<<"\t\t|======= Team-B =========|"<<endl;
	cout<<"-------------------------";      cout<<"\t\t--------------------------"<<endl;
	for(int i=0;i<4;i++){
		cout<<"|\t["<<i<<"]"<<players[(teamA.player[i]).id]<<"\t|\t\t|\t["<<i<<"]"<<players[(
				teamB.player[i]).id]<<"\t|\n";
	}
	cout<<"-------------------------";      cout<<"\t\t-------------------------"<<endl;

}

void Game::toss(){

	cout<<endl<<endl;
	srand(time(0));
	int res=rand()%(2);

	cout<<"Tossing the coin............"<<endl<<endl;
	sleep(3);

	if(res){
		cout<<"Team-A won the Toss "<<endl<<endl;
		choose(teamA);
	}
	else {
		cout<<"Team-B won the Toss "<<endl<<endl;
		choose(teamB);
	}

}

void Game::choose(Tteam winner){

	cout<<"Enter 1 to Bat or 2 to Bowl first. "<<endl;
	int choise=take_integer_input();


	switch(choise){

	case (1):
		cout<<winner.name<<" Won the toss and choose to Bat first "<<endl;
		if(winner.name=="Team-A"){
			battingteam=&teamA;
			bowlingteam=&teamB;
		}
		else{
			battingteam=&teamB;
			bowlingteam=&teamA;
		}
		break;

	case 2:
		cout<<winner.name<<" Won the toss and choose to Bowl first "<<endl;
		if(winner.name=="Team-A"){
			battingteam=&teamB;
		    bowlingteam=&teamA;
		}
		else{
			battingteam=&teamA;
			bowlingteam=&teamB;
		}
		break;
	default:
		cout<<" Please enter valid input "<<endl;
			choose(winner);
			break;
	}


}

void Game::print_first_inning(){
	cout<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<"|======== Let's Toss ========"<<endl;
	cout<<"------------------------------"<<endl;

	isfirstinnings=true;
	initialise_player();
	play_inning();
}

void Game::initialise_player(){
	batsman=&battingteam->player[0];
	bowler=&bowlingteam->player[0];

	cout<<battingteam->name<<" "<<batsman->name<<" is batting "<<endl;
	cout<<bowlingteam->name<<" "<<bowler->name<<" is bowling "<<endl<<endl;;

}

void Game::play_inning(){

	for(int i=0;i<maxballs;i++){
		cout<<"Press enter to ball........"<<endl;
		getchar();
		cout<<"Bowling.........."<<endl;
		bat();

		if(!check_innings()){
			break;
		}
		cout<<"---------------------------------------------------------"<<endl;
		cout<<battingteam->name<<" "<<battingteam->totalrunscored<<" - "<<
				battingteam->wicketslost<<" ( "<<battingteam->totalballsbowled<<" ) "<<
				batsman->name<<" "<<batsman->runscored<<" ( "<<batsman->ballsplayed<<" ) "<<
				bowler->name<<" - "<<bowler->ballsbowled<<" - "<<bowler->runsgiven<<" - "<<
				bowler->wicketstaken<<endl;
		cout<<"-----------------------------------------------------------"<<endl;


	}
}

void Game::bat(){

	srand(time(0));
	int run=rand()%7;
	batsman->runscored+=run;
	battingteam->totalrunscored+=run;
	batsman->ballsplayed+=1;

	bowler->ballsbowled+=1;
	bowlingteam->totalballsbowled+=1;
	battingteam->totalballsbowled+=1;
	bowler->runsgiven+=run;


	cout<<endl;

	if(run==0){
		cout<<bowler->name<<" to "<<batsman->name<<" OUT !!!!!"<<endl<<endl;

		bowler->wicketstaken=bowler->wicketstaken+1;

	}
	else{
	cout<<bowler->name<<" to "<<batsman->name<<" "<<run<<" runs. "<<endl<<endl;

	battingteam->wicketslost=battingteam->wicketslost+1;
	bowlingteam->wicketstaken=bowlingteam->wicketstaken+1;

	int index_next_player=battingteam->wicketslost;
	batsman=&battingteam->player[index_next_player];
	}

}

bool Game::check_innings(){

	if(isfirstinnings){
		if(battingteam->wicketslost==playerperteam|| bowlingteam->totalballsbowled==maxballs){

			cout<<"\t\t |||| FIRST INNING ENDS ||||"<<endl<<endl;
			cout<<battingteam->name<<" "<<battingteam->totalrunscored<<" --- "<<
					battingteam->wicketslost<<" ("<<bowlingteam->totalballsbowled<<" )"<<endl;
			cout<<bowlingteam->name<<" needs "<<battingteam->totalrunscored+1<<" "<<""
					" runs to win "<<endl<<endl;

			return false;
		}
	}

	return true;
}




