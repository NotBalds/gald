all: build run clean

build:
	g++ -I ./include $(shell ncursesw5-config --cflags) $(shell ncursesw5-config --libs) ./src/example.cpp -oout
run:
	./out
clean:
	rm -rf out
