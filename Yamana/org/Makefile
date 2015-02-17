# MAKE FILE FOR CARAF Test By Tetsuya Yamamoto (RCNP)

OBJ = decorder 
sourcefile = decorder.C r2root.C r2root.h 


ROOTCFLAGS  = $(shell root-config --cflags)
ROOTLIBS    = $(shell root-config --libs)

CFLAGS = -Wall -O2 -I$(TARTSYS)/include -I$(ROOTSYS)/include -L$(TARTSYS)/lib -lXMLParser -lanacore

GXX = g++ -std=c++0x

all:$(OBJ)

$(OBJ): $(sourcefile)
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ $(filter %.C ,$(sourcefile))

clean:
	rm -f *~ *.o $(OBJ)
