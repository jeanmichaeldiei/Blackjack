# This is a complicated makefile so don't try to copy it
# It compiles every .cpp file in this directory into an executable

CC = g++
CFLAGS= -Wall -Werror -std=c++11 -g

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -rf *o $(PROGS)
