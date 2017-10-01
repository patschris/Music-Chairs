#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "chain.h"


using namespace std;


/* Construct a chain with N players with random IDs*/
Chain::Chain(int N):list() {  
	int i, id, counter, arrayID[N];
	Player newPlayer;
	for (i=0; i<N; i++) arrayID[i] = 0 ; // initialization
	for (i = 0; i < N ; i++) {
		id = rand() % N + 100;	// give random ids
		counter = 0;	
        /* Give random ids until I find one that it's not used yet*/
		while(counter < i){
			if (id == arrayID[counter]) {
				id = rand() % N + 100;
				counter = 0;
			}
            else {
			    counter++;
            }
		}
        /* Create and insert a new player */
		arrayID[i] = id;
		newPlayer.ID = id;
		newPlayer.position = i+1;
		list.insertPlayer(newPlayer);    
	}	 
	cout << "Chain with " << N << " players has just constructed" << endl;
}


Chain::~Chain() {	
	cout << "Chain desructed " << endl;
}


/* Moves every player one position left and updates the list */
void Chain::hit() {
	int i;
	Node *first = list.get_first();
	Node *temp = first;
	int size = list.get_size();	
	for (i=0; i<size; i++) {
		temp->player.position--;  
		if (i == 0)	{ // The previous first goes to the last position
            temp->player.position = size; 
        }
		else if (i == 1) {	// The previous second is the new first 
			first = temp;
			list.set_first(first);
		}	
		temp = temp -> next ;
	}		 	
}


/* Music stops, one player loses */
int Chain::stop_tune() {
	int pos = rand() % list.get_size() + 1; // delete a player randomly
	list.deletePlayer(pos);
	return pos;
}


/* Fixes the chain after the removal of a player in stop_tune */
void Chain::resume (int pos) {
	int i;
	Node *first = list.get_first();
    Node *temp = first;
	int size = list.get_size();
	if (pos != size + 1) {
        /* Find the last player with correct position number */
	    for (i=1; i<pos; i++) temp = temp->next;
        /* Everyone after temp has incorrect position number*/
	    for (i=pos; i <= size; i++) {
		    temp -> player.position--;
		    temp = temp->next;
	    }
    }
}


/* Prints the chain that contains the remaining players */
void Chain::print_chain() {
	int i;
	Node *temp = list.get_first();
	for (i = 1 ; i <= list.get_size() ; i++){
		cout << "Player in position " << i << " has ID " << temp->player.ID  << endl ;
		temp = temp -> next;
	}
}


/* If there is only one player in the list, the game is over */
bool Chain::game_over() {
	if (list.get_size() == 1) return true; 
	else return false ;
}


/* if the game is over, we have a winner */
void Chain::winner() {
	if (game_over() == true) cout << "Nikitis einai o paiktis me ID " << list.get_first()->player.ID << endl << endl;
}
