//
// QueueSystem.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __QUEUESYSTEM_HPP__
#define __QUEUESYSTEM_HPP__

#include "Queue.hpp"
#include "Event.hpp"
#include "ServerWindow.hpp"

class QueueSystem {

public:
	QueueSystem(int total_service_time,
			int window_num);
	~QueueSystem();

	void simulate(int simulate_num);
	double getAvgStayTime() const {
		return _avg_stay_time;
	}
	double getAvgCustomers() const {
		return _avg_customers;
	}
	

private:
	double run();
	void init();
	void end();
	void customerArrived();
	void customerDeparture();
	int getIdleServiceWindow();

	int _window_num;
	int _total_service_time;
	int _total_customer_stay_time;
	int _total_customer_num;

	ServerWindow* _windows;
	Queue<Customer> _customer_list;
	Queue<Event> _event_list;
	Event* _current_event;

	double _avg_stay_time;
	double _avg_customers;
};

QueueSystem::QueueSystem(int total_service_time,
		int window_num):
	_total_service_time(total_service_time),
	_window_num(window_num),
	_total_customer_stay_time(0),
	_total_customer_num(0)
{ 
	_windows = new ServerWindow[_window_num];
}

QueueSystem::~QueueSystem() {
	delete[] _windows;
}

void QueueSystem::simulate(int simulate_num) {
	double sum = 0;
	for (int i = 0; i != simulate_num; ++i)	
		sum += run();
	_avg_stay_time = 
		static_cast<double>(sum) / simulate_num;
	_avg_customers = 
		static_cast<double>(_total_customer_num) 
		/ (simulate_num * _total_service_time);
}

void QueueSystem::init() {
	_current_event = new Event;
	if (!_current_event) abort();
}

double QueueSystem::run() {
	init();
	while (_current_event) {	
		if (_current_event->_event_type == -1) 
			customerArrived();
		else 
			customerDeparture();
		delete _current_event;
		_current_event = _event_list.dequeue();
	}
	end();
	return static_cast<double>(_total_customer_stay_time)
			/ _total_customer_num;
}
 
void QueueSystem::end() {
	for (int i = 0; i != _window_num; ++i)
		_windows[i].setIdle();
	_customer_list.clear();
	_event_list.clear();
}

void QueueSystem::customerArrived() {
	++_total_customer_num;
	int intertime = Random::uniform(100);
	int time = _current_event->_occur_time 
			+ intertime;
	if (time < _total_service_time) 
		_event_list.orderEnqueue(Event(time));
	_customer_list.enqueue(
		Customer(_current_event->_occur_time) );
	int idleIndex = getIdleServiceWindow();
	if (idleIndex >= 0) {
		Customer* customer = _customer_list.dequeue();
		_windows[idleIndex].setCustomer(*customer );
		_windows[idleIndex].setBusy();
		Event temp_event(
			_current_event->_occur_time 
			+ customer->_duration, idleIndex );
		_event_list.orderEnqueue(temp_event);
		delete customer;
	}
}

int QueueSystem::getIdleServiceWindow() {
	for (int i = 0; i != _window_num; ++i)
		if (_windows[i].isIdle())
			return i;
	return -1;
}

void QueueSystem::customerDeparture() {
	if (_current_event->_occur_time 
			< _total_service_time) {
		_total_customer_stay_time += 
			_current_event->_occur_time -
			_windows[_current_event->_event_type].
				getCustomerArriveTime();
		if (!_customer_list.empty()) {
			Customer* customer = 
				_customer_list.dequeue();
			_windows[_current_event->_event_type].
				setCustomer(*customer);
			Event temp_event(
				_current_event->_occur_time 
				+ customer->_duration,
				_current_event->_event_type );
			_event_list.orderEnqueue(temp_event);
			delete customer;
		} 
		else {
			_windows[_current_event->_event_type].
				setIdle();
		}
	}
}
#endif
