OBJS=mc_pi.o generator.o przetwarzacz.o sumator.o aproksymator.o ekran.o iwatek.o
CXX=i686-w64-mingw32-g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++14
LDFLAGS=-lncurses -pthread

all: mc_pi

mc_pi : $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean