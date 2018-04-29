#include <iostream>
#include <cstdlib>
#include "Random.hpp"
#include "Event.hpp"
#include "Queue.hpp"
#include "Customer.hpp"
#include "ServerWindow.hpp"
#include "QueueSystem.hpp"

using namespace std;
int main() {
	std::srand((unsigned)time(0));

	for (int i = 0; i < 5; ++i)
		std::cout << rand() << " ";
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << Random::uniform() << " ";
	std::cout << std::endl;
	
	Event event(1, 2);
	Customer customer(1);
	Queue<Customer> qc;
	qc.enqueue(customer);
	qc.enqueue(customer);
	qc.enqueue(customer);
	Queue<Event> qe;
	qe.enqueue(event);
	qe.enqueue(event);
	qe.enqueue(event);
	qc.show();
	qe.show();
	
	cout << qc.length() << endl;
	cout << qe.length() << endl;
	ServerWindow sw(customer);
	qc.clear();
	qc.show();

	return 0;
}
