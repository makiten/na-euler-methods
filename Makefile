#----------Macros-------------------------

BASEDIR = ./src
INCDIR = $(BASEDIR)/include
LIBDIR = $(BASEDIR)/lib

LIBS = -lm

INCLUDES = -I$(BASEDIR) -I$(INCDIR) -I$(LIBDIR)

CC=gcc
CCFLAGS=-Wall $(INCLUDES)

#----------Dependencies-------------------

SRC = $(INCDIR)/* $(LIBDIR)/* $(BASEDIR)/main.c

OBJ = numerical-euler

#----------Commands-----------------------

CLEAN=rm -rf euler.log
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
	$(CC) $(CCFLAGS) $(LIBS) -o $(OBJ) $(SRC)
clean:
	$(CLEAN) $(OBJ)
