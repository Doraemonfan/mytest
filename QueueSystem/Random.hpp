//
// Random.hpp
// QueueSystem
// 2018/4/25
//

#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__


#include <cstdlib>
#include <ctime>

class Random {
public:
	static double uniform(double max = 1) {	
		return static_cast<double>(rand()) 
			/ RAND_MAX * max;
	}
};



#endif
