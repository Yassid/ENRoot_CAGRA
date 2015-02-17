# MAKE FILE FOR CARAF Test By Tetsuya Yamamoto (RCNP)
OBJ = ENMain
sourcefile = ENMain.cxx TENUnpack.cxx TENUnpack.h TENPPAC_Sort.cxx TENPPAC_Sort.h TENNaI_Sort.cxx TENNaI_Sort.h TENIonChamb_Sort.cxx TENIonChamb_Sort.h TENSSD_Sort.cxx TENSSD_Sort.h TENTS_Sort.cxx TENTS_Sort.h F2UPPAC_Cal.cxx F2UPPAC_Cal.h TENSort.cxx TENSort.h TENScint_Sort.cxx TENScint_Sort.h TENTrig_Sort.cxx TENTrig_Sort.h
# TENClover_Sort.cxx TENClover_Sort.h

ROOTCFLAGS  = $(shell root-config --cflags)
ROOTLIBS    = $(shell root-config --libs)

CFLAGS = -Wall -O2 -I$(TARTSYS)/include -I$(ROOTSYS)/include -L$(TARTSYS)/lib -lXMLParser -lanacore

GXX = g++ -std=c++0x

all:$(OBJ)

$(OBJ): $(sourcefile)
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ $(filter %.cxx ,$(sourcefile)) 

clean:
	rm -f *~ *.o $(OBJ)