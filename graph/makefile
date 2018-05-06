SOURCE := $(wildcard *.cpp)
EXEC := $(SOURCE:.cpp=)
OBJ := $(SOURCE:.cpp=.o)
CC := g++ -std=c++14 -g

$(EXEC): %: %.cpp
	$(CC) -o $@ $<

