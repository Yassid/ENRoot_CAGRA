 /******************************************************************
 ***                     ENRoot                                 ***
 ***  Dedicated framework to analyze RCNP EN Course Experiments ***
 ***  Developers: Y. Ayyad (yassid.ayyad@rcnp.osaka-u.ac.jp)    ***
 ***              T. Yamamoto (tetsuya@rcnp.osaka-u.ac.jp)      ***
 ******************************************************************/


#include "TENUnpack.h"
#include "TENPPAC_Sort.h"
#include "TENScint_Sort.h"
#include "TENNaI_Sort.h"
#include "TENSSD_Sort.h"
#include "TENIonChamb_Sort.h"
#include "TENTS_Sort.h"
#include "TENTrig_Sort.h"
#include "TENSort.h"
#include "F2UPPAC_Cal.h"

#include <vector>
#include "TROOT.h"


#ifdef __MAKECINT__
#pragma link C++ class vector<int>+;
#endif

using namespace std;

int main(int argc, char **argv)
{
  
  gSystem->AddIncludePath("-I$TARTSYS/include/");
  gSystem->Load("libanacore.so");
  gSystem->Load("TENUnpack_cxx.so");
  gSystem->Load("ENMain_cxx.so");
  
  gROOT->ProcessLine(".L ENMain.cxx+");  
  
  std::stringstream  fins;    // OUTPUT STRINGSTREAM 
  std::stringstream  fouts;   // INPUT  STRINGSTREAM 
  cout<<argc<<endl;
  
  if(argc==2){
    fins<<argv[1];
    fouts<<argv[1];
  }
  
  else if(argc==3){
    fins<<argv[1];
    fouts<<argv[2];
  }
  
  else {
    cout<<argc<<endl;
    cout<<"!!!!!!!!!!!!   Input parameters are wrong    !!!!!!!!!!!!!!"<<endl;
    cout<<"If you use same name of input file and output file."<<endl;
    cout<<"    ex) ./ENMain inputfilename [ENTER]"<<endl;
    cout<<"If you change ..."<<endl;
    cout<<"    ex) ./ENMain inputfilename  outputfilename [ENTER]"<<endl;
    return -1;
  }
  
  TString	rawpath	 = "ridffiles/";  
  TString	rootpath = "rootfiles/";
  TString       ridfext  = ".ridf";
  TString       rootext  = ".root"; 
  string        ridffilename;  
  string        rootfilename;    
  ridffilename = rawpath + fins.str() + ridfext;
  rootfilename = rootpath + fouts.str() + rootext;  

  char	*ridffile		= new char[ridffilename.size()+1];
  ridffile[ridffilename.size()]	= 0;
  memcpy(ridffile,ridffilename.c_str(),ridffilename.size());
  
  cout<<"ENRoot Analyzing data file: "<<ridffilename.c_str()<<endl;
 
  gSystem->Load("libXMLParser.so");
  
  // PREPARE INPUT FILE NAME   
  TFile		*file	   = new TFile(rootfilename.c_str(),"RECREATE");  
  TENUnpack     *unpack	   = new TENUnpack();
  unpack->LoadRIDFParameters("./xml/ENRIDF.xml");

  TTree		*ENrawtree = new TTree("ENrawtree","ENrawtree");	
  unpack->Open(ridffilename.c_str());  
  unpack->ENUnpackVME(ENrawtree);
  ENrawtree->Write();

/*  TTree *ENsorttree = new TTree("ENsorttree","ENsorttree");  
  TENSort        *ensort        = new TENSort();
  ensort->GetENSortTree(ENrawtree,ENsorttree);    
  ENsorttree->Write();*/  
  

  /***********  CALIBRATION LOOP  **************/
  /*
    TTree		*ENcaltree = new TTree("ENcaltree","ENcaltree"); 
    int		 nEvent		   = ENsorttree->GetEntries();
    F2UPPAC_Cal	*f2uppac	   = new F2UPPAC_Cal;
    double	 f2uppac_xns,f2uppac_yns;
    double	 f2uppac_xmm,f2uppac_ymm;
    ENcaltree->Branch("f2uppac_xns",&f2uppac_xns,"f2uppac_xns/D");
    ENcaltree->Branch("f2uppac_yns",&f2uppac_yns,"f2uppac_yns/D");
  
    cout<<"Calibration Start : Total Event Number is : "<<nEvent<<endl;
    
    for(int i =1;i<nEvent;i++){
    ENsorttree->GetEntry(i);
    f2uppac->SetPosition(1,2,3,4);
    f2uppac_xns = f2uppac->GetX_Time();
    f2uppac_yns = f2uppac->GetY_Time();
    f2uppac_xmm = f2uppac->GetX_Position();
    f2uppac_ymm = f2uppac->GetY_Position();
    ENcaltree->Fill();        
    }  

    ENcaltree->Write();

    // delete unpack;
    // delete enppac;  
    // delete ennai;  
    // delete enssd;  
    // delete enion;  
    // delete enpla;  
    // delete ents;
    */
  /***********  CALIBRATION LOOP  **************/    

  file->Close();

  return 0;

}
