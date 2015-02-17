 #include "TENUnpackf.h"

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
	    //	    if(detid==PPACT) ENvme_v1190_1[ch] = val;	    
	  }
	  else{
	    ENvme = val;
	    ENvmedetid = detid;
	    ENvmech       = ch;
	  }  
	  tree->Fill();
	}	       	
    
    }
    
    ENrawevt=nevt;

    nevt++;    
    if(nevt%10000==0) cout<<"Event number: "<<nevt<<endl;    
    
    
  }
  //  tree->Write();
  return 1;
}


  void TENUnpack::Clear(){    
}


Bool_t TENUnpack::BuildTree(TTree *tree){
  if(tree==NULL)return 0;
  tree->Branch("ENrawevt",&ENrawevt,"ENrawevt/I");  
  //  tree->Branch("ENvme",ENvme,"ENvme[64][32]/I");      
  //  tree->Branch("ENvme_v1190_1",&ENvme_v1190_1,"ENvme_v1190_1[128]/I");      
  
  // Temp
  tree->Branch("ENvme",&ENvme,"ENvme/I");      
  tree->Branch("ENvmedetid",&ENvmedetid,"ENvmedetid/I");      
  tree->Branch("ENvmech",&ENvmech,"ENvmech/I");      

  tree->Branch("ENvme_v1190",&ENvme_v1190,"ENvme_v1190/I");      
  tree->Branch("ENvmedetid_v1190",&ENvmedetid_v1190,"ENvmedetid_v1190/I");      
  tree->Branch("ENvmech_v1190",&ENvmech_v1190,"ENvmech_v1190/I");        
  return 1;

}
