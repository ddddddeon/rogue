NAME=rogue
LIBS=-lncurses
CFLAGS=-std=gnu99 -Werror $(LIBS) -DDEBUG

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c) 

$(NAME): 
	set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS)

clean:	findBin
	@rm -rf bin;

findBin:
	@[ -d bin ];
