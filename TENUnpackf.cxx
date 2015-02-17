 #include "TENUnpack.h"

#ifdef __MAKECINT__ 
#pragma link C++ class vector<int>+;
#endif

TENUnpack::TENUnpack(){
  nevt   = 0;
  estore = new TArtEventStore(); 
  //  for(int i=0;i<64;i++){
  //    for(int j=0;j<128;j++){
  //      if(j<32)ENvme[i][j]=0;
  //      if(i<11)ENvme_v1190[i][j]=0;
  //  }
  //  }
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
      int	detid =	seg->GetDetector();             // change 
      int	modid =	seg->GetModule();
      
        for(int j=0;j<seg->GetNumData();j++){
	  TArtRawDataObject	*d	       = seg->GetData(j);	
	  int			 val	       = d->GetVal();
	  int			 ch	       = d->GetCh();	  
	  if(modid==V1190){
	    ENvme_v1190			       = val;
	    ENvmedetid_v1190		       = detid;
	    ENvmech_v1190			       = ch;
	    ENvme      = 0;
	    ENvmedetid = 0;
	    EvmeNch       = 0;
	  }
	  else{
	    ENvme = val;
	    ENvmedetid = detid;
	    ENvmech       = ch;
	    ENvme_v1190      = 0;
	    ENvmedetid_v1190 = 0;
	    ENvmech_v1190       = 0;

	  }  
	  ENrawevt=nevt;
	  tree->Fill();
	  Clear();
	}	       	    
    }        
    nevt++;    
    if(nevt%10000==0) cout<<"Event number: "<<nevt<<endl;    
    
    
  }
  //  tree->Write();
  return 1;
}


  void TENUnpack::Clear(){    
     ENrawevt=0;
     ENvme=0; 
     ENvme_v1190=0;  
     ENvmedetid=0;ENvmedetid_v1190=0; 
     ENvmech=0;ENvmech_v1190=0;     

}


Bool_t TENUnpack::BuildTree(TTree *tree){
  if(tree==NULL)return 0;
  tree->Branch("ENrawevt",&ENrawevt,"ENrawevt/I");  
  
  // Temp
  tree->Branch("ENvme",&ENvme,"ENvme/I");      
  tree->Branch("ENdetid",&ENdetid,"ENdetid/I");      
  tree->Branch("ENch",&ENch,"ENch/I");      

  tree->Branch("ENvme_v1190",&ENvme_v1190,"ENvme_v1190/I");      
  tree->Branch("ENdetid_v1190",&ENdetid_v1190,"ENdetid_v1190/I");      
  tree->Branch("ENch_v1190",&ENch_v1190,"ENch_v1190/I");        
  return 1;

}
