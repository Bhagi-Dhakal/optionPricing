CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude
SRC = src/main.cpp  src/binomialModel.cpp src/blackScholesFormula.cpp
OUT = bin/main

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) 

run: $(OUT)
	./$(OUT)

clean: 
	rm -f $(OUT) bin/*.o

