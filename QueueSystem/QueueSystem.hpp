//
// QueueSystem.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __QUEUESYSTEM_HPP__
#define __QUEUESYSTEM_HPP__

#include "Queue.hpp"
#include "Customer.hpp"
#include "Event.hpp"
#include "Random.hpp"
#include "ServerWindow.hpp"

class QueueSystem {

public:
	QueueSystem(int total_service_time,
			int window_num);
	~QueueSystem();

	void simulate(int simulate_num);
	double getAvgStayTime() {
		return _avg_stay_time;
	}
	double getAvgCustomers() {
		return _avg_customers;
	}

private:
	void run();
	void init();
	void end();
	void arrive_customer();
	void depart_customer();

	ServerWindow* _windows;

	Queue<Customer> _customers;
	Queue<Event> _events;

	Customer *_current_customer;
	Customer *_current_event;
	int _total_service_time;
	int _window_num;

	double _avg_stay_time;
	double _avg_customers;
};

QueueSystem::QueueSystem(int total_service_time,
		int window_num):
	_total_service_time(total_service_time),
	_window_num(window_num)
{ 
	_windows = new ServerWindow[_window_num];
}

QueueSystem::~QueueSystem() {
	delete[] _windows;
}

void QueueSystem::simulate(int simulate_num) {
	int sum;
	for (int i = 0; i < simulate_num; ++i)	
		sum += run();
	_avg_stay_time = 
		static_cast<double>(_total_service_time)
			/ sum * simulate_num;
	_avg_customers = 
		static_cast<double>(sum) / simulate_num
			/ _total_service_time;
}

void QueueSystem::run() {
	init();
	while (!_events.empty()) {	
		current_event = _events.dequeue();
		if (event._window_id < 0) 
			arrive_customer();
		else 
			depart_customer();
	}
	end();
}

void QueueSystem::arrive_customer() {
	int window = getIdleWindow();
	int interval = Random::uniform();
	Customer new_customer(
		current_customer->_occur_time + interval);
	if (new_customer->_occur_time
void QueueSystem::init() {
	_current_customer = new Customer(0);
	if (!_current_customer) exit(-1);
	_customes.enqueue(_current_customer);
	Event events_start(
		_current_customer->_arrive_vime, -1);
}
 
void QueueSystem::end() {
	_customers.clear();
	_events.clear();
}


#endif
