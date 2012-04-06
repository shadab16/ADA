CXX =		g++

CXXFLAGS =	-O2 -Wall -Wextra -pedantic

VPATH =		src/

1a:		1a.o
	$(CXX) -o practical$@ $@.o $(LIBS)

1b:		1b.o
	$(CXX) -o practical$@ $@.o $(LIBS)

2:		2.o
	$(CXX) -o practical$@ $@.o $(LIBS)

3:		3.o
	$(CXX) -o practical$@ $@.o $(LIBS)

4:		4.o
	$(CXX) -o practical$@ $@.o $(LIBS)

5:		5.o
	$(CXX) -o practical$@ $@.o $(LIBS)

6:		6.o
	$(CXX) -o practical$@ $@.o $(LIBS)

7:		7.o
	$(CXX) -o practical$@ $@.o $(LIBS)

8:		8.o
	$(CXX) -o practical$@ $@.o $(LIBS)

9:		9.o
	$(CXX) -o practical$@ $@.o $(LIBS)

10:		10.o
	$(CXX) -o practical$@ $@.o $(LIBS)

clean:
	$(RM) *.o practical*

