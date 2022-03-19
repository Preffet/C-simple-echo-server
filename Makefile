SHELL = /bin/sh
client := echo_client
server := echo_server

CC ?= cc

CFLAGS := -Wall

# may have to edit the following if not on Linux
os := $(shell uname)
ifeq ($(os),Linux)
    CFLAGS +=-g -std=c99 -D_GNU_SOURCE
endif

all: $(client) $(server)
.PHONY: all

clean:
	-rm -rf $(client)
	-rm -rf $(server)
.PHONY: clean

$(server): $(server).c

$(client): $(client).c


