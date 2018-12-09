CC = gcc
CPP = g++
CFLAGS ?= -O1 -Wall
LDFLAGS ?=

ODIR = ./bin

src = ./src

.PHONY: clean

run:
	python3 robot.py

ROBOT:
	@sleep 1 # wait for callbacks
	@echo -n $(DO) > data/command.text
	@make -s run||:

build: $(src)
	$(CC) $(src)/translate.c $(CFLAGS) $(LDFLAGS) -o $(ODIR)/translate
	$(CPP) $(src)/genxml.c $(CPPFLAGS) $(LDFLAGS) -o $(ODIR)/genxml

clean:
	rm $(ODIR)/*
	touch $(ODIR)/.keep

build2:
	make clean||:;	make build;
