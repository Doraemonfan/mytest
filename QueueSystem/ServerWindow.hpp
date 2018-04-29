//
// ServerWindow.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __SERVERWINDOW_HPP__
#define __SERVERWINDOW_HPP__

#include "Customer.hpp"

class ServerWindow {

public:
	enum STATUS { SERVE, IDLE };
	ServerWindow() = default;
	ServerWindow(const Customer& customer,
			STATUS status = IDLE):
		_customer(customer), _status(status)
	{ }
	bool isIdle() const { return _status == IDLE; }
	void setCustomer(Customer& customer) {
		_customer = customer;
	}
	void setBusy() { _status = SERVE; }
	void setIdle() { _status = IDLE; }
	int getCustomerArriveTime() const { 
		return _customer._arrive_time;
	}
	int getCustomerDuration() const { 
		return _customer._duration;
	}

//private:
	Customer _customer;
	STATUS _status;
};

#endif
