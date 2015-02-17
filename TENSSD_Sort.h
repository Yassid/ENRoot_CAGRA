#ifndef TENSSD_SORT_H
#define TENSSD_SORT_H

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

class TENSSD_Sort{
 private:
 public:
  TENSSD_Sort();
  ~TENSSD_Sort();
  Bool_t BuildSortTree(TTree *sorttree);  
  Bool_t SetSSDValue(TTree *rawtree,TTree *sorttree,int nevent);
  void BranchSwitcher(TTree *sorttree,int i);
  void Clear();
  
  Bool_t SetRawBranchAddress(TTree* rawtree){ 
    rawtree->SetBranchAddress("ENvme_v792_2", ENvme_v792_2, &b_ENvme_v792_2);
    return 1;
  };
  
  
  int ENvme_v792_2[32];  
  int F2SSD;
  int F3SSD;

  TBranch        *b_ENvme_v792_2;

};
#endif
