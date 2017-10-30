//Name: Ashley Smith
//Date: April 23, 2017
//Description: Space class for project 8

#include <iostream>
#ifndef SPACE_H
#define SPACE_H

namespace main_savitch_14 
{

class space 
{
	public:
		space()
		{
			empty = true;
			king = false; 
			yellow = false;
		}
		
		void output() const;
		
		void operator=(const space& space1);
		
		void set_empty(bool a)
		{
			empty = a;
		}

		void set_yellow(bool a) 
		{
			yellow = a;
		}

		void set_king(bool a) 
		{
			king = a;
		}

		bool is_yellow() const 
		{
			return yellow;
		}
		
		bool is_king() const 
		{
			return king;
		}
		
		bool is_empty() const 
		{
			return empty;
		}
	
	private:
		bool king;
		bool yellow;
		bool empty;
		
};

}
#endif
