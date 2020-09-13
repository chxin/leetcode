compile: ./34-find-int-appear-once.cpp
	g++ -std=c++11 -Wall $< -o main
	g++ -std=c++11 -Wall $< -g -o debug-main
run: compile main
	./main
debug: compile debug-main
	lldb ./debug-main
