#ifndef __chain__
#define __chain__

#include "list.h"
 

class Chain {
	private:
		List list;
	public:
		Chain(int N);
		~Chain();
		void hit() ;			
		int stop_tune();	
		void resume(int);
		void print_chain();		
		bool game_over();
		void winner();
};

#endif
