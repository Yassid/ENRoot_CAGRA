/******************************************************************
/***                     ENRoot                                 ***
/***  Dedicated framework to analyze RCNP EN Course Experiments ***
/***  Developers: Y. Ayyad (yassid.ayyad@rcnp.osaka-u.ac.jp)    ***
/***              T. Yamamoto (tetsuya@rcnp.osaka-u.ac.jp)      ***
/******************************************************************/

 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include "Riostream.h"
 #include "TROOT.h"
 #include "TFile.h"
 #include "TTree.h"
 #include "TBranch.h"
 #include "TGraph.h"
 #include "TApplication.h"
 #include "TRint.h"
 #include "TMath.h"
 #include "TAxis.h"
 #include "TH1F.h"
 #include "TH2I.h"
 #include "TH1I.h"
 #include "TCanvas.h"
 #include "TString.h"
 #include <sstream>
 #include <string>


#include "TENUnpack.h"

using namespace std;


int main(int argc, char **argv)
{

  char       *inputfilename;
  char       *outputfilename;  

  char       ridffilename[36];
  char       rootfilename[36];

  if(argc==3){
    //    ss<<argv[1];
    inputfilename  = argv[1];
    outputfilename = argv[2];    
  }
  
  else {
    cout<<"ex) ./ENMain inputfilename outputfilename"<<endl;
    return -1;
  }
  
  //  cout<<"Run-Number"<<runnum<<endl;
  TString	rawpath	 = "./ridffile";  
  TString	rootpath = "./rootfile";
  TString       ridfext  = ".ridf";
  TString       rootext  = ".root";
  char		filename[36];
  
  // PREPARE INPUT FILE NAME 
  
  //  sprintf(filename,"CAGRA_%04d.ridf",runnum); // change
  //  rawpath += filename;  

  cout<<"analyzing data file: "<<filename<<endl;
  gSystem->Load("libanacore.so");
  gSystem->Load("libXMLParser.so");

  //  sprintf(filename,"%04d.root",runnum); // change 
  //  rootpath += filename;
  
  //  TFile *file	 = new TFile(rootpath.Data(),"RECREATE");    
  TFile *file	    = new TFile(outputfilename,"RECREATE");  
  TENUnpack *unpack = new TENUnpack();
 // unpack->Open(outputfilename);

  file->Close();
  return 0;

}

