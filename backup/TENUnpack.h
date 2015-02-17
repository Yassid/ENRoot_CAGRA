#ifndef TENUNPACK_H_
#define TENUNPACK_H_

class TArtRawEventObject;
class TArtRawSegmentObject;

#include <TH1.h>
#include <string>
#include <sstream>
#include <fstream>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TSystem.h>

#include "TArtEventStore.hh"

//#include "segidlist.h"

#include <iostream>
using namespace std;

class TENUnpack {
  
  private:

  public:
  Long64_t nevt;
 // TArtEventStore *estore;
 // TArtRawEventObject *rawevent;
 // TArtRawSegmentObject *seg; 

  TENUnpack();
  ~TENUnpack();    
 // bool Open(const char * filename);
  // 20140612 change
//  ClassDef(TENUnpack,1);

};

#endif
