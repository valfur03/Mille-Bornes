CC=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=run
SRC=$(wildcard sources/*.cpp)
OBJ=$(SRC: .cpp=.o)

all: $(EXEC)
	./$(EXEC)

run: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: includes/Card.h includes/Distance.h includes/Hazard.h includes/Player.h includes/Remedy.h includes/Safety.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f ./$(EXEC)
