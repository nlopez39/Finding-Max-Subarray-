CC = g++

all:
	$(CC) -std=c++11 -o a.exe nlopez53.cpp

clean:
	rm -f a.exe

