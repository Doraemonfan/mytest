SOURCE := $(wildcard *.cpp)
EXEC := $(SOURCE:.cpp=)
OBJ := $(SOURCE:.cpp=.o)
CC := g++ -g -std=c++14 

$(EXEC): %: %.cpp
	$(CC) -o $@ $< -lpthread 
