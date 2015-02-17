#ifndef TENNaI_SORT_H
#define TENNaI_SORT_H

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

class TENNaI_Sort{
 private:
 public:
  TENNaI_Sort();
  ~TENNaI_Sort();
  Bool_t BuildSortTree(TTree *sorttree);  
  Bool_t SetNaIValue(TTree *rawtree,TTree *sorttree,int nevent);
  void BranchSwitcher(TTree *sorttree,int i);
  void Clear();

  Bool_t SetRawBranchAddress(TTree* rawtree){ 
    rawtree->SetBranchAddress("ENvme_v792_2", ENvme_v792_2, &b_ENvme_v792_2);
    rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);
    return 1;
  };
  

  int ENvme_v792_2[32];
  int ENvme_v1190_1[128][10];
  int F3NaI_H;
  int F3NaI_L;
  int F3NaI_H_T;
  int F3NaI_L_T;


  TBranch        *b_ENvme_v792_2;
  TBranch        *b_ENvme_v1190_1;

};
#endif
