SOURCE := $(wildcard *.cpp)
SOURCE2 := $(wildcard *.c)

EXEC := $(SOURCE:.cpp=)
EXEC2 := $(SOURCE2:.c=)

OBJ := $(SOURCE:.cpp=.o)

G++ := g++ -g -std=c++14 
GCC := gcc -g -std=c11 

$(EXEC): %: %.cpp
	$(G++) -o $@ $< -lpthread 

$(EXEC2): %: %.c
	$(GCC) -o $@ $< 
