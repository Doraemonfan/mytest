SOURCE := $(wildcard *.cpp)
OBJ := $(SOURCE:.cpp=.o)
EXEC := t
C++ := g++ -std=c++14 -g -Wall

$(EXEC): $(OBJ)
	$(C++) -o $@ $^

$(OBJ): %.o: %.cpp 
	$(C++) -o $@ -c $<
