
CXXFLAGS = -g -Wall -Wfatal-errors 

ALL = main

all: $(ALL)

main: main.cpp Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp

clean:
	$(RM) $(ALL) *.o
