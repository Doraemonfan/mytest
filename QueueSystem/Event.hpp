//
// Event.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

class Event {
public:
	Event(int occur_time, int window_id):
		_occur_time(occur_time),
		_window_id(window_id),
		_next(nullptr)
	{ }

	void show() {
		std::cout << "occur_time: " << _occur_time
			<< "  _window_id: " << _window_id 
			<< std::endl;
	}
//private:
	int _occur_time;
	int _window_id;
	Event *_next;
};


#endif
