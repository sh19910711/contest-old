include ../../Makefile.in

all: main.cpp
	g++ $(CPPFLAGS) -o main.exe main.cpp $(LIBGTEST) $(LIBGTEST_MAIN)

clean:
	rm -f main.exe
	rm -f *.gcda
	rm -f *.gcov
	rm -f *.gcno

test:
	./main.exe $(GTESTFLAGS) 
	gcovr $(GCOVRFLAGS) 


