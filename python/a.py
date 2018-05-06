#!/usr/bin/env python3
x = 1
n = 10
sum = 0
while x <= n:
	sum += 1 / x
	if (x != sum):
		print("1/{} + ".format(x))
	else:
		print("1/{}".format(x))
	x += 1
print(" = {:.5f}".format(sum))
	
