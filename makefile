CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lsyslog

all: main

main: main.o CodeTemplate.o CodeBuilder.o CodeGenerator.o
    $(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
    rm -f *.o main
    
