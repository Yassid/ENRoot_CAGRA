#ifndef TENUNPACK_H
#define TENUNPACK_H


class TXMLNode;
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
#include <TROOT.h>
#include <TList.h>
#include <map>

#include "TArtEventStore.hh"
#include "segidlist.h"
#ifdef __MAKECINT__ 
#pragma link C++ class vector<int>+;
#endif

using namespace std;

class TENUnpack  {
  
 private:
  
 protected:
  void ParseParaList(TXMLNode *node);
  
 public:
  int ENrawevt;
  int ENvme_v792_1[32];  
  int ENvme_v792_2[32];  
  int ENvme_madc[32]; 
  int ENvme_v1190_1[128][10]; 
  int ENvme_v1190_2[128][10]; 
  
  //int ENvme_ts[2];   // 20150205 modifie by yamamoto
  Long64_t ENvme_ts;  

  Long64_t nevt;
  TArtEventStore *estore;
  TArtRawEventObject *rawevent;
  TArtRawSegmentObject *seg; 
  
  TENUnpack();
  ~TENUnpack();    
  Bool_t Open(const char * filename);
  Bool_t ENUnpackVME(TTree *tree);
  Bool_t BuildTree(TTree *tree);
  Bool_t LoadRIDFParameters(char *xmlfile);
  void Clear();
  //  20140612 change  
};

#endif

