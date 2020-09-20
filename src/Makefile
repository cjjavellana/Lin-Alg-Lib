main.o : main.cpp
	clang++ -c main.cpp

matrix: main.o
	clang++ main.o -o matrix

clean:
	rm -f *.o matrix