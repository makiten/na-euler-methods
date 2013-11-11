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

#----------User info----------------------
USER=$(shell whoami)
GROUP=$(shell id -gn)

#----------Commands-----------------------

CLEAN=rm -rf euler.log
MAKE=make -s

all: install
install:
ifeq ($(shell uname), Darwin)
	sudo $(CC) $(CCFLAGS) $(LIBS) -o $(OBJ) $(SRC)
	sudo chown $(USER):$(GROUP) $(OBJ)
else
	$(CC) $(CCFLAGS) $(LIBS) -o $(OBJ) $(SRC)
endif

clean:
	$(CLEAN) $(OBJ)
