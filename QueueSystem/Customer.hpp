//
// Customer.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__

#include "Random.hpp"

class Customer {

public:
	Customer(int arrive_time,
			int duration = Random::uniform()):
		_arrive_time(arrive_time),
		_duration(duration),
		_next(nullptr)
	{ }

	void show() {
		std::cout << "arrive_time: " << _arrive_time 
			<< " duration: " << _duration
			<< std::endl;
	}
//public:
	int _arrive_time;
	int _duration;
	Customer *_next;
};

#endif
