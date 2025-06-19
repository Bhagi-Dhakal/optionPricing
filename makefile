CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
SRC = src/main.cpp src/matrix2D.cpp src/binomialModel.cpp
OUT = bin/main

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) 

run: $(OUT)
	./$(OUT)

clean: 
	rm -f $(OUT) bin/*.o

