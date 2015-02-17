#include "TENPPAC_Ana.h"

TENPPAC_Ana::TENPPAC_Ana(){}
TENPPAC_Ana::~TENPPAC_Ana(){}

Bool_t TENPPAC_Ana::GetENTree(TTree *sorttree,TTree *anatree){
  if(tree==NULL)return 0;  
  sorttree->SetBranchAddress("F2UPPAC",&F2UPPAC);
  sorttree->SetBranchAddress("F2DPPAC",&F2DPPAC);
  sorttree->SetBranchAddress("F3UPPAC",&F3UPPAC);
  sorttree->SetBranchAddress("F3DPPAC",&F3DPPAC);  
  
  int nEvent= tree->GetEntries();
  cout<<"  Analyzing EN PPACS, please be patient....."<<endl;
  
  for(int i=0;i<nEvent;i++){
    sorttree->GetEntry(i);         
    if(i%10000==0)cout<<" Event: "<<i<<"/"<<nEvent<<endl;                          
    
    anatree->Fill();   
  }
 
}

void TENPPAC_Ana::F2UPPAC_Cal(){
  F2UPPAC_pos = ;  
}

void TENPPAC_Ana::F2DPPAC_Cal(){
  F2DPPAC_pos = ;
}  

void TENPPAC_Ana::F3UPPAC_Cal(){
  F3UPPAC_pos = ;
}  

void TENPPAC_Ana::F3DPPAC_Cal(){
  F3DPPAC_pos = ;
}  



Bool_t TENPPAC_Ana::BuildAnaTree(TTree *anatree){
  if(tree==NULL)return 0;
  anatree->Branch("F2UPPAC_pos",&F2UPPAC_pos,"F2UPPAC_pos/D");
  anatree->Branch("F2DPPAC_pos",&F2DPPAC_pos,"F2DPPAC_pos/D");
  anatree->Branch("F3UPPAC_pos",&F3UPPAC_pos,"F3UPPAC_pos/D");
  anatree->Branch("F3DPPAC_pos",&F3DPPAC_pos,"F3DPPAC_pos/D");  
  
  return 1;
}
