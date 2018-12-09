CC = gcc
CPP = g++
CFLAGS ?= -O1 -Wall
LDFLAGS ?=

ODIR = ./bin

src = ./src

.PHONY: clean

build: $(src)
	$(CC) $(src)/translate.c $(CFLAGS) $(LDFLAGS) -o $(ODIR)/translate
	$(CPP) $(src)/genxml.c $(CPPFLAGS) $(LDFLAGS) -o $(ODIR)/genxml

clean:
	rm $(ODIR)/*
	touch $(ODIR)/.keep
