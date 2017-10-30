//Name: Ashley Smith
//Date: April 23, 2017
//Description: Space class function definitions for project 8

#include "colors.h"
#include "space.h"
#include <iostream>

namespace main_savitch_14 
{

void space::output() const
{
	if(is_empty())
	{
		cout << "   ";
	}
	
	else if(is_yellow() && is_king())
	{
		cout << YELLOW << "*o*";
	}
	
	else if(is_yellow() && !is_king())
	{
		cout << YELLOW << " o ";
	}
	
	else if(!is_yellow() && is_king())
	{
		cout << BLACK << "*o*";
	}
	
	else if(!is_yellow() && !is_king())
	{
		cout << BLACK << " o ";
	}
}

void space::operator = (const space& mine) 
{
	yellow = mine.yellow;
	empty = mine.empty;
	king = mine.king; 
}

}
