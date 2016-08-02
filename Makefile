ARCH=c
#ARCH=js

FILESYSTEM=test.pl

ifeq ($(ARCH),js)
CC=emcc
TARGET=build/proscript.js
#CFLAGS=-O2
CFLAGS=-O1 -s NO_EXIT_RUNTIME=1 -s TOTAL_MEMORY=134217738
BOOT=--pre-js $(BOOTFILE)
BOOTFILE=src/pre.js
BOOT_FS=--embed-file $(FILESYSTEM)
else
CC=gcc
TARGET=build/proscript
CFLAGS=-g -I/opt/local/include
LDFLAGS=-L/opt/local/lib
BOOTFILE=main.o
BOOT=main.o
endif

OBJECTS=kernel.o parser.o constants.o ctable.o stream.o hashmap.o test.o compiler.o bihashmap.o crc.o list.o operators.o prolog_flag.o errors.o whashmap.o module.o init.o foreign.o arithmetic.o options.o char_conversion.o term_writer.o

$(TARGET):	$(OBJECTS) $(BOOTFILE)
		$(CC) $(CFLAGS) $(OBJECTS) $(BOOT) $(BOOT_FS) $(LDFLAGS) -lgmp -o $@

foreign.o:	src/foreign.c src/foreign_impl.c
		$(CC) $(CFLAGS) -DDEBUG -c $< -o $@

%.o:		src/%.c src/constants src/instructions
		$(CC) $(CFLAGS) -DDEBUG -c $< -o $@

clean:
		rm -f *.o
