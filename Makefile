all: build run clean

build:
	g++ -I ./include -lncursesw ./src/example.cpp -oout
run:
	./out
clean:
	rm -rf out
