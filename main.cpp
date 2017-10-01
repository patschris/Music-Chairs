#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "chain.h"

using namespace std;


int main (void) {
	int i, j, N, hits, pos;
	cout << endl << "Give number of players: " << endl;
	cin >> N;
	Chain chain(N);
	srand(time (NULL));
	cout << endl << "Playing music chairs with " << N << " players" << endl;
	cout << "Printing initial chain" << endl;
	chain.print_chain();
	for (i=1; i<N; i++) {
		hits = rand() % 10 + 1;
		cout << endl << endl << "Music chairs round " << i << endl;
		cout << "Hits: " << hits << endl;
		for (j=0; j<hits; j++) chain.hit();
		pos = chain.stop_tune();
		chain.resume (pos);
		cout << "Chain after removal:" << endl; 
		chain.print_chain();
	}
	chain.winner();
	return 0 ;
}
