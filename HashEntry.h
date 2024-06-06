/*
	Title:  HashEntry.h
	Author:	April Crockett, made template by Cole Howell
	Purpose:  	Hash Table Implementation
				Values					-	whatever datatype is passed for the template
				Hash Function			-	modulus operator
				Collision resolution	-	Dynamic
				
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
using namespace std;

template <typename var> //mainly for the value section of each hash entry, is whatever variable type needed
class HashEntry
{
	private:
		int key;
		var value;
		HashEntry* next;
		
	public:
		HashEntry(int k, var v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		int getKey()
		{
			return key;
		}
		var getValue()
		{
			return value;
		}
		HashEntry* getNext()
		{
			return next;
		}
		void setNext(HashEntry *next)
		{
			this->next = next;
		}
		void setValue(var v)
		{
			value = v;
		}
};

#endif