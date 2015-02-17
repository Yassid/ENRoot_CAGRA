#include "TENClover_Sort.h"

TENClover_Sort::TENClover_Sort(){}
TENClover_Sort::~TENClover_Sort(){}

Bool_t TENClover_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  sorttree->Branch("F2Clover",&F2Clover,"F2Clover/I");
  sorttree->Branch("F3Clover",&F3Clover,"F3Clover/I");
  return 1;
}


Bool_t TENClover_Sort::SetCloverValue(TTree *rawtree,TTree *sorttree,int nevent){
  if(rawtree==NULL)return 0;  
  rawtree->GetEntry(nevent);
  
  F2Clover=ENvme_v792_2[8];
  F3Clover=ENvme_v792_2[12];

  return 1;
}

void TENClover_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F2Clover",i);
  sorttree->SetBranchStatus("F3Clover",i);
}

void TENSSD_Sort::Clear(){
  //  F2SSD=0;
  //  F3SSD=0;
}
