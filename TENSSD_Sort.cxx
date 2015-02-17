#include "TENSSD_Sort.h"

TENSSD_Sort::TENSSD_Sort(){}
TENSSD_Sort::~TENSSD_Sort(){}

Bool_t TENSSD_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  sorttree->Branch("F2SSD",&F2SSD,"F2SSD/I");
  sorttree->Branch("F3SSD",&F3SSD,"F3SSD/I");
  return 1;
}


Bool_t TENSSD_Sort::SetSSDValue(TTree *rawtree,TTree *sorttree,int nevent){
  if(rawtree==NULL)return 0;  
  
    rawtree->GetEntry(nevent);

    F2SSD=ENvme_v792_2[8];
    F3SSD=ENvme_v792_2[12];

    return 1;
}

void TENSSD_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F2SSD",i);
  sorttree->SetBranchStatus("F3SSD",i);
}

void TENSSD_Sort::Clear(){
  F2SSD=0;
  F3SSD=0;
}
