CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=
PROJECT=Cars
EXEC=$(PROJECT)

SRC=car.c main.c
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(PROJECT): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: *.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) 

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

re: clean all 
