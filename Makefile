CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS = llrec-test.o llrec.o
OBJSTACK = stack-test.o
OBJHEAP = heap-test.o
all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)
llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

stack-test: $(OBJSTACK) stack.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJSTACK)

heap-test: $(OBJHEAP) heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJHEAP)
heap-test.o: heap-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c heap-test.cpp





#llrec-test: llrec-test.cpp llrec.o
#	$(CXX) $(CXXFLAGS) $(DEFS) $< -o llrec-test
#llrec.o: llrec.cpp llrec.h
#	$(CXX) $(CXXFLAGS) $(DEFS) -c $^ -o llrec.o





clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 