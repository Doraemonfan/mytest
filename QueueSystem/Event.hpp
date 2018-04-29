//
// Event.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "Random.hpp"


class Event {
public:
	static int RANDOM_PARAMETER;
	Event(int occur_time = 
			Random::uniform(RANDOM_PARAMETER),
			int event_type = -1):
		_occur_time(occur_time),
		_event_type(event_type),
		_next(nullptr)
	{ }

//	void show() {
//		std::cout << "occur_time: " << _occur_time
//			<< "  event_type " << _event_type 
//			<< std::endl;
//	}
//private:
	int _occur_time;
	int _event_type;
	Event *_next;
};

int Event::RANDOM_PARAMETER = 100;
#endif
