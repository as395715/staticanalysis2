//Name: Ashley Smith
//Date: April 23, 2017
//Description: Checkers class for project 8

#include <iostream> 
#include "game.h"
#include "space.h"
#include "colors.h"

using namespace std;

#ifndef CHECKERS_H
#define CHECKERS_H

namespace main_savitch_14
{
	class checkers:public game
	{
		public: 
			checkers();
			void restart();
			void display_status() const; 
			bool is_legal(const string& move) const;
			void make_move(const string& move);  
			bool is_game_over() const;
			int evaluate() const;
			void compute_moves(queue<string>& moves) const;
			game* clone()const;
			game::who winning() const;
			
		private: 
			space board[8][8];
			int ynum;
			int bnum;
	}; 
}
#endif
