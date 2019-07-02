## Poker Simulation

# Motivation  
As someone who enjoys the occasional poker game (specificall Texas Hold'em), I have always enjoyed the strategy of the game. Most of this does come from playing with other human beings and includes difficult-to-quanitfy qualities like how much risk a person is willing to take or if an individual has a "tell" of some sorts indicating what kind of hand they may have. For this project, I decided to try and understand the mathematics behind the game.  

# The Simulation
The idea was to simulate many iterations of a texas hold'em game and keep track of the number of times a certain hand won each game. As of right now, the output looks something like this:

STRAIGHT FLUSH      3                   
ROYAL STRAIGHT FLUSH2                   
STRAIGHT            78                  
FLUSH               46                  
HIGH                64                  
FOUR OF A KIND      5                   
FULL HOUSE          44                  
THREE OF A KIND     61                  
PAIR                391                 
TWO PAIR            306 

To run this project, run "make" and then run the executable named "texas_holdem". The number of times you wish to run or "play a game" can be altered in the main.cpp file.

# The Process
For this project, I wrote the Card, Deck, Player and Game objects and implemented the logic to
	a) determine the best hand the player can make from their own hand and the community cards
	b) compare against other players to see which hand won

The Card object simply represents a single card with a rank and suit. 

The Deck object represents a deck of cards, with the ability to "deal" cards.

The Player object represents a single player with their own "hand" of two cards, and the ability to determine their best hand from their private hand and the community cards. 

The Game object is an abstraction of a single game of Texas Hold'em. First, it creates a list of players and creates a deck. Then it deals in each player, and runs through the stages of a game. It deals (and burns) cards in the appropriate order (first comes the flop, the turn, then river).

The various poker hands are kept in an enum class in the poker_hands file. 

# TODO
This project is far from being complete, so the issue tracker is a good record of things I need to fix or features I want to add. There are a lot of things that can be optimized, and definitely some style revision necessary. 