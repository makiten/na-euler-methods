CC=gcc
CFLAGS=-Wall
CLEAN=rm -rf euler.log
SOURCES=euler.c
EXECUTABLE=euler
MAKE=make -s
all: install
install:
	uname=`uname`; \
	user=`whoami`; \
	if test $$uname == "Darwin" ; \
	then \
		if test $$user != "root" ; \
		then \
			echo "You need to be root to run make."; \
			exit 1; \
		fi \
	fi
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE);
clean:
	$(CLEAN) $(EXECUTABLE)
