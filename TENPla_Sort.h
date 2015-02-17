#ifndef TENPla_SORT_H
#define TENPla_SORT_H

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

class TENPla_Sort{
 private:
 public:
  TENPla_Sort();
  ~TENPla_Sort();
  Bool_t	BuildSortTree(TTree *sorttree);  
  Bool_t	SetPlasticValue(TTree* rawtree,TTree* sorttree,int nevent);
  void		BranchSwitcher(TTree *sorttree,int i);
  void		Clear();
  
  Bool_t SetRawBranchAddress(TTree* rawtree){ 
    rawtree->SetBranchAddress("ENvme_v792_1", ENvme_v792_1, &b_ENvme_v792_1);
    rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);    
    return 1;
  };

  int ENvme_v792_1[32];
  int ENvme_v1190_1[128][10];

  int F2Plastic_Q;
  int F3Plastic_LQ;
  int F3Plastic_RQ;

  int F2Plastic_T;
  int F3Plastic_LT;
  int F3Plastic_RT;

  TBranch        *b_ENvme_v792_1;
  TBranch        *b_ENvme_v1190_1;
  
};
#endif
