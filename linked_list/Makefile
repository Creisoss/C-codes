CC = gcc
CFLAGS = -Wall -O2

SOURCES = ./src/climenu/climenuupdate.c ./src/climenu/climenucreate.c ./src/climenu/climenuprint.c ./src/core/starter.c ./src/utils/utils.c ./src/list/list.c ./src/climenu/climenufile.c ./src/climenu/climenumain.c ./src/climenu/climenudelete.c ./src/core/main.c
OBJECTS = $(SOURCES:.c=.o)

BINARY = ./bin/list

all: $(BINARY) clean_after_compile

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BINARY)

clean_after_compile:
	rm -f $(OBJECTS)
