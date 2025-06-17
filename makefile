compile:
	g++ -std=c++20 src/main.cpp ../tools/Button.cpp 
	-I/opt/homebrew/Cellar/sfml/2.6.1/include -o main 
	-L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics 
	-lsfml-window -lsfml-system

clean:
	rm -f main bin/*.o
