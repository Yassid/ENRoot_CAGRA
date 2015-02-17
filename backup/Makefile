TARGET  = ENMain
CC	= g++ -std=c++0x
COPT	= -O2 
LD	= gcc
LDFLAGS	= $(OPT)
ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)
CXXFLAGS   = $(COPT) -Wall -fPIC -I$(TARTSYS)/include -I$(ROOTSYS)/include -L$(TARTSYS)/lib -lXMLParser -lanacore $(ROOTCFLAGS)
HEADERS = TENUnpack.h

CXXLIBS    = $(ROOTLIBS)
LIBS       =  -lXpm -lX11 ${ROOTLIBS} -lm
OBJS = TENUnpack.o ENMain.o 

enroot_dict.cpp: $(HEADERS) enroot_linkdef.h
	rootcint -f $@ -c $(CXXFLAGS) -p $^
 
#enroot.so: enroot_dict.cpp $(SOURCES)
#	g++ -shared -o$@ `root-config --ldflags` $(CXXFLAGS) -I$(ROOTSYS)/include $^

all:$(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) -O $(OBJS) $(LIBS) $(LDFLAGS)

clean:
	@echo " CLEANING $(TARGET)..."
	rm -f $(TARGET) $(OBJS)
.C.o:
	@echo " !!!!!!!!!!!!!!!!!!!!!!!!!!!LINK AND PRODUCING $(TARGET)..."	
	$(CC) $(CXXFLAGS) -c $<
	

ENMain.o: ENMain.C
TENunpack.o: TENunpack.cpp TENunpack.h 
