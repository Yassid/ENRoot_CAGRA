#include "TENIonChamb_Sort.h"

TENIonChamb_Sort::TENIonChamb_Sort(){}
TENIonChamb_Sort::~TENIonChamb_Sort(){}


Bool_t TENIonChamb_Sort::BuildSortTree(TTree *sorttree){
  if(sorttree==NULL)return 0;
  Clear();
  sorttree->Branch("F3MUSIC_E",F3MUSIC_E,"F3MUSIC_E[8]/I");  
  sorttree->Branch("F3MUSIC_T",F3MUSIC_T,"F3MUSIC_T[8]/I");  
  return 1;
}

Bool_t TENIonChamb_Sort::SetIonChambValue(TTree *rawtree,TTree *sorttree,int  nevent){
  if(rawtree==NULL)return 0;  
  
  rawtree->GetEntry(nevent);

  for(int j=0;j<8;j++){
    F3MUSIC_E[j] =  ENvme_madc[j];
    F3MUSIC_T[j] =  ENvme_v1190_1[j+64][0];
  }
    
  return 1;
  
}

void TENIonChamb_Sort::BranchSwitcher(TTree *sorttree,int i){
  sorttree->SetBranchStatus("F3MUSIC_E",i);
  sorttree->SetBranchStatus("F3MUSIC_T",i);
}

void TENIonChamb_Sort::Clear(){    
   memset(F3MUSIC_E,-100,sizeof(F3MUSIC_E));
   memset(F3MUSIC_T,-100,sizeof(F3MUSIC_T));
}
