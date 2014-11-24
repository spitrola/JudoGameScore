/*==============================================================================================================
================================================================================================================
Sonia Pitrola
Comp 2231
Section 001
Assignment 4
Jason Heard
********************PURPOSE********************
The purpose of this assignment is to calculate the judo scores.

********************METHOD*********************
The method of this assignment is to determine the player scoring the point using a switch, determining the 
point that the player scored also using a switch. Determining the winner from who has the highest score. 

******************LIMITATIONS******************
The limitations of this assignment is that it doesn't account for penalties and medical time outs.

================================================================================================================
===============================================================================================================*/
#include <iostream>
using namespace std;

const int WAZA_ARI_WEIGHT = 1000;
const int YUKO_WEIGHT = 10;
const int KOKA_WEIGHT = 1;
const int IPPOIN_WEIGHT=10000;

void score_turn (int &whiteplayer, int &blueplayer, bool &endGame);
void score_point (int &player, bool &endGame);
void score_waza_ari (int &player, bool &endGame);
void winner_determination (int &blueplayer, int &whiteplayer, bool &blue_wins);
void score_whitePlayer (int &white_Waza_Ari, int &white_Yuko, int &white_KoKa, int &whiteplayer);
void score_bluePlayer (int &blue_Waza_Ari, int &blue_Yuko, int &blue_KoKa, int &blueplayer);
void score_match (bool &blue_wins, int &blue_Waza_Ari, int &blue_Yuko, int &blue_KoKa, int &white_Waza_Ari, int &white_Yuko, int &white_KoKa);
void display_score (int blue_Waza_Ari, int blue_Yuko, int blue_KoKa, int white_Waza_Ari, int white_Yuko, int white_KoKa);

int main ()
{
    int blue_Waza_Ari=0;
    int blue_Yuko=0;
    int blue_KoKa=0;
    int white_Waza_Ari=0;
    int white_Yuko=0;
    int white_KoKa=0;
    bool blue_wins; 
    score_match (blue_wins, blue_Waza_Ari, blue_Yuko, blue_KoKa, white_Waza_Ari, white_Yuko, white_KoKa);
    display_score (blue_Waza_Ari, blue_Yuko, blue_KoKa,  white_Waza_Ari, white_Yuko, white_KoKa);

    if (blue_wins)
    {
	cout <<"Blue!" <<endl;
    }    
    else
    {
	cout <<"White!" <<endl;
    }
    return 0;
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of the score turn function is to determine which player scored. Either blue or white player.
********************METHOD*********************
The method of the score turn function is to use a switch. With the parameters as white player, blue player and
end game. 

read in player choice
**use a switch**
if player choice is W then the point goes to white player
which then goes into the next function called score point

if player choice is B then the point goes to blue player
which then goes into the next function called score point

******************LIMITATIONS*******************
The limitations for the score turn function is that if an incorrect player is entered it will prompt for
a correct input.
================================================================================================================
===============================================================================================================*/
void score_turn (int &whiteplayer, int &blueplayer, bool &endGame)
{
    char playerchoice;
    cin >> playerchoice;
    switch (playerchoice)
    {
    case 'W':
    case 'w':
        score_point (whiteplayer, endGame);
        break;
    case 'B':
    case 'b':
	score_point (blueplayer, endGame);      
        break;
    }
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose for the score point function is to determine which type of point the player will recieve.

********************METHOD*********************
The method of the score point function is to use a switch. With the parameters of player and end game.

read in point style
**use switch**
if point style is W or w then player recieves a Waza-Ari
which then goes into next function called score waza-ari

if point style is Y or y then player recieves a Yuko
player is updated with player equal to player plus yuko weight(10)

if point style is K or k then player recieves a Koka
player is updated with player equal to player plus koka weight(1)

if point style is I or i then player recieves a ippon 
player is updated with player equal to player plus ippon weight(10000) 
and game is over

******************LIMITATIONS*******************
The limitations for the score point function is if the incorrect point style is entered it will prompt for
a correct input.
================================================================================================================
===============================================================================================================*/
void score_point (int &player, bool &endGame)
{
    char point_style;
    cin >> point_style;
    switch (point_style)
    {
    case 'W':
    case 'w':
	score_waza_ari (player, endGame);
        break;
    case 'Y':
    case 'y':
	player = player +  YUKO_WEIGHT;
        break;
    case 'K':
    case 'k':
	player = player + KOKA_WEIGHT;
        break; 
    case 'I':
    case 'i': 
	player = player +IPPOIN_WEIGHT;
	endGame = true;
        break; 
    }
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of score waza-ari function is to update the player score. Also to determine if the score for waza-ari.

********************METHOD*********************
The method for the score waza-ari function is to update player using the waza-ari weight and a if statement.
With the parameters of player and end game

player equals player plus waza-ari weight(1000)
if player is greater than or equal to 2000
end game is true which then the game ends

================================================================================================================
===============================================================================================================*/
void score_waza_ari (int &player, bool &endGame)
{
    player = player + WAZA_ARI_WEIGHT;
    if ( player >= 2000 )
    {
	endGame = true;
    }
} 

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose for the function winner determination is to determine which player has won. Also to check if
a tie has occured. 

********************METHOD*********************
The method for the winner determination function is to use if statements and a switch. With the parameters of 
blue player white player and blue wins.

if blue player is greater than white player 
blue wins equals true
else blue wins equals false

if blue player equals white player
read in tie break
**use switch**
if tiebreak is W or w then white gets the sudden death point
blue wins equals false

if tiebreak is B or b then blue gets the sudden death point 
blue wins equals true
 
================================================================================================================
===============================================================================================================*/

void winner_determination (int &blueplayer, int &whiteplayer, bool &blue_wins)
{
    char tiebreak;
    if ( blueplayer > whiteplayer )
    {
	blue_wins = true;
    }
    else 
    {  
	blue_wins = false;
    } 
    if (blueplayer == whiteplayer)
    {
	cin >> tiebreak;
	switch (tiebreak)
	{
	case 'W':
	case 'w':
	    blue_wins = false;
	    break;
	case 'B':
	case 'b':
	    blue_wins = true;
	    break;
	}
    }
}

 /*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of the score white player function is to get the score of white waza-ari, white yuko and white koka.
 
********************METHOD*********************
The method for the score white player function is to use div and mod to split up the final answer into its 
corresponding parts. Also a if statement if waza-ari is equal to two. With the parameters of white_waza_ari,
white_yuko, white_koka and white player.

white waza-ari equals white player div 1000 mod 10
if white waza-ari is equal to 2 
white waza-ari equals 1

white yuko equals white player div 10 mod 100
white koka equals white player mod 10

================================================================================================================
===============================================================================================================*/
void score_whitePlayer (int &white_Waza_Ari,int &white_Yuko,int &white_KoKa,int &whiteplayer)
{
    white_Waza_Ari = (whiteplayer/1000)%10;
    if ( white_Waza_Ari == 2 )
    {
        white_Waza_Ari = 1;
    }
    white_Yuko = (whiteplayer/10)%100;
    white_KoKa = (whiteplayer % 10);
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of the score blue player function is to get the score of blue waza-ari, blue yuko and blue koka.

********************METHOD*********************
The method for the score blue player function is to use div and mod to split up the final answer into its
corresponding parts. Also a if statement if waza-ari is equal to two. With the parameters of blue_waza_ari,
blue_yuko, blue_koka and blue player.

blue waza-ari equals blue player div 1000 mod 10
if blue waza-ari is equal to 2
blue waza-ari equals 1

blue yuko equals blue player div 10 mod 100
blue koka equals blue player mod 10

================================================================================================================
===============================================================================================================*/
void score_bluePlayer ( int &blue_Waza_Ari, int &blue_Yuko, int &blue_KoKa, int &blueplayer)
{
    blue_Waza_Ari = (blueplayer/1000)%10;
    if ( blue_Waza_Ari == 2)
    {
        blue_Waza_Ari = 1;
    }
    blue_Yuko = (blueplayer/10)%100;
    blue_KoKa = (blueplayer%10);
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of the score match function is to determine if a point is made or a time out has occured. Also calls
to previous functions to determine the score and winner. 

********************METHOD*********************
The method for score match is to use a while loop along with nested if statements. 

white not end game
read in input
if input is equal to P
call the function score turn
else if input equals to T
end game equals true

call the function for score white player
call the function for score blue player
call the function for winner determination 

******************LIMITATIONS*******************
The limitation for the score match function is if the input is a lower case p or t the function will not work 
like its supposed to. 
================================================================================================================
===============================================================================================================*/
void score_match (bool &blue_wins, int &blue_Waza_Ari, int &blue_Yuko, int &blue_KoKa, int &white_Waza_Ari, int &white_Yuko, int &white_KoKa)
{
    int whiteplayer = 0;
    int blueplayer = 0;
    char input;
    bool endGame = false;

    while (!endGame)
    {
	cin >> input;
	if (( input == 'P')||(input == 'p'))

	{
	    score_turn (whiteplayer, blueplayer, endGame);
	}
	else if ((input == 'T')||(input == 't'))
	{
	    endGame = true;
       	}
    }
    score_whitePlayer (white_Waza_Ari, white_Yuko, white_KoKa, whiteplayer);
    score_bluePlayer (blue_Waza_Ari, blue_Yuko, blue_KoKa, blueplayer);
    winner_determination (blueplayer, whiteplayer, blue_wins);
    
    return;
}

/*==============================================================================================================
================================================================================================================
********************PURPOSE********************
The purpose of the display score function is to display the score board. 

********************METHOD*********************
Use the \t to tab. 

          Waza-Ari       Yuko         Koka
Blue
White

Winner:
================================================================================================================
===============================================================================================================*/
void display_score (int blue_Waza_Ari,int blue_Yuko,int blue_KoKa,int white_Waza_Ari,int white_Yuko,int white_KoKa)
{
    cout << " \t Waza-Ari";
    cout << " \t Yuko ";
    cout << " \t Koka " << endl;
    cout << " BLUE" << "\t " << blue_Waza_Ari << " \t " << " \t " << blue_Yuko << " \t " << blue_KoKa << endl;
    cout << " WHITE "<<  "\t " << white_Waza_Ari << " \t " << " \t " << white_Yuko << " \t " << white_KoKa << endl;
    cout << " WINNER: ";
}


