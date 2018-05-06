//
// zTimer.hpp 
// 2018/4/29
//
#ifndef __ZTIMER_HPP__
#define __ZTIMER_HPP__

#include <string>
#include <cstdio>
#include <iostream>

namespace zLimbo {

class zTimer {
	
private:
	enum { SECOND_NUM = 1000000 };
	enum STATUS { RUN, PAUSE, HALT };
	long _now;
	long _span;
	STATUS _status;

public:
	zTimer(): _now(0), _span(0), _status(HALT) { }
	void start() { 
		_now = clock(); 
		_span = 0; 
		_status = RUN;
	}
	void pause() {
		if (_status == RUN) {
			_span += clock() - _now;
			_status = PAUSE;
		}
	}
	void goOn() {
		if (_status == PAUSE) {
			_now = clock();
			_status = RUN;
		}
	}
	void end() {
		pause();
		_status = HALT;
	}
	void show(const std::string head = std::string(),
		const std::string tail = std::string() ) const 
	{
		if (_status != RUN) {
			std::cout << head  
				<< static_cast<double>(_span) 
					/ SECOND_NUM
				<< " seconds" << tail << std::endl;
		}
		else {
			std::cout << "Time is running!"
				<< std::endl;
		}
	}	
}; // class zTimer

}; // namespace zLimbo

#endif // zTime.hpp

