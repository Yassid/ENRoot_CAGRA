# MAKE FILE FOR CARAF Test By Tetsuya Yamamoto (RCNP)
OBJ = ENMain
sourcefile = ENMain.cxx TENUnpack.cxx TENUnpack.h 

ROOTCFLAGS  = $(shell root-config --cflags)
ROOTLIBS    = $(shell root-config --libs)

CFLAGS = -Wall -O2 -I$(TARTSYS)/include -I$(ROOTSYS)/include -L$(TARTSYS)/lib -lXMLParser -lanacore

GXX = g++ -std=c++0x

all:$(OBJ)

$(OBJ): $(sourcefile)
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ $(filter %.cxx ,$(sourcefile)) 

clean:
	rm -f *~ *.o $(OBJ)