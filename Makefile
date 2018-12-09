CC = GCC
CFLAGS ?= -O1 -Wall
LDFLAGS ?=

ODIR = ./bin

src = $(wildcard src/*.c)
sql = $(wildcard ./*.sql)

.PHONY: build mysql

build: $(src)
	$(CC) $(src) $(CFLAGS) $(LDFLAGS) -o $(ODIR)/translate

mysql: $(sql)
	mysql < $(sql)
