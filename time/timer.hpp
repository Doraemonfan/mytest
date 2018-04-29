//
// timer.hpp
//
// 2018/4/29 others "kedixa"
//

#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <chrono>
#include <string>

namespace kedixa {

class timer {

	using tp = std::chrono::steady_clock::time_point;
	using dd = std::chrono::duration<double>;
	using sc = std::chrono::steady_clock;

private:
	tp _begin;
	dd _span;
public:
	timer(): _begin(tp()), _span(dd(0)) { }

	void start() { _begin = sc::now(); }
	void pause() { 
		tp _end = sc::now();
		_span += std::chrono::
			duration_cast<dd>(_end - _begin);
	}
	void stop(std::string head = std::string(),
			std::string tail = std::string() ) {
		pause();
		std::cout << head << _span.count() 
			<< " seconds" << tail << std::endl;
		_span = dd(0);
	}
	~timer() { }

};  // class timer


}; // namespace kedixa

#endif // timer.hpp
