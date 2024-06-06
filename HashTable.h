/*
	Title:  HashTable.h
	Author:	April Crockett, made template by Cole Howell
	Purpose:  	Hash Table Implementation
				Values					-	Whatever is entered into the template variable
				Hash Function			-	modulus operator
				Collision resolution	-	Dynamic
				
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

template <typename var> 
class HashTable
{
	private:
		int tableSize;
		HashEntry<var>** hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry<var>*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<var> *prevEntry = NULL;
					HashEntry<var> *entry = hashArray[i];
					while(entry != NULL)
					{
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}
		
		var getValue(int key)
		{
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL)
			{
				return NULL;
			}
			else
			{
				HashEntry<var> *entry = hashArray[bucketIndex];
				while(entry != NULL && entry->getKey() != key)
					entry = entry->getNext();
				if(entry == NULL)
					return NULL;
				else
					return entry->getValue();
			}
		}
		
		void putValue(int key, var value)
		{
			int bucketIndex = key % tableSize;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = new HashEntry<var>(key, value);
			}
			else //collision
			{
				HashEntry<var>* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry<var>(key, value));
			}
		}
		
		void removeValue(int key)
		{
			HashEntry<var> *entry;
			HashEntry<var> *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL)
			{
				//traverse through list and find matched key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL & entry->getKey() != key)
				{
					prevEntry = entry;
					entry = entry->getNext();
				}
				if(entry->getKey() == key) //found the key in previous while loop
				{
					if(prevEntry == NULL)
					{
						HashEntry<var> *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}
					else
					{
						HashEntry<var> *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
					}
				}
			}		
		}
		
		void printHashTable()
		{
			cout << "----------";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<var>* entry = hashArray[i];
					while(entry->getNext() != NULL)
					{
						cout << "---->" << *(entry->getValue());
						entry = entry->getNext();
					}
					cout << "\n";
					cout << "BUCKET " << i << "---->" << *(entry->getValue());
					
				}
				else{
					cout << "\n";
					cout << "BUCKET" << i << "---->" << -1;
				}
			}
			cout << "\n----------\n\n";
		}
		
};


#endif