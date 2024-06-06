
/*
	Title: Games.cpp
	Author: Cole Howell
	Purpose: Function implementations for the game class
*/



#include "Games.h"

//constructor
Games::Games(int id, string t, int rate){
	this->idNum = id;
	this->title = t;
	this->rating = rate;
}
//destructor implementation
Games::~Games(){}
//accessors	
int Games::getIdNum(){
	return this->idNum;
}
string Games::getTitle(){
	return this->title;
}
int Games::getRating(){
	return this->rating;
}

//mutators
void Games::setIdNum(int k){
	this->idNum = k;
}
void Games::setTitle(string k){
	this->title = k;
}
void Games::setRating(int k){
	this->rating = k;
}