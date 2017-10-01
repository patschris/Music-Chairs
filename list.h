#ifndef __list__
#define __list__


/* Player's attributes */
struct Player {
	int ID;
	int position;
};


/* List's node. Contains a player and points to the next node */
struct Node {
	Node *next;
	Player player;
};
 
/* List of players */
class List {
	private:
		int size;
		Node *first;
	public:
		List();
		~List();
		void set_first(Node*);
		int get_size();
		Node* get_first();
		void insertPlayer(Player&);
		void deletePlayer(int);
};

#endif
