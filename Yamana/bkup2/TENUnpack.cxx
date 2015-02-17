#include "TENUnpack.h"

TENUnpack::TENUnpack(){
  nevt   = 0;
  estore = new TArtEventStore(); 
}

TENUnpack::~TENUnpack(){}

Bool_t TENUnpack::Open(const char *filename){
  if(estore==0) estore	= new TArtEventStore();
   bool flag		= 0;
   flag			= estore->Open(filename);
   rawevent		= estore->GetRawEventObject();
   return flag;   
}

Bool_t TENUnpack::BuildEvent(TTree *tree){
  if(tree==NULL) return false;
  //  BranchTree(daq);
  while(estore->GetNextEvent()){
    // Clear();
    for(int i=0;i<rawevent->GetNumSeg();i++){
      seg	      = rawevent->GetSegment(i);	//get segment
      int	detid =	seg->GetDetector();
      int	modid =	seg->GetModule();
      cout<<"Unpacking VME - Event number : "<<nevt<<endl;
      // DecodeRaw(detid,modid);
    }
    tree->Fill();
    nevt++;
  }
  return 1;
}
