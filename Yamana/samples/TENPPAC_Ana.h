#ifndef TENPPAC_ANA_H
#define TENPPAC_ANA_H

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

using namespace std;

class TENPPAC_Ana{
 private:

  // virtual int* GetF2UPPAC_xl(){return F2UPPAC;}

 public:
  TENPPAC_Ana();
  ~TENPPAC_Ana();
  Bool_t GetENTree(TTree *sorttree,TTree *anatree);   
  Bool_t BuildAnaTree(TTree *anatree);   // TMP FUNCTION
 
  int F2UPPAC[5];
  int F2DPPAC[5];
  int F3UPPAC[5];
  int F3DPPAC[5];

  double F2UPPA_pos;
  double F2DPPA_pos;
  double F3UPPA_pos;
  double F3DPPA_pos;

};
#endif
