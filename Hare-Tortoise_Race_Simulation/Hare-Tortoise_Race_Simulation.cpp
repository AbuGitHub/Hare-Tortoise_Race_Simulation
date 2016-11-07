/*  Abuzar Noorali
Purpose/Description: This program simulates a race between a rabbit and a tortoise
*/

#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

default_random_engine engine(static_cast <unsigned int> (time(0)));
uniform_int_distribution<unsigned int> randomInt(1, 10);

//Determine how much the tortoise will move on this tick
int moveTortoise(int tortoise_position)
{
	int tortoise_position_change = 0;							//To hold the amount of change this turn
	int adjusted_tortoise_position = tortoise_position;			//Bring in previous position, and hold in this variable for editing
	unsigned int move_generate = (randomInt(engine));			//Genereate a random number between 1-10

																//Fast Plod
	if (move_generate <= 5)
	{
		tortoise_position_change = tortoise_position_change + 3;
	}

	//Slip
	else if (move_generate > 5 && move_generate <= 7)
	{
		tortoise_position_change = tortoise_position_change - 6;
	}

	//Slow Plod
	else if (move_generate > 7 && move_generate <= 10)
	{
		tortoise_position_change = tortoise_position_change + 1;
	}


	adjusted_tortoise_position = adjusted_tortoise_position + tortoise_position_change;		//Add the changes to the previous position

	if (adjusted_tortoise_position < 1)
	{
		adjusted_tortoise_position = 1;														//If position goes under 1, reassign position to 1
	}

	cout << "Tortoise distance: " << adjusted_tortoise_position << "\n";					//Display the position after change
	return adjusted_tortoise_position;
}

//Determine how much the hare will move this tick
int moveHare(int hare_position)
{
	int hare_position_change = 0;									//To hold the amount of change this turn
	int adjusted_hare_position = hare_position;						//Bring in previous position, and hold in this variable for editing
	unsigned int move_generate = (randomInt(engine));				//Genereate a random number between 1-10

																	//Sleep
	if (move_generate <= 2)
	{
		hare_position_change = hare_position_change + 0;
	}

	//Big hop
	else if (move_generate > 2 && move_generate <= 4)
	{
		hare_position_change = hare_position_change + 9;
	}

	//Big slip
	else if (move_generate > 4 && move_generate <= 5)
	{
		hare_position_change = hare_position_change - 12;
	}

	//Small hop
	else if (move_generate > 5 && move_generate <= 8)
	{
		hare_position_change = hare_position_change + 1;
	}

	//Small slip
	else if (move_generate > 8 && move_generate <= 10)
	{
		hare_position_change = hare_position_change - 2;
	}

	adjusted_hare_position = adjusted_hare_position + hare_position_change;			//Add the changes to the previous position

	if (adjusted_hare_position < 1)													//If position goes under 1, reassign position to 1
	{
		adjusted_hare_position = 1;
	}
	cout << "Hare distance: " << adjusted_hare_position << "\n";					//Display the position after change

	return adjusted_hare_position;
}


int main()
{
	const int endRace = 70;															//The race ends when either animal reaches 70
	int hare_position = 1;															//Hold the hare's position
	int tortoise_position = 1;														//Hold the tortoise's position
	string raceTrack[70];															//Array to hold the entire track display
	bool isRaceOver = false;														//Variable to limit completing the loop if an animal finishes the race

	cout << "BANG !!! \nAND THEY'RE OFF!\n\n\n";									//Display start of race

																					//Loop through the randomly generated moves until one animal finishes the race
	while (endRace > hare_position && endRace > tortoise_position)
	{

		//Call both movement generating methods, and assign new positions
		tortoise_position = moveTortoise(tortoise_position);
		hare_position = moveHare(hare_position);

		//End loop and display if both animals finish at the same time
		if (hare_position >= endRace && tortoise_position >= endRace)
		{
			cout << "\n\nIT'S A TIE! \n";
			isRaceOver = true;
		}

		//End loop if hare finishes first 
		else if (hare_position >= endRace)
		{
			cout << "\n\nHARE WINS. Yuch.\n";
			isRaceOver = true;
		}

		//End loop if tortoise finishes first
		else if (tortoise_position >= endRace)
		{
			cout << "\n\nTORTOISE WINS! YAY! \n";
			isRaceOver = true;
		}


		//If the race isn't finished, display the track, and OUCH (if applicable), and the positions of the animals on the track
		if (isRaceOver == false)
		{
			//Reset the racetrack
			for (int i = 0; i < 70; i++)
			{
				raceTrack[i] = ".";
			}

			//Display a T for the tortoise's position on the track
			if (tortoise_position <= 70)
				raceTrack[tortoise_position] = "T";

			//Display an H for the hare's position on the track
			if (hare_position <= 70)
				raceTrack[hare_position] = "H";

			//If both the hare and tortoise have the same position, display OUCH for that position
			for (int a = 0; a < 70; a++)
			{
				if (hare_position == tortoise_position)
				{
					raceTrack[hare_position] = "OUCH";			//Tortoise bites the hare
				}

				//Display the track with the new positions
				cout << raceTrack[a];
			}


			cout << "\n";

		}
	}

	cout << endl;
	return 0;
}