CC = gcc
CFLAGS = -O2 -Wall -I.
DEPS = iprs_types.h sign.h validity.h
OBJECTS = sign.o validity.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)
