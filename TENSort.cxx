#include "TENSort.h"
#include "TENPPAC_Sort.h"
#include "TENNaI_Sort.h"
#include "TENIonChamb_Sort.h"
#include "TENScint_Sort.h"
#include "TENSSD_Sort.h"
#include "TENTrig_Sort.h"

TENSort::TENSort(){}
TENSort::~TENSort(){}


Bool_t TENSort::GetENSortTree(TTree *rawtree,TTree *sorttree){
   if(rawtree==NULL)return 0;  
 
   TENPPAC_Sort		*enppac	 = new TENPPAC_Sort();
   TENNaI_Sort		*ennai	 = new TENNaI_Sort();
   TENIonChamb_Sort	*enmusic = new TENIonChamb_Sort();
   TENScint_Sort	*enscint = new TENScint_Sort();
   TENSSD_Sort		*enssd	 = new TENSSD_Sort();
   TENTrig_Sort		*entrig	 = new TENTrig_Sort();

   

   
   
   //   TENClover_Sort		*enclover	 = new TENClover_Sort();
   
   enppac->BuildSortTree(sorttree);
   ennai->BuildSortTree(sorttree);
   enmusic->BuildSortTree(sorttree);

   enscint->BuildSortTree(sorttree);
   entrig->BuildSortTree(sorttree);
   
   enssd->BuildSortTree(sorttree);
   enssd->SetRawBranchAddress(rawtree);   	
   
   //     for CAGRA-campaign    
   //  enclover->BuildSortTree(sorttree);
   //  enclover->SetRawBranchAddress(sorttree);
   
   int	nEvent = rawtree->GetEntries();
   
   for(int i=0;i<nEvent;i++){
     
     if(i%10000==0) cout<<"ENRoot Sorting, please be patient... Event number: "<<i<<"/"<<nEvent<<endl;
     
     enppac->SetRawBranchAddress(rawtree);
     enppac->SetPPACValue(rawtree,sorttree,i);
     
     ennai->SetRawBranchAddress(rawtree);
     ennai->SetNaIValue(rawtree,sorttree,i);

     enmusic->SetRawBranchAddress(rawtree);
     enmusic->SetIonChambValue(rawtree,sorttree,i);
     
     enscint->SetRawBranchAddress(rawtree);
     enscint->SetScintValue(rawtree,sorttree,i);
     
     enssd->SetRawBranchAddress(rawtree);
     enssd->SetSSDValue(rawtree,sorttree,i);
     //     for CAGRA-campaign 
     //     enclover->SetRawBranchAddress(rawtree);
     //     enclover->SetCLOVERValue(rawtree,sorttree,i);
     
     entrig->SetRawBranchAddress(rawtree);
     entrig->SetTrigValue(rawtree,sorttree,i);
     
     
     sorttree->Fill();
     
   }
   
   delete enppac;
   delete ennai;
   delete enmusic;
   delete enscint;
   delete enssd;

   //   delete enclover;

   
   return 1;
}
