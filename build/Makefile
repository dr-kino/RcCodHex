SDIR = ../src
IDIR = ../include
ODIR = .obj

OBJECTC = objectc.o

CC=gcc
CFLAGS+=-I$(IDIR)
CFLAGS+=-Wall -c

CXX=g++
CXXFLAGS+=-I$(IDIR)
CXXFLAGS+=-std=c++11

CSOURCES = \
	$(SDIR)/rccodhex_cmd.c 

CXXSOURCES = \
	$(SDIR)/rccodhex.cpp


rc-codhex: 
	$(CC) $(CSOURCES) $(CFLAGS) -o $(ODIR)/$(OBJECTC)
	$(CXX) $(ODIR)/$(OBJECTC) $(CXXSOURCES) $(CXXFLAGS) -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~

