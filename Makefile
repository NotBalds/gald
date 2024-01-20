demo:
	g++ -I ./include $(ncurses-config --cflags) $(ncurses-config -- libs) ./src/example.cpp -oout
	./out
