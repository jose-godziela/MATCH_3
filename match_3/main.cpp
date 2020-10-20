#include "Mainframe.h"
using namespace M3;


int main() {
	Mainframe* Match3 = new Mainframe;
	Match3->init();
	Match3->mainLoop();

	delete Match3;

#if DEBUG
	fflush(stdin);
	cout << "game ended" << endl;
	cin.get();
#endif
	return 0;
}