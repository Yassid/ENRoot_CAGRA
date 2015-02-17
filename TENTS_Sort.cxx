#include "TENTS_Sort.h"

TENTS_Sort::TENTS_Sort(){}
TENTS_Sort::~TENTS_Sort(){}

Bool_t TENTS_Sort::GetENTree(TTree *tree,TTree *sorttree){
  if(tree==NULL)return 0;  
  tree->SetBranchAddress("ENvme_ts",&ENvme_ts);      
  int nEvent= tree->GetEntries();
  cout<<"  Unpacking EN Time Stamp, please be patient....."<<endl;
  
  for(int i=0;i<nEvent;i++){
    tree->GetEntry(i);
    if(i%10000==0)cout<<" Event: "<<i<<"/"<<nEvent<<endl;                          
    TimeStamp=ENvme_ts[0]+TimeStamp;
    EvNum=i++;
    sorttree->Fill();
    
  }

}

Bool_t TENTS_Sort::BuildSortTree(TTree *tree){
  if(tree==NULL)return 0;
  tree->Branch("TimeStamp",&TimeStamp,"TimeStamp/I");
  tree->Branch("EvNum",&EvNum,"EvNum/I");
  return 1;
}



