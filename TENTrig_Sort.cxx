#include "TENTrig_Sort.h"

TENTrig_Sort::TENTrig_Sort(){}
TENTrig_Sort::~TENTrig_Sort(){}

Bool_t TENTrig_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  Clear();
  sorttree->Branch("RF1",&RF1,"RF1/I");
  sorttree->Branch("RF2",&RF2,"RF2/I");
  sorttree->Branch("TRIG",&TRIG,"TRIG/I");
  sorttree->Branch("CoinReg",CoinReg,"CoinReg[4]/I");
  return 1;
}

Bool_t TENTrig_Sort::SetTrigValue(TTree* rawtree,TTree* sorttree,int nevent){
  if(rawtree==NULL)return 0;    
  rawtree->GetEntry(nevent);   
  
  RF1     = ENvme_v1190_1[10][0];
  RF2     = ENvme_v1190_1[12][0];
  TRIG    = ENvme_v1190_1[11][0];
  
  CoinReg[0] = ENvme_v1190_2[0][0];
  CoinReg[1] = ENvme_v1190_2[1][0];
  CoinReg[2] = ENvme_v1190_2[2][0];
  CoinReg[3] = ENvme_v1190_2[3][0];

  return 1;  
}

void TENTrig_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("RF1",i);
  sorttree->SetBranchStatus("RF2",i);
  sorttree->SetBranchStatus("TRIG",i);
  sorttree->SetBranchStatus("CoinReg",i);
}
void TENTrig_Sort::Clear(){    
  RF1     = 0;
  RF2     = 0;
  TRIG    = 0;
  memset( CoinReg,-100,sizeof( CoinReg));
}


