#include <iostream>
#include "zTimer.hpp"
#include "timer.hpp"

using namespace std;

int main() {
	using kedixa::timer;
	
	timer t;
	t.start();

	zTime zt;
	zt.start();
	zt.show();

	for (int i = 0; i < 1000000000; ++i)  ;

	t.pause();
	zt.pause();
	zt.show("pause ", ".");

	t.start();
	zt.goOn();	
	for (int i = 0; i < 1000000000; ++i) ;

	zt.end();
	zt.show("end ", "?");

	t.stop("end ", "!");

	return 0;
}
