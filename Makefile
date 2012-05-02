# Makefile
#
# Author: Roger Baker
# 
# Created on: May 2, 2012
#
# Complile using "make" and clean using "make clean"

CC = g++
CCFLAGS  = -pedantic -g
OBJS = pyou.cpp

all: PyramidOfUnix clean

PyramidOfUnix:
	${CC} ${CCFLAGS} -o $@ ${OBJS}

clean:
	rm -f *.o
