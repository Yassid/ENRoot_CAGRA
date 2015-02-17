#ifndef TENTRIG_SORT_H
#define TENTRIG_SORT_H

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

class TENTrig_Sort{
 private:


 public:
  TENTrig_Sort();
  ~TENTrig_Sort();
  
  Bool_t BuildSortTree(TTree *sorttree);  
  Bool_t SetTrigValue(TTree* rawtree,TTree* sorttree,int nevent);
  void BranchSwitcher(TTree *sorttree,int i);
  void Clear();
  int Echo(int evtnum);
  
  Bool_t SetRawBranchAddress(TTree* rawtree){ 
  rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);
  rawtree->SetBranchAddress("ENvme_v1190_2", ENvme_v1190_2, &b_ENvme_v1190_2);
  return 1;
  };

  int RF1;
  int RF2;
  int TRIG;
  int CoinReg[4];

  int      ENvme_v1190_1[128][10];  
  int      ENvme_v1190_2[128][10];  
  TBranch        *b_ENvme_v1190_1;
  TBranch        *b_ENvme_v1190_2;
};
#endif
