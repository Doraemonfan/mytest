//
// main.cpp
// QueueSystem
// 2018/4/25
//

#include "QueueSystem.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand((unsigned)time(0));
	int total_service_time = 240;
	int window_num = 4;
	int simulate_num = 100000;

	QueueSystem system(total_service_time, window_num);
	system.simulate(simulate_num);

	std::cout << "The average time of " 
		"customer staying in bank: "
		<< system.getAvgStayTime() << std::endl;
	std::cout << "The number of customer "
		"arriving bank per minute: "
		<< system.getAvgCustomers() << std::endl;

	return 0;
}

