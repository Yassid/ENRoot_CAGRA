#include "r2root.h"

r2root::r2root(){
  estore = new TArtEventStore(); 
  nevt	  = 0;
}

Bool_t r2root::Open(const char *filename){
  if(estore==0) estore	= new TArtEventStore();
  bool flag		= 0;
  flag			= estore->Open(filename);
  rawevent		= estore->GetRawEventObject();
  return flag;
}

Bool_t r2root::BuildEvent(TTree *daq){
  if(daq==NULL) return false;
  BranchTree(daq);
  while(estore->GetNextEvent()){
    Clear();
    for(int i=0;i<rawevent->GetNumSeg();i++){
      seg	      = rawevent->GetSegment(i);	//get segment
      int	detid =	seg->GetDetector();
      int	modid =	seg->GetModule();
      DecodeRaw(detid,modid);
    }
    neve=nevt;
    daq->Fill();
    nevt++;    
    if(ts0==0&&ts1==0)
      cout<<nevt<<endl;    
    
    //    if(nevt%10000==0)
    //      cout<<nevt<<endl;
  }
  return 1;
}

Bool_t r2root::BuildEvent(TTree *daq,Int_t maxnevt){
  if(daq==NULL) return false;
  BranchTree(daq);
  while(estore->GetNextEvent())
    {
    Clear();
    for(int i=0;i<rawevent->GetNumSeg();i++)
    {
      seg	      = rawevent->GetSegment(i);	//get segment
      int	detid =	seg->GetDetector();
      int	modid =	seg->GetModule();
      DecodeRaw(detid,modid);
    }
    daq->Fill();
    nevt++;
    if(nevt>=maxnevt) break;
  }
  return 1;
}

void r2root::DecodeRaw(int detid,int modid){
  // MADC ---- Ge         -----
  if(detid==6)
    {
      //		    cout<<seg->GetNumData()<<endl;
      for(int j=0;j<seg->GetNumData();j++)
	{
	  //get rawdata
	  TArtRawDataObject	*d   = seg->GetData(j);	
	  // int geo		     = d->GetGeo(); 
	  // int 	ch	     = d->GetCh();
	  int	 		 val = d->GetVal();
	  madc			     = val;
	  //cout<<" Val : "<<val<<" Ch  :"<<ch<<" neve  "<<neve<<endl;			      			
	}
    }
  // MADC ---- Ge         -----
  
  // QDC ---- LIQUID1 -----		
  if(detid==40)
    {			  		  
      //cout<<seg->GetNumData()<<endl;
      for(int j=0;j<seg->GetNumData();j++)
	{
	  TArtRawDataObject	*d = seg->GetData(j);	//get rawdata	  
	  //int geo       = d->GetGeo(); 
	  int	ch	  = d->GetCh();
	  int	val	  = d->GetVal();
	  //cout<<" Val : "<<val<<" Ch  :"<<ch<<" neve  "<<neve<<endl;			      			
	  if(val<4096)
		    {
		      switch(ch)
			{
			case 0:
			  qdc0 = val;		      			  
			  break;
			case 1:
			  qdc1 = val;		      			  
			  break;
			case 2:
			  qdc2 = val;		      			  
			  break;
			case 3:
			  qdc3 = val;		      			  
			  break;
			case 4:
			  qdc4 = val;		      			  
			  break;
			case 5:
			  qdc5 = val;		      			  
				break;
			case 6:
			  qdc6 = val;		      			  
			  break;
			case 7:
			  qdc7 = val;		      			  
			  break;			 		       		      
			default:
			  break;
			}		  
		    }
		}
	    }
	  
	  // TDC ---- ALL DETECTOR -----		
	  if(detid==3)
	    {
	      
	      for(int j=0;j<seg->GetNumData();j++)
		{
		  TArtRawDataObject    *d = seg->GetData(j);	//get rawdata		  
		  //int geo               = d->GetGeo(); 
		  int	ch		  = d->GetCh();
		  int	val		  = d->GetVal();
		  // cout<<" Val : "<<val<<" Ch  :"<<ch<<" neve  "<<neve<<endl;			      
		  
		  if(val<40000)
		    {
		      switch(ch)
			{
			case 0:
			  tdc0 = val;		      			  
			  break;
			case 1:
			  tdc1 = val;		      			  
			  break;
			case 2:
			  tdc2 = val;		      			  
			  break;
			case 3:
			  tdc3 = val;		      			  
			  break;
			case 4:
			  tdc4 = val;		      			  
			  break;
			case 5:
			  tdc5 = val;		      			  
			  break;
			case 6:
			  tdc6 = val;		      			  
			  break;
			case 7:
			  tdc7 = val;		      			  
			  break;			 		       		      
			case 8:
			  tdc8 = val;		      			  
			  break;
			case 9:
			  tdc9 = val;		      			  
			  break;			 		       		      
			default:
			  break;
			}		  
		    }
		  
		}
	    }
	  
	  // LUPO ---- TIME STAMP -----
	  if(detid==60)
	    {			  
	      for(int j=0;j<seg->GetNumData();j++)
		{
		  TArtRawDataObject	*d = seg->GetData(j);	//get rawdata
		  
		  //int geo	      = d->GetGeo(); 
		  int		ch    = d->GetCh();
		  unsigned int	valts = d->GetVal();	   
		  if(ch==0) ts0		      = valts;
		  if(ch==1){
		    ts1		      = valts;		    
		    // hts->Fill(0);
		  }		      
		}
	      
	    }
	  // LUPO ---- TIME STAMP -----
	  
}

// INITIALIZE     
void r2root::Clear(){
   qdc0	= 0;qdc1=0;qdc2=0;qdc3=0;qdc4=0;qdc5=0;qdc6=0;qdc7=0;
   tdc0	= 0;tdc1=0;tdc2=0;tdc3=0;tdc4=0;tdc5=0;tdc6=0;tdc7=0;tdc8=0;tdc9=0;
   madc	= 0;			//MADC
   ts0	= 0;ts1=0;		//FOR CAGRA 
   neve	= 0;

}
// INITIALIZER     

Bool_t r2root::BranchTree(TTree *daq)
{
  if(daq==NULL) return 0;
  daq->Branch("neve",&neve,"neve/L");

  daq->Branch("ts0",&ts0,"ts0/L");
  daq->Branch("ts1",&ts1,"ts1/L");
  
  daq->Branch("qdc0",&qdc0,"qdc0/I");	// liquid1f
  daq->Branch("qdc1",&qdc1,"qdc1/I");	// 
  daq->Branch("qdc2",&qdc2,"qdc2/I");	// 
  daq->Branch("qdc3",&qdc3,"qdc3/I");	// liquid1s
  daq->Branch("qdc4",&qdc4,"qdc4/I");	// liquid2f
  daq->Branch("qdc5",&qdc5,"qdc5/I");	// 
  daq->Branch("qdc6",&qdc6,"qdc6/I");	//
  daq->Branch("qdc7",&qdc7,"qdc7/I");	// liquid2s
  
  daq->Branch("madc",&madc,"madc/I");	//  Ge
  
  daq->Branch("tdc0",&tdc0,"tdc0/I");
  daq->Branch("tdc1",&tdc1,"tdc1/I"); 
  daq->Branch("tdc2",&tdc2,"tdc2/I");
  daq->Branch("tdc3",&tdc3,"tdc3/I");
  daq->Branch("tdc4",&tdc4,"tdc4/I");
  daq->Branch("tdc5",&tdc5,"tdc5/I");
  daq->Branch("tdc6",&tdc6,"tdc6/I"); 
  daq->Branch("tdc7",&tdc7,"tdc7/I"); 
  daq->Branch("tdc8",&tdc8,"tdc8/I"); 
  daq->Branch("tdc9",&tdc9,"tdc9/I"); 

  return 1;
}
