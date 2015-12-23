#SRC = $(shell find ../nodes/ -name *.cpp)
#OBJS = $(SRC:%.cpp = %.o)

#OBJS = *.o
SRC = $(wildcard ../nodes/*.cpp)
OBJS = $(SRC:.cpp=.o)
all: testNode

testNode: $(OBJS)
	g++ $(OBJS) -o testNode

clean:
	rm -rf *.o testNode