 #include "TENUnpack.h"

TENUnpack::TENUnpack():ENvme(62,vector<int>(32,-1)){
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

Bool_t TENUnpack::ENUnpackVME(TTree *tree){
  if(tree==NULL) return false;
  BuildTree(tree);
  while(estore->GetNextEvent()){
    Clear();
    for(int i=0;i<rawevent->GetNumSeg();i++){
      seg	      = rawevent->GetSegment(i);	//get segment
      int	detid =	seg->GetDetector();
      int	modid =	seg->GetModule();
      for(int j=0;j<seg->GetNumData();j++){
	TArtRawDataObject	*d   = seg->GetData(j);	
	int			 val = d->GetVal();
	fvme   = val; /*My Ana*/		
      }
    }    
    //    ENnevt=nevt;
    fevtnum=nevt;     /*My Ana*/
    tree->Fill();
    nevt++;        
    

  }
  return 1;
}


void TENUnpack::Clear(){
  ENvme.clear();
}

Bool_t TENUnpack::BuildTree(TTree *tree){
  if(tree==NULL){return 0;}
  //  tree->Branch("ENvme",&ENvme);
  //  tree->Branch("ENnevt",&ENnevt,"ENnevt/L");  
  tree->Branch("fvme",&fvme,"fvme/I");  
  tree->Branch("fdetid",&fdetid,"fdetid/I");  
  tree->Branch("fmodid",&fmodid,"fmodid/I");  
  tree->Branch("fevtnum",&fevtnum,"fevtnum/I");  
  return 1;
}
