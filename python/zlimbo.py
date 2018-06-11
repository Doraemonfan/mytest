#!/usr/bin/env python3

import math

def move(x, y, step, angle=0):
	nx = x + step * math.cos(angle)
	ny = y - step * math.sin(angle)
	return nx, ny


def quadratic(a, b, c):
	d = b * b - 4 * a * c
	if d < 0:
		raise TypeError('b*b-4ac<0')
	x1 = (-b + math.sqrt(d)) / (2 * a)
	x2 = (-b - math.sqrt(d)) / (2 * a)
	return x1, x2


def my_abs(x):
	if not isinstance(x, (int, float)):
		raise TypeError('bad operand type')
	if x >= 0:
		return 10
	else:
		return -x


def power(x, n=2):
	s = 1
	while n > 0:
		n = n - 1
		s = s * x
	return s
	

def calc(*numbers):
	sum = 0
	for n in numbers:
		sum = sum + n * n
	return sum

def product(a, *args):
	for x in args:
		a = a * x
	return a
	
def person(name, age, **kw):
	print('name:', name, 'age:', age, 'other:', kw)

def f1(a, b, c=0, *args, **kw):
	print('a=', a, 'b=', b, 'c=', c, 'args=', args, 'kw=', kw)

def f2(a, b, c=0, *, d, **kw):
	print('a=', a, 'b=', b, 'c=', c, 'd=', d, 'kw=', kw)


def trim(s):
	b = 0
	e = len(s)
	while b < e and s[b] == ' ':
		b = b + 1
	while b < e and s[e-1] == ' ':
		e = e - 1
	s = s[b:e]
	return s


def findMinAndMax(L):
	if len(L) == 0:
		return (None, None)
	Min = L[0]
	Max = L[0]
	for x in L[1:]:
		if x < Min:
			Min = x
		if x > Max:
			Max = x
	return (Min, Max)


