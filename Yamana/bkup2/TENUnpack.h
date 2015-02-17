#ifndef TENUNPACK_H
#define TENUNPACK_H

class TArtRawEventObject;
class TArtRawSegmentObject;

#include <TH1.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TSystem.h>

#include"TArtEventStore.hh"

//#include "segidlist.h"



using namespace std;

class TENUnpack  {
  
 private:
  
 public:
  Long64_t nevt;
  TArtEventStore *estore;
  TArtRawEventObject *rawevent;
  TArtRawSegmentObject *seg; 

  TENUnpack();
  ~TENUnpack();    
  Bool_t Open(const char * filename);
  void   EventLoop(int detid,int modid);
  Bool_t BuildEvent(TTree *tree);
  void BuildTree(TTree *tree);
  // 20140612 change
  //  ClassDef(TENUnpack,1);

};

#endif
