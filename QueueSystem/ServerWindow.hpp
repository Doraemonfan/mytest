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
	enum STATUS { WORK, IDLE };
	ServerWindow(const Customer& customer,
			STATUS status = IDLE):
		_customer(customer), _status(status)
	{ }

//private:
	Customer _customer;
	STATUS _status;
};

#endif
