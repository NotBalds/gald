demo:
	g++ -I ./include $(shell ncurses-config --cflags) $(shell ncurses-config --libs) ./src/example.cpp -oout
	./out
