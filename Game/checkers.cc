//Name: Ashley Smith
//Date: April 23, 2017
//Description: Checkers class function definitions for project 8

#include <string>
#include "checkers.h"
#include "game.h"
using namespace std;
namespace main_savitch_14
{

//Restart function
void checkers::restart()
{
	checkers();
}

//Default constuctor that sets up the game
checkers::checkers()
{
	int x;
	int y;
	ynum = 12;
	bnum = 12;
	
	for(x = 0; x < 8; x++)
	{
		for(y = 0; y < 8; y++)
		{
			board[y][x].set_empty(true);
			board[y][x].set_yellow(false);
			board[y][x].set_king(false);
		}
	}
	
	for(x = 0; x < 3; x++) 
	{
		if(x == 0 || x == 2)
		{
			for(y = 1; y < 8; y = y+2) 
			{
				board[y][x].set_empty(false);
				board[y][x].set_yellow(false);
				board[y][x].set_king(false);
			}
		}
		
		else if (x == 1)
		{
			for(y = 0; y < 8; y = y+2) 
			{
				board[y][x].set_empty(false);
				board[y][x].set_yellow(false);
				board[y][x].set_king(false);
			}
		}
	}
	
	for(x = 7; x >= 5; x--) 
	{
		if(x == 7 || x == 5) 
		{
			for(y = 0; y < 8; y = y+2)
			{
                                board[y][x].set_empty(false);
                                board[y][x].set_yellow(true);
                                board[y][x].set_king(false);
			}
		}
		
		else if (x == 6) 
		{
			for(y = 1; y < 8; y = y+2) 
			{
                                board[y][x].set_empty(false);
                                board[y][x].set_yellow(true);
                                board[y][x].set_king(false);
			}
		}
	}
}

//Evaluates the number of pieces each player has
int checkers::evaluate() const
{
	return bnum - ynum;
}

//Clones the game
game* checkers::clone()const
{
	return new checkers(*this);
}

//Determines who is winning the game
game::who checkers::winning() const 
{
	if(ynum > bnum)
	{
		return HUMAN;
	}
	
	else if(bnum > ynum)
	{
		return COMPUTER;
	}
	
	else
	{
		return NEUTRAL;
	}
}


//Displays the board
void checkers::display_status() const
{
     	int x;
     	int y;
	char letter = 'A';
	
	cout << "  ";
	
	for(x = 1; x <= 8; x++) 
	{
		cout << " " << letter << " ";
		letter ++;
	}
	
	cout << endl;

        for(x = 0; x < 8; x++)
        {
		cout << RESET << x+1 << " ";

                if(x % 2 == 0)
                {
                    for(y = 0; y < 8; y++)
                    {
                        if(y % 2 == 0)
                        {  
                        	cout << B_BLACK;
				board[y][x].output();
                        } 
                        
                        else 
                        { 
                        	cout << B_CYAN;
				board[y][x].output();
                        }
                    }
                    cout << RESET << endl;
                }

                else 
                { 
                    for(y = 0; y < 8; y++) 
                    {
                       if(y % 2 == 0) 
                       { 
                          	cout << B_CYAN;
				board[y][x].output();
                       } 
                       
                       else 
                       { 
				cout << B_BLACK;
				board[y][x].output();
                       }
                    }
                    cout << RESET << endl;
                }
        }
}

//Moves the pieces
void checkers::make_move(const string& move)
{
	int first1,second1;
	int first2,second2;
	char x;
	space tmp;

	x = move[0];
	first1 = x - '0';
	first1 -= 48;

	x = move[1];
	second1 = x - '0';

	x = move[2];
	first2 = x - '0';
	first2 -= 48;

	x = move[3];
	second2 = x - '0';

 	tmp = board[first2-1][second2-1];
	board[first2-1][second2-1] = board[first1-1][second1-1];
	board[first1-1][second1-1] = tmp;
	
	if(second2 == 1 || second2 == 8)
	{
		board[first2-1][second2-1].set_king(true);
	}
	
	if(second2 == second1 - 2)
	{
		if(first2 == first1 + 2)
		{
			if(board[first1][second1-2].is_yellow())
			{
				ynum--;
			}
			
			else
			{
				bnum--;
			}
			
			board[first1][second1-2].set_empty(true);
		}
		
		else if(first2 == first1 - 2) 
		{
			if(board[first1-2][second1-2].is_yellow())
			{
				ynum--;
			}
			
			else
			{
				bnum--;
			}
			
			board[first1-2][second1-2].set_empty(true);
		}
	}
	
	else if(second2 == second1 + 2)
	{
		if(first2 == first1 + 2)
		{
			if(board[first1][second1].is_yellow())
			{
				ynum--;
			}
			
			else
			{
				bnum--;
			}
			
			board[first1][second1].set_empty(true);
		}
		
		else if(first2 == first1 - 2) 
		{
			if(board[first1-2][second1].is_yellow())
			{
				ynum--;
			}
			else
			{
				bnum--;
			}
			
			board[first1-2][second1].set_empty(true);
		}
	}
	
	game::make_move(move);
}


//Checks to see if the move is a legal one or not
bool checkers::is_legal(const string& move) const
{
	char x;
	int first1, second1, first2, second2;
	x = move[0];
	first1 = x - '0';
	first1 -= 48;

	x = move[1];
	second1 = x - '0';

	x = move[2];
	first2 = x - '0';
	first2 -= 48;

	x = move[3];
	second2 = x - '0';

	if(board[first1-1][second1-1].is_empty())
	{
		return false;
	}
	
	if(!(board[first2-1][second2-1].is_empty()))
	{
        	return false;
	}
	
	if(!board[first1-1][second1-1].is_king()) 
	{
		if(next_mover() == HUMAN)
		{
			if(board[first1-1][second1-1].is_yellow())
			{
				if(second2 == second1-1)
				{
					if(first2 == first1-1 || first2 == first1+1)
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
				
				else if(second2 == second1 - 2) 
				{
					if(first2 == first1 - 2) 
					{
						if(!board[first1-2][second1-2].is_empty()) 
						{
							if(!board[first1-2][second1-2].is_yellow())
							{
								return true;
							}
							
							else
							{
								return false;
							}
						}
						
						else
						{
							return false;
						}
					}

					else if(first2 = first1 + 2) 
					{
						if(!board[first1][second1-2].is_empty()) 
						{
							if(!board[first1][second1-2].is_yellow())
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						
						else
						{
							return false;
						}
					}
					
					else
					{
						return false;
					}
				}
				
				else
				{
					return false;
				}
			}
			
			else
			{
				return false;
			}
		}

		else if(next_mover() == COMPUTER) 
		{
			if(!board[first1-1][second1-1].is_yellow())
			{
				if(second1 == second2 -1) 
				{
					if(first2 == first1-1 || first2 == first1+1)
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
			
				else if(second2 == second1 + 2)
				{
					if(first2 == first1 + 2) 
					{
						if(!board[first1][second1].is_empty()) 
						{
							if(board[first1][second1].is_yellow())
							{
								return true;
							}
							
							else
							{
								return false;
							}
						}
						
						else
						{
							return false;
						}
					}
					
					else if(first2 == first1 - 2)
					{
						if(!board[first1-2][second1].is_empty())
						{
							if(board[first1-2][second1].is_yellow())
							{
								return true;
							}
							
							else
							{
								return false;
							}
						}
						
						else
						{
							return false;
						}
					}
					
					else
					{
						return false;
					}
				}
				
				else
				{
					return false;
				}
			}
			
			else
			{
				return false;
			}
		}
	}

	else 
	{
		if(next_mover() == HUMAN && !board[first1-1][second1-1].is_yellow())
		{
			return false;
		}
		
		if(next_mover() == COMPUTER  && board[first1-1][second1-1].is_yellow())
		{
			return false;
		}
		
		if(second1 == second2 - 1 || second1 == second2+1) 
		{
			if(first2 == first1 -1 || first2 == first1+1)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		else if(second2 == second1 + 2) 
		{
			if(first2 == first1 + 2)
			{
				if(!board[first1][second1].is_empty()) 
				{
					if(board[first1-1][second1-1].is_yellow() != board[first1][second1].is_yellow())
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
				
				else
				{
					return false;
				}
			}
			
			else if(first2 = first1 - 2)
			{
				if(!board[first1-2][second1].is_empty()) 
				{
					if(board[first1-1][second1-1].is_yellow() != board[first1-2][second1].is_yellow())
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
				
				else
				{
					return false;
				}
			}
			
			else
			{
				return false;
			}
		} 
		
		else if (second2 == second1 - 2)
		 {
			if(first2 == first1 + 2)
			{
				if(!board[first1][second1-2].is_empty()) 
				{
					if(board[first1-1][second1-1].is_yellow() != board[first1][second1-2].is_yellow())
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
				
				else
				{
					return false;
				}
			}
			
			else if(first2 == first1 -2) 
			{
				if(!board[first1-2][second1-2].is_empty())
				 {
					if(board[first1-1][second1-1].is_yellow() != board[first1-2][second1-2].is_yellow())
					{
						return true;
					}
					
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
}

//Checks to see if the game is over, and announces the winner
bool checkers::is_game_over() const
{
	if(ynum == 0) 
	{
		cout << "Black wins!\n";
		return true;
	}
	
	else if(bnum == 0) 
	{
		cout << "Yellow wins!\n";
		return true;
	}
	 
	else
	{
		return false;
	}
}


//Computes the moves for the players			
void checkers::compute_moves(queue<string>& moves)const
{
	string ok = "    ";
	char x;
	char y;
	char z;
	char a;
	
        for(x = '1'; x < '9'; x++)
        {
                for(y = 'a'; y < 'i'; y++)
                {
                        for(a = '1'; a < '9'; a++)
                        {
                                for(z = 'a'; z < 'i'; z++)
                                {
                                        ok[0] = y;
                                        ok[1] = x;
                                        ok[2] = z;
                                        ok[3] = a;
                                        
                                        if(is_legal(ok))
                                        {
						moves.push(ok);
                                        }
                                }
                        }
                }
        }
}
}
