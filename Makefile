CC=gcc
CFLAGS=-Wall
CLEAN=rm -rf euler.log
SOURCES=euler.c
EXECUTABLE=euler

all: $(EXECUTABLE)
$(EXECUTABLE):
	UNAME:=$(shell uname)
	USER:=$(whoami)
	if [[ $(UNAME) == "Darwin"]]; then
		if [[ $(USER) != "root" ]]; then
			echo "You must be root to compile. Aborting."
			exit 1
		fi
	fi
	
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
clean:
	$(CLEAN) $(EXECUTABLE)
