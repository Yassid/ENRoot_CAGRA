#include "TENPla_Sort.h"

TENPla_Sort::TENPla_Sort(){}
TENPla_Sort::~TENPla_Sort(){}


Bool_t TENPla_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  Clear();
  sorttree->Branch("F2Plastic_Q",&F2Plastic_Q,"F2Plastic_Q/I");
  sorttree->Branch("F3Plastic_LQ",&F3Plastic_LQ,"F3Plastic_LQ/I");
  sorttree->Branch("F3Plastic_RQ",&F3Plastic_RQ,"F3Plastic_RQ/I");
  sorttree->Branch("F2Plastic_T",&F2Plastic_T,"F2Plastic_T/I");
  sorttree->Branch("F3Plastic_LT",&F3Plastic_LT,"F3Plastic_LT/I");
  sorttree->Branch("F3Plastic_RT",&F3Plastic_RT,"F3Plastic_RT/I");
  return 1;
}


Bool_t TENPla_Sort::SetPlasticValue(TTree *rawtree,TTree *sorttree,int nevent){
  if(rawtree==NULL)return 0;  
  

  rawtree->GetEntry(nevent);
  
  F2Plastic_Q=ENvme_v792_1[0];     //F2Plastic Charge
  F3Plastic_LQ=ENvme_v792_1[1];    //F3Plastic L-Charge
  F3Plastic_RQ=ENvme_v792_1[2];    //F3Plastic R-Charge
  
  F2Plastic_T=ENvme_v1190_1[13][0]; //F3Plastic L-Time
  F3Plastic_LT=ENvme_v1190_1[26][0]; //F3Plastic L-Time
  F3Plastic_RT=ENvme_v1190_1[28][0]; //F3Plastic R-Time
  

  return 1;
}


void TENPla_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F2Plastic_Q",i);
  sorttree->SetBranchStatus("F3Plastic_LQ",i);
  sorttree->SetBranchStatus("F3Plastic_RQ",i);
  sorttree->SetBranchStatus("F2Plastic_T",i);
  sorttree->SetBranchStatus("F3Plastic_LT",i);
  sorttree->SetBranchStatus("F3Plastic_RT",i);

}

void TENPla_Sort::Clear(){    
  F2Plastic_Q=0;
  F3Plastic_LQ=0;
  F3Plastic_RQ=0;
  F2Plastic_T=0;
  F3Plastic_LT=0;
  F3Plastic_RT=0;

}
