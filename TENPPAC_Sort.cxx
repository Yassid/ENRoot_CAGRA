#include "TENPPAC_Sort.h"

TENPPAC_Sort::TENPPAC_Sort(){}
TENPPAC_Sort::~TENPPAC_Sort(){}

Bool_t TENPPAC_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  Clear();
  sorttree->Branch("F2UPPAC",F2UPPAC,"F2UPPAC[5]/I");
  sorttree->Branch("F2DPPAC",F2DPPAC,"F2DPPAC[5]/I");
  sorttree->Branch("F3UPPAC",F3UPPAC,"F3UPPAC[5]/I");
  sorttree->Branch("F3DPPAC",F3DPPAC,"F3DPPAC[5]/I");  
  return 1;
}

Bool_t TENPPAC_Sort::SetPPACValue(TTree* rawtree,TTree* sorttree,int nevent){

 
  if(rawtree==NULL)return 0;  
    
  rawtree->GetEntry(nevent);   
  //  if(nevent%10000)cout<<"debug - "<<ENvme_v1190_1[0][0]<<endl;
  F2UPPAC[0]=ENvme_v1190_1[0][0]; // F2UPPAC LEFT
  F2UPPAC[1]=ENvme_v1190_1[1][0]; // F2UPPAC DOWN
  F2UPPAC[2]=ENvme_v1190_1[2][0]; // F2UPPAC RIGHT
  F2UPPAC[3]=ENvme_v1190_1[3][0]; // F2UPPAC UP
  F2UPPAC[4]=ENvme_v1190_1[4][0]; // F2UPPAC ANODE    
  F2DPPAC[0]=ENvme_v1190_1[5][0]; // F2DPPAC LEFT
  F2DPPAC[1]=ENvme_v1190_1[6][0]; // F2DPPAC DOWN
  F2DPPAC[2]=ENvme_v1190_1[7][0]; // F2DPPAC RIGHT
  F2DPPAC[3]=ENvme_v1190_1[8][0]; // F2DPPAC UP
  F2DPPAC[4]=ENvme_v1190_1[9][0]; // F2DPPAC ANODE    
  
  F3UPPAC[0]=ENvme_v1190_1[16][0]; // F3UPPAC LEFT
  F3UPPAC[1]=ENvme_v1190_1[17][0]; // F3UPPAC DOWN
  F3UPPAC[2]=ENvme_v1190_1[18][0]; // F3UPPAC RIGHT
  F3UPPAC[3]=ENvme_v1190_1[19][0]; // F3UPPAC UP
  F3UPPAC[4]=ENvme_v1190_1[20][0]; // F3UPPAC ANODE    
  
  F3DPPAC[0]=ENvme_v1190_1[21][0]; // F3DPPAC LEFT
  F3DPPAC[1]=ENvme_v1190_1[22][0]; // F3DPPAC DOWN
  F3DPPAC[2]=ENvme_v1190_1[23][0]; // F3DPPAC RIGHT
  F3DPPAC[3]=ENvme_v1190_1[24][0]; // F3DPPAC UP
  F3DPPAC[4]=ENvme_v1190_1[25][0]; // F3DPPAC ANODE    

  return 1;   
}

void TENPPAC_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F2UPPAC",i);
  sorttree->SetBranchStatus("F2DPPAC",i);
  sorttree->SetBranchStatus("F3UPPAC",i);
  sorttree->SetBranchStatus("F3DPPAC",i);
}

void TENPPAC_Sort::Clear(){    
  memset(F2UPPAC,-100,sizeof(F2UPPAC));
  memset(F2DPPAC,-100,sizeof(F2DPPAC));
  memset(F3UPPAC,-100,sizeof(F3UPPAC));
  memset(F3DPPAC,-100,sizeof(F2DPPAC));
}


int TENPPAC_Sort::Echo(int evtnum){
  return  F2UPPAC[0];
}    
