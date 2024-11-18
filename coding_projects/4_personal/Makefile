FLAGS = -Wall -Wextra -g
CC = g++

all: driver

driver: Voter.o RegisterVoter.o driver.o
	$(CC) $(FLAGS) RegisterVoter.o Voter.o driver.o -o $@

Voter.o: Voter.cpp Voter.h
	$(CC) $(FLAGS) -c Voter.cpp -o $@

RegisterVoter.o: RegisterVoter.cpp RegisterVoter.h Voter.h
	$(CC) $(FLAGS) -c RegisterVoter.cpp -o $@

driver.o: driver.cpp RegisterVoter.h Voter.h
	$(CC) $(FLAGS) -c driver.cpp -o $@

clean:
	rm driver *.o