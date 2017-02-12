TOP_DIR=..
LIB_DIR=$(TOP_DIR)
GCC = g++

CFLAGS = -g -W -Wall -I.

LIBS = 
SRCS = udpclient.cpp
INCDIR = includes
OBJS = udpclient.o

all: $(OBJS)
	$(GCC) $(CFLAGS) $(LIBS) $(OBJS) -o udpclient.out

udpclient.o: udpclient.cpp
	$(GCC) $(CFLAGS) $(INCLUDE) -c udpclient.cpp

clean:
	rm -f *.o *~ udpclient.out

