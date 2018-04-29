//
// Math.hpp
// Math
// 2018/4/29
//

#ifndef __MATH_HPP__
#define __MATH_HPP__

#include <cstdlib>

namespace Math {
	
	constexpr double PI = 3.1415926575;
	constexpr double E = 2.718281828;

	int abs(int x) {
		return (x < 0) ? -x : x;
	}

	double abs(double x) {
		return (x < 0.0) ? -x : x;
	}

	bool isPrime(int N) {
		if (N < 2) return false;
		if (N % 2 == 0) return false;
		for (int i = 3; i * i <= N; i += 2) 
			if (N % i == 0) return false;
		return true;
	}

	double sqrt(double c) {
		if (c < 0) return 0.0 / 0.0;
		double err = 1e-15;
		double t = c;
		while (Math::abs(t - c/t) > err * t)
			t = (t + c/t) / 2.0;
		return t;
	}

	double hypotenuse(double a, double b) {
		if (a < 0 || b < 0) abort();
		return sqrt(a*a + b*b);
	}
	
	double Harmonic(int N) {
		double sum = 0.0;
		for (int i = 1; i <= N; ++i)
			sum += 1.0 / i;
		return sum;
	}

	template <typename T>
	T max(const T& a, const T& b) {
		return (a < b) ? b : a;
	}

	template <typename T>
	T min(const T& a, const T& b) {
		return (a < b) ? a : b;
	}

	double pow(double a, double b) {
		//TODO
	}

	double sin(double x) {
		//TODO
	}
	
	double random() {
		//TODO
	}

	

	
};

#endif

