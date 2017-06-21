OBJS=mc_pi.o generator.o przetwarzacz.o sumator.o aproksymator.o ekran.o
CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic
LDFLAGS=-lncurses

all: mc_pi

mc_pi : $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean