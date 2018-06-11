# coding=utf-8

import turtle
import math
import time
import random

def paintdot(lst):
    for i in range(len(lst)):
        turtle.penup()
        turtle.goto(lst[i][0], lst[i][1])
        if lst[i][2] == 1:
            turtle.color("black")
        else:
            turtle.color("red")
        turtle.pendown()
        turtle.dot(5)


def paintline(sl):
    if sl[0] == 0:
        dge = 90
    else:
        dge = math.degrees(math.atan(sl[1]/sl[0]))

    turtle.penup()
    turtle.goto(0, 0)
    turtle.setheading(dge+90)
    turtle.forward(300)

    turtle.penup()
    turtle.pendown()
    turtle.color("green")
    turtle.setheading(dge-90)
    turtle.forward(600)

    
def line(lst):
    sl = [0, 0]
    len_ = len(lst)
    ok = False
    turtle.speed(10)
    turtle.clear()
    paintdot(lst)
    while not ok:
        ok = True
        for i in range(len_):
            ot = lst[i][0] * sl[0] + lst[i][1] * sl[1]
            if lst[i][2] == 1 and ot <= 0:
                sl[0] += lst[i][0]
                sl[1] += lst[i][1]
                ok = False
            elif lst[i][2] == -1 and ot >= 0:
                sl[0] -= lst[i][0]
                sl[1] -= lst[i][1]
                ok = False
        paintline(sl)
        if not ok:
            turtle.undo()


#a = [(1, 1, 1), (2, 1, 1), (3, 0, 1), (4, 2, 1), (-1, 0, -1), (-2, -3, -1)]
#line(a)
#turtle.screensize(1000,800)
b = []
n = 5
m = 10
for _ in range(n):
    x = random.randrange(0, m*20, 20)
    y = random.randrange(0, m*20, 20)
    z = random.choice([-1, 1, 1, 1])
    b.append((x,y,z))
for i in b:
    print(i)
print(b)
line(b)
turtle.mainloop()
