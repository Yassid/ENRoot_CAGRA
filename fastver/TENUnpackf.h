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
#include <vector>
#include "TArtEventStore.hh"
#include "segidlist.h"
#ifdef __MAKECINT__ 
#pragma link C++ class vector<int>+;
#endif

using namespace std;

class TENUnpack  {
  
 private:
  
 public:
  //  int ENvme[64][32];
  //  int ENvme_v1190_1[128]; 
  //  int ENvme_v1190_2[128]; 
  
  // Temp */
  int ENrawevt;
  int ENvme; 
  int ENvme_v1190;  
  int ENvmedetid,ENvmedetid_v1190; 
  int ENvmech,ENvmech_v1190; 
  
   //  Long64_t ENnevt;  

  
  Long64_t nevt;
  TArtEventStore *estore;
  TArtRawEventObject *rawevent;
  TArtRawSegmentObject *seg; 

  TENUnpack();
  ~TENUnpack();    
  Bool_t Open(const char * filename);
  //void   EventLoop(int detid,int modid);
  Bool_t ENUnpackVME(TTree *tree);
  Bool_t BuildTree(TTree *tree);
  void Clear();
  
};

#endif

