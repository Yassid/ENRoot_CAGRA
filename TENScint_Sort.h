#ifndef TENScint_SORT_H
#define TENScint_SORT_H

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

class TENScint_Sort{
 private:
 public:
  TENScint_Sort();
  ~TENScint_Sort();
  Bool_t	BuildSortTree(TTree *sorttree);  
  Bool_t	SetScintValue(TTree* rawtree,TTree* sorttree,int nevent);
  void		BranchSwitcher(TTree *sorttree,int i);
  void		Clear();
  
  Bool_t SetRawBranchAddress(TTree* rawtree){ 
    rawtree->SetBranchAddress("ENvme_v792_1", ENvme_v792_1, &b_ENvme_v792_1);
    rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);    
    return 1;
  };

  int ENvme_v792_1[32];
  int ENvme_v1190_1[128][10];

  int F3Plastic_LQ;
  int F3Plastic_RQ;
  int F3Veto_LQ;
  int F3Veto_RQ;

  int F3Plastic_LT;
  int F3Plastic_RT;
  int F3Veto_LT;
  int F3Veto_RT;

  TBranch        *b_ENvme_v792_1;
  TBranch        *b_ENvme_v1190_1;
  
};
#endif
