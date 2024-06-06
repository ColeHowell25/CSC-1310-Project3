/*
	Title: Main.cpp
	Author: Cole Howell
	Purpose: Driver function to demonstrate use of a hash table
*/


#include "Games.h"
#include "HashTable.h"
#include <fstream>


using namespace std;

//function prototypes
void enterFile(HashTable<Games*>*);
void manualEntry(HashTable<Games*>*);
bool searchTable(HashTable<Games*>*, int);
void deleteValue(HashTable<Games*>*);

int main(){
	HashTable<Games*>* myTable = new HashTable<Games*>(10);
	
	cout << "Please choose from the options below by entering the number next to the option (1-6)\n\n";
	int choice;
	
	do{
		cout << "\n";
		cout << "1. Enter data from file into hash table.\n";
		cout << "2. Enter data manually.\n";
		cout << "3. Search Hash Table for value.\n";
		cout << "4. Delete value from hash table.\n";
		cout << "5. Print the hash table.\n";
		cout << "6. Exit Program\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "\n";
		
		while(choice < 1 || choice > 6){
			cout << "Invalid input. Enter a value between 1 and 6";
			cin >> choice;
		}
		
		switch(choice){
			case 1: enterFile(myTable);
					break;
			case 2: manualEntry(myTable);
					break;
			case 3:	
			{
				int id;
				cout << "Enter the idNum of the game you wish to search for: ";
				cin >> id;
				
				if (searchTable(myTable, id)){
					cout << "The game is already in the table.\n";
				}
				else{
					cout << "The game is not in the table.\n";
				}
				break;
			}
			case 4: deleteValue(myTable);
					break;
			case 5: myTable->printHashTable();
					break;
			case 6: cout << "Exiting Program.";
					break;
		}
	}
	while (choice != 6);
	delete myTable;
	
	return 0;
}

void enterFile(HashTable<Games*>* g){
	
	ifstream inFile;
	inFile.open("dataFile.txt");
	if (inFile){
		int id; //id number
		string t; //title
		int rate; //rating
		
		while(inFile >> id){
		
			inFile.ignore();
			getline(inFile, t);
			inFile >> rate;
			cout << "The Game " << t << " has been added to the hash table with ID number " << id << ".\n";
			Games* game = new Games(id, t, rate);
			g->putValue(id, game);
		}
	}
	inFile.close();
}

void manualEntry(HashTable<Games*>* g){
	int id;
	string t;
	int rate;
	
	cout << "Enter the information for the game you wish to add to the hash table.\n";
	cout << "ID Number: ";
	cin >> id;
	cout << "Title: ";
	cin.ignore();
	getline(cin, t);
	cout << "Rating (1-10): ";
	cin >> rate;
	
	Games* game = new Games(id, t, rate);
	g->putValue(id, game);
}

bool searchTable(HashTable<Games*>* g, int key){
	if (!g->getValue(key)){
		return false;
	}
	else
		return true;
}

void deleteValue(HashTable<Games*>* g){
	int key;
	cout << "Enter the key of the object you wish to delete: ";
	cin >> key;
	g->removeValue(key);
}