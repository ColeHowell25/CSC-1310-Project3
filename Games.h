/*
	Title: Games.h
	Author: Cole Howell
	Purpose: Class implementation for Games
*/

#ifndef GAMES_H
#define GAMES_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Games{
	
	private:
		int idNum;
		string title;
		int rating;
		
	public:
		//constructor
		Games(int, string, int);
		
		//destructor
		~Games();
			
			
		//accessors	
		int getIdNum();
		string getTitle();
		int getRating();
		
		//mutators
		void setIdNum(int);
		void setTitle(string);
		void setRating(int);
		
		/*
			Overloaded << operator, when using cout, will print out all attributes to the game
		*/
		friend ostream &operator << (ostream &strm, Games &g)
		{
			strm << setw(8) << "IDNUM:  " << g.idNum << ", ";
			strm << setw(8) << "TITLE:  " << g.title << "," << setw(8);
			strm << setw(10) << "RATING:  " << g.rating;
		
			return strm;
		}	
};

#endif