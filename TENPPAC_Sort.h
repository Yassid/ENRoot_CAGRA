#ifndef TENPPAC_SORT_H
#define TENPPAC_SORT_H

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

class TENPPAC_Sort{
 private:

  // virtual int* GetF2UPPAC_xl(){return F2UPPAC;}

 public:
  TENPPAC_Sort();
  ~TENPPAC_Sort();
  
  Bool_t BuildSortTree(TTree *sorttree);  
  Bool_t   SetPPACValue(TTree* rawtree,TTree* sorttree,int nevent);
  void BranchSwitcher(TTree *sorttree,int i);
  void Clear();
  int Echo(int evtnum);
  
  Bool_t SetRawBranchAddress(TTree* rawtree){ 
  rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);
  return 1;
  };
  


  int ENvme_v1190_1[128][10];
  int F2UPPAC[5];
  int F2DPPAC[5];
  int F3UPPAC[5];
  int F3DPPAC[5];
  
  TBranch        *b_ENvme_v1190_1;

};
#endif
