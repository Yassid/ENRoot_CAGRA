//**********************************
// raw to root program 
//
// 
//
// Mon May 26 2014 By Lee(Jing Li)(PKU) E407  
// June 05 2014 By Tetsuya Yamamoto(RCNP) CAGRAF Test 
//**********************************


#ifndef R2ROOT_H
#define R2ROOT_H

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

//THESE PARAM IS NOT USED FOR CAGRAF 08062014
const int adcnum=13; 
const int gdcnum=3; 
const int qdcnum=1; 
const int scanum=1; 

class r2root
{
 private:
  
 public:
  Int_t qdc0;
  Int_t qdc1;
  Int_t qdc2;
  Int_t qdc3;
  Int_t qdc4;
  Int_t qdc5;
  Int_t qdc6;
  Int_t qdc7;
 
  Int_t tdc0;
  Int_t tdc1;
  Int_t tdc2;
  Int_t tdc3;
  Int_t tdc4;
  Int_t tdc5;
  Int_t tdc6;
  Int_t tdc7;
  Int_t tdc8;
  Int_t tdc9;
  Int_t madc;           

  unsigned long int ts0;
  unsigned long int ts1;
  Long64_t neve;
  Long64_t nevt;
  
  TArtEventStore *estore;
  TArtRawEventObject *rawevent;
  TArtRawSegmentObject *seg;
  
    r2root();
    ~r2root();
    Bool_t        BranchTree(TTree *daq);
    void          Clear();
    Bool_t        BuildEvent(TTree *daq);
    Bool_t        BuildEvent(TTree *daq,Int_t maxnevt);
    Bool_t        Open(const char * filename);
    void          DecodeRaw(int detid,int modid);
};

#endif

