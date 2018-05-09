SOURCE := $(wildcard *.cpp)
EXEC := $(SOURCE:.cpp=)
G++ := g++ -g -std=c++14 

$(EXEC): % : %.cpp
	$(G++) -o $@ $<

