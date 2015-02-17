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
#include"TArtEventStore.hh"

//#include "segidlist.h"
/* #ifdef __MAKECINT__ */
/* #pragma link C++ class vector<int>+; */
/* #endif */

using namespace std;

class TENUnpack  {
  
 private:
  
 public:
  //  Int_t ENnevt;
  
  /************************/
  /****   My Analyzer  ****/
  /************************/
  int		fvme;
  int		fdetid,fmodid;
  int		fmodch;
  Long64_t	fevtnum;
  /************************/



  vector< vector<int> > ENvme;
  Long64_t ENnevt;
  Long64_t nevt;
  TArtEventStore *estore;
  TArtRawEventObject *rawevent;
  TArtRawSegmentObject *seg; 

  TENUnpack();
  ~TENUnpack();    
  Bool_t Open(const char * filename);
  void   EventLoop(int detid,int modid);
  Bool_t ENUnpackVME(TTree *tree);
  Bool_t BuildTree(TTree *tree);
  void Clear();
  //  20140612 change
  //  ClassDef(TENUnpack,1);

};

#endif

