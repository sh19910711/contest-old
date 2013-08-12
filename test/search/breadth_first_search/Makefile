include ../../Makefile.in

all: main.cpp
	$(CXX) $(CPPFLAGS) -o main.exe main.cpp $(LIBGTEST) $(LIBGTEST_MAIN) $(CPPFLAGS_AFTER)

clean:
	rm -f main.exe
	rm -f *.gcda
	rm -f *.gcov
	rm -f *.gcno

test:
	./main.exe $(GTESTFLAGS) 
	gcovr $(GCOVRFLAGS) 

test-only:
	./main.exe $(GTESTFLAGS) 


