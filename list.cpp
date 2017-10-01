#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "chain.h"


using namespace std;


List::List() {
	size = 0;
	first = NULL;
	cout << "List constructed" << endl;
}


List::~List(){
	int i;
	for (i = 1 ; i <= size; i++) deletePlayer(1);
	cout << "List destructed" <<endl;
}


/* Insert a new player in the end of the list */
void List::insertPlayer (Player& p) {
	int i;
	Node *new_node, *last ;
	new_node = new Node;
    /* If list is empty, the new node is the first node of the list */
	if (size == 0) {
		first = new_node;
		new_node->player = p;  // bitwise assignment
		new_node->next = first;
	}
    /* Else, I insert the new node after the last node */
    else {		
        last = first;		
    	for (i=1 ; i<size ; i++) last = last->next ;
    	last->next = new_node;
    	new_node->player = p;  // bitwise assignment
    	new_node->next = first; // cyclic list
    }
	size ++;		
}


/* Deletes the player in the position pos */
void List::deletePlayer (int pos) {
    int i;
    Node *prev, *todel;
    if (pos<1 || pos>size) {
        cout << "Invalid position " << pos << endl;
    }
    else {
        if (size == 1) {
            delete first;
            first = NULL;
        }
        else {
            todel = first;
            for (i=0; i<pos-1; i++) todel = todel->next;
            prev = first;
            while (prev->next != todel) prev = prev->next;
    	    prev->next = todel->next;
            if (todel == first) first = todel->next ;
    	    cout << "Remove player with ID " << todel->player.ID << endl << endl;
            delete todel;
        }        
        size--;        
    }
}


/* Returns the first node of the list */
Node* List::get_first(){
	return first;
}


/* Update the first of the list */
void List::set_first(Node *k) {
	first = k;
}

/* Returns the size of the list */
int List::get_size(){
	return size;
}
