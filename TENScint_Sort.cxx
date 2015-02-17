#include "TENScint_Sort.h"

TENScint_Sort::TENScint_Sort(){}
TENScint_Sort::~TENScint_Sort(){}


Bool_t TENScint_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  Clear();
  sorttree->Branch("F3Plastic_LQ",&F3Plastic_LQ,"F3Plastic_LQ/I");
  sorttree->Branch("F3Plastic_RQ",&F3Plastic_RQ,"F3Plastic_RQ/I");
  sorttree->Branch("F3Veto_LQ",&F3Veto_LQ,"F3Veto_LQ/I");
  sorttree->Branch("F3Veto_RQ",&F3Veto_RQ,"F3Veto_RQ/I");

  sorttree->Branch("F3Plastic_LT",&F3Plastic_LT,"F3Plastic_LT/I");
  sorttree->Branch("F3Plastic_RT",&F3Plastic_RT,"F3Plastic_RT/I");
  sorttree->Branch("F3Veto_LT",&F3Veto_LT,"F3Veto_LT/I");
  sorttree->Branch("F3Veto_RT",&F3Veto_RT,"F3Veto_RT/I");
  
  return 1;
}


Bool_t TENScint_Sort::SetScintValue(TTree *rawtree,TTree *sorttree,int nevent){
  if(rawtree==NULL)return 0;  
  
  rawtree->GetEntry(nevent);
  
  F3Plastic_LQ	    = ENvme_v792_1[1];	//F3Plastic L-Charge
  F3Plastic_RQ	    = ENvme_v792_1[2];	//F3Plastic R-Charge
  F3Veto_LQ         = ENvme_v792_1[1];	//F3Plastic L-Charge
  F3Veto_RQ         = ENvme_v792_1[2];	//F3Plastic R-Charge

  F3Plastic_LT = ENvme_v1190_1[26][0];	//F3Plastic L-Time
  F3Plastic_RT = ENvme_v1190_1[28][0];	//F3Plastic R-Time  
  F3Veto_LT = ENvme_v1190_1[27][0];	//F3Plastic L-Time
  F3Veto_RT = ENvme_v1190_1[29][0];	//F3Plastic R-Time  

  return 1;
}


void TENScint_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F3Plastic_LQ",i);
  sorttree->SetBranchStatus("F3Plastic_RQ",i);
  sorttree->SetBranchStatus("F3Veto_LQ",i);
  sorttree->SetBranchStatus("F3Veto_RQ",i);
  sorttree->SetBranchStatus("F3Plastic_LT",i);
  sorttree->SetBranchStatus("F3Plastic_RT",i);
  sorttree->SetBranchStatus("F3Veto_LT",i);
  sorttree->SetBranchStatus("F3Veto_RT",i);
  
}

void TENScint_Sort::Clear(){    
  F3Plastic_LQ = 0;
  F3Plastic_RQ = 0;
  F3Plastic_LT = 0;
  F3Plastic_RT = 0;
  F3Veto_LQ = 0;
  F3Veto_RQ = 0;
  F3Veto_LT = 0;
  F3Veto_RT = 0;
}
