#include "TENUnpack.h"
#include "TArtCore.hh"

#include <TROOT.h>
#include <TDOMParser.h>
#include <TXMLNode.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


#ifdef __MAKECINT__ 
#pragma link C++ class vector<int>+;
#endif

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

Bool_t TENUnpack::ENUnpackVME(TTree *tree){
  if(tree==NULL) return false;
  BuildTree(tree);
  while(estore->GetNextEvent()){
    Clear();
    for(int i=0;i<rawevent->GetNumSeg();i++){
      seg	      = rawevent->GetSegment(i);	// get segment
      int	detid =	seg->GetDetector();             // change 
      int	modid =	seg->GetModule();


         // v1190 multi hit handling
	  int  mult1[128]={0};
	  int  mult2[128]={0};
      
    /*    for(int j=0;j<seg->GetNumData();j++){
	  TArtRawDataObject	*d   = seg->GetData(j);	
	  int			 val = d->GetVal();
	  int			 ch  = d->GetCh();	*/  
	  

	  if(modid==V1190){


		for(int j=0;j<seg->GetNumData();j++){
	 			 TArtRawDataObject	*d   = seg->GetData(j);	
	 			 int	val = d->GetVal();
	  			 int	ch  = d->GetCh();
		


				    // if(detid==PPACT||detid==PLAT) ENvme_v1190_1[ch] = val;	    	    	    // if(detid==COIN)  ENvme_v1190_2[ch] = val;	    	    
				    //  cout<<"test-->"<<ch<<endl;	    
				      if(detid==PPACT||detid==PLAT) {	      
					if(mult1[ch]<10){		  
					  ENvme_v1190_1[ch][mult1[ch]] = val;	    	    	
					  mult1[ch]++;
					}
				      }//detid

		}// Segment loop V1190
	      
	     
	    }// V1190 
	      
	  else{
		if(detid==PLAQ){
			for(int j=0;j<seg->GetNumData();j++){
				  TArtRawDataObject	*d   = seg->GetData(j);	
				  int			 val = d->GetVal();
				  int			 ch  = d->GetCh();
                                      
                                   ENvme_v792_1[ch] = val;
			}// Segment Loop
		}


		if(detid==CLOVERA){
			for(int j=0;j<seg->GetNumData();j++){
				  TArtRawDataObject	*d   = seg->GetData(j);	
				  int			 val = d->GetVal();
				  int			 ch  = d->GetCh();

				   ENvme_madc[ch]    = val;
			}//Segment Loop

		}

		// ------------------------- time stamp reading --------------------------		
		if(detid==TS){		  
		  unsigned int ts0=0,ts1=0,ts2=0;
		  unsigned long long int timestamp=0;		  
		     for(int j=0;j<seg->GetNumData();j++){
				  TArtRawDataObject	*d   = seg->GetData(j);	
				  int			 ch  = d->GetCh();    
				  unsigned int valts = d->GetVal();
		  
			  if(ch==0){
			    ts0 = (valts>>16)&0xffff;
			    ts1 = valts&0xffff;							 	
			    //cout<<" TS0 : "<<std::hex<<ts0<<" TS1 : "<<std::hex<<ts1<<endl;
			  }	
			  if(ch==1){
			    ts2 = valts&0xffff;
			    //cout<<" TS2 : "<<std::hex<<ts2<<endl;
			  }		      		      		      
		 
		  }//Segment Loop

		 // GetNumData		  
		  timestamp = ts2&0xffff;
		  timestamp = timestamp<<16;
		  timestamp = timestamp + ts1;
		  timestamp = timestamp<<16;
		  timestamp = timestamp +ts0;
		  ENvme_ts  = timestamp;
		  //cout<<" Timestamp : "<<std::dec<<ENvme_ts<<std::endl;
		  
						
		}  // Rest of modules  
	  ENrawevt=nevt;
	}    	       	
	
    }
    tree->Fill();
    nevt++;    
    if(nevt%10000==0) cout<<"ENRoot Unpacking, please be patient... Event number: "<<nevt<<endl;            
  }// Event loop
  return 1;
}


void TENUnpack::Clear(){    
  ENrawevt=0;
  memset(ENvme_madc,0,sizeof(ENvme_madc));
  memset(ENvme_v792_1,0,sizeof(ENvme_v792_1));
  memset(ENvme_v792_2,0,sizeof(ENvme_v792_2));
  memset(ENvme_v1190_1,0,sizeof(ENvme_v1190_1));
  memset(ENvme_v1190_2,0,sizeof(ENvme_v1190_2));
  //  memset(ENvme_ts,0,sizeof(ENvme_ts)); // 20150205 modifie by yamamoto
  ENvme_ts=0;
}


Bool_t TENUnpack::BuildTree(TTree *tree){
  if(tree==NULL)return 0;
  tree->Branch("ENrawevt",&ENrawevt,"ENrawevt/I");  
  tree->Branch("ENvme_v792_1",&ENvme_v792_1,"ENvme_v792_1[32]/I");	// PLASTIC ENERGY
  tree->Branch("ENvme_v792_2",&ENvme_v792_2,"ENvme_v792_2[32]/I");	// NAI ENERGY     
  tree->Branch("ENvme_madc",&ENvme_madc,"ENvme_madc[32]/I");	// ION CHANBER ENERGY 
  tree->Branch("ENvme_v1190_1",&ENvme_v1190_1,"ENvme_v1190_1[128][10]/I");	// PPAC TIME OR PLASTIC TIME     
  tree->Branch("ENvme_v1190_2",&ENvme_v1190_2,"ENvme_v1190_2[128][10]/I");	// COIN TIME      
  //  tree->Branch("ENvme_ts",&ENvme_ts,"ENvme_ts[2]/I");	// TIME STAMP
  tree->Branch("ENvme_ts",&ENvme_ts,"ENvme_ts/L");	// TIME STAMP

  return 1;

}


Bool_t TENUnpack::LoadRIDFParameters(char *xmlfile){

            TArtCore::Info(__FILE__," Load RIDF parameters from %s ",xmlfile);
            TDOMParser *domParser = new TDOMParser();
	    domParser->SetValidate(false);
	    Int_t parsecode = domParser->ParseFile(xmlfile);	
	    if(parsecode<0){
		cerr<< domParser->GetParseCodeMessage(parsecode) <<endl;
	    }
	    TXMLNode * node = domParser->GetXMLDocument()->GetRootNode();
	    ParseParaList(node->GetChildren());
	    //itrEnd = pmap.end();
	    delete domParser;

	   return true;

}

void TENUnpack::ParseParaList(TXMLNode *node){

	for(; node;node=node->GetNextNode()){
		if(node->GetNodeType()==TXMLNode::kXMLElementNode){ //Element node
		   if(strcmp(node->GetNodeName(),"ENRIDF") == 0){
			cout<<node->GetNodeName()<<endl;
		   }
		}
	}


}


















