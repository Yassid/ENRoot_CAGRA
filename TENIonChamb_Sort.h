#ifndef TENIonChamb_SORT_H
#define TENIonChamb_SORT_H

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

class TENIonChamb_Sort{
 private:
 public:
  TENIonChamb_Sort();
  ~TENIonChamb_Sort();
  Bool_t	BuildSortTree(TTree *sorttree);  
  Bool_t	SetIonChambValue(TTree* rawtree,TTree* sorttree,int nevent);
  void		BranchSwitcher(TTree *sorttree,int i);
  void		Clear();

  Bool_t SetRawBranchAddress(TTree* rawtree){ 
    rawtree->SetBranchAddress("ENvme_madc", ENvme_madc, &b_ENvme_madc);
    rawtree->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);    
    return 1;
  };
  
  int	ENvme_madc[32];  
  int	ENvme_v1190_1[128][10];  
  int	F3MUSIC_E[8];
  int	F3MUSIC_T[8];

  TBranch        *b_ENvme_v1190_1;
  TBranch        *b_ENvme_madc;
};
#endif
