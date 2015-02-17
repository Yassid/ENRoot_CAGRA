#include "TENNaI_Sort.h"

TENNaI_Sort::TENNaI_Sort(){}
TENNaI_Sort::~TENNaI_Sort(){}


Bool_t TENNaI_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;  
  Clear();
  sorttree->Branch("F3NaI_H",&F3NaI_H,"F3NaI_H/I");
  sorttree->Branch("F3NaI_L",&F3NaI_L,"F3NaI_L/I");
  sorttree->Branch("F3NaI_H_T",&F3NaI_H_T,"F3NaI_H_T/I");
  sorttree->Branch("F3NaI_L_T",&F3NaI_L_T,"F3NaI_L_T/I");

  return 1;
}

Bool_t TENNaI_Sort::SetNaIValue(TTree *rawtree,TTree *sorttree,int nevent){
  if(rawtree==NULL)return 0;    
  rawtree->GetEntry(nevent);   
  
  F3NaI_H=ENvme_v792_2[2];
  F3NaI_L=ENvme_v792_2[3];
  F3NaI_H_T = ENvme_v1190_1[13][0];
  F3NaI_L_T = ENvme_v1190_1[15][0];

  return 1;
}

void TENNaI_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F3NaI_H",i);
  sorttree->SetBranchStatus("F3NaI_L",i);
  sorttree->SetBranchStatus("F3NaI_H_T",i);
  sorttree->SetBranchStatus("F3NaI_L_T",i);
  
}


void TENNaI_Sort::Clear(){    
  F3NaI_H=0;
  F3NaI_L=0;
  F3NaI_H_T=0;
  F3NaI_L_T=0;

}
