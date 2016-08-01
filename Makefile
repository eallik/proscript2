#ARCH=c
ARCH=js

FILESYSTEM=test.pl

ifeq ($(ARCH),js)
CC=emcc
TARGET=build/proscript.js
#CFLAGS=-O2
CFLAGS=-g -s NO_EXIT_RUNTIME=1
BOOT=--pre-js $(BOOTFILE)
BOOTFILE=src/pre.js
BOOT_FS=--embed-file $(FILESYSTEM)
else
CC=gcc
TARGET=build/proscript
CFLAGS=-g
BOOTFILE=main.o
BOOT=main.o
endif

OBJECTS=kernel.o parser.o constants.o ctable.o stream.o hashmap.o test.o compiler.o bihashmap.o crc.o list.o operators.o prolog_flag.o errors.o whashmap.o module.o init.o foreign.o

$(TARGET):	$(OBJECTS) $(BOOTFILE)
		$(CC) $(CFLAGS) $(OBJECTS) $(BOOT) $(BOOT_FS) -o $@

foreign.o:	src/foreign.c src/foreign_impl.c
		$(CC) $(CFLAGS) -DDEBUG -c $< -o $@

%.o:		src/%.c src/constants src/instructions
		$(CC) $(CFLAGS) -DDEBUG -c $< -o $@

clean:
		rm -f *.o
