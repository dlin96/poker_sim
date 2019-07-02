CPPFLAGS = -Wall -Werror -std=c++14 -g -Og -I ./include
DEPS = $(wildcard include/*.h)
objects = src/card.o \
		  src/deck.o \
		  src/game.o \
		  src/main.o \
		  src/player.o \
		  $(NULL)

%.o: %.cpp $(DEPS)
		g++ -c $< -o $@ $(CPPFLAGS)

all: texas_holdem

playertest:
	g++ test/playertest.cpp src/player.cpp src/card.cpp $(CPPFLAGS)

texas_holdem: $(objects) 
			g++ -o $@ $^ $(CPPFLAGS)

clean: 
	rm src/*.o
