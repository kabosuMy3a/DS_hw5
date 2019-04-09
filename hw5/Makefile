CXX = g++
CXXFLAGS =
TARGETS = hw5
OBJS = Stack.o Calculator.o hw5.cpp

all : $(TARGETS)

$(TARGETS) : $(OBJS)
	$(CXX)$(CXXFLAGS) -o $@ $^


%.o : %.cpp %.h
		$(CXX) -c $(CXXFLAGS) $(OPTION) $< -o $@

clean :
	rm *.o hw5

