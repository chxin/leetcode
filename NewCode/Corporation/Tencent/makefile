all: 5.cpp
	g++ -std=c++11 -g $< -o main
run: all main
	./main
debug: all main
	lldb ./main
