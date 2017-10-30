//Name: Ashley Smith
//Date: April 23, 2017
//Description: Main class for project 8

#include <iostream> 
#include "colors.h"
#include "checkers.h"
#include "space.h"
#include "game.h"

using namespace std;
using namespace main_savitch_14;

int main()
{
	game * mine;
	mine = new checkers;
	 
	mine -> play();
	return 0; 
}

