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

int main(int argc, char **argv)
{
  stringstream	ss;
  int		runnum;
  int		maxnevt	= 0;

  if(argc==2)
  {
    ss<<argv[1];
    runnum = atoi(argv[1]);
  }
  else if(argc==3)
  {
    ss<<argv[1];
    runnum  = atoi(argv[1]);
    maxnevt = atoi(argv[2]);
  }
  else {
    cout<<"USAGE: ./convert Run-Number"<<endl;
    cout<<"USAGE: ./convert Run-Number Max-Event-Number"<<endl;
    return -1;
  }
  
  cout<<"Run-Number"<<runnum<<endl;
  
  TString	rootpath = "./rootfile/";
  TString	rawpath	 = "./ridffile/";

  char		filename[36];
  
  // PREPARE INPUT FILE NAME 
  
  //  sprintf(filename,"CAGRA_%04d.ridf",runnum); // change
  sprintf(filename,"CAGRA_%04d.ridf",fiName);
  
  rawpath += filename;  
  cout<<"analyzing data file: "<<filename<<endl;
  
  gSystem->Load("libanacore.so");

  //  sprintf(filename,"%04d.root",runnum); // change -
  sprintf(filename,"%04d.root",foName); 
  rootpath += filename;
  
  TFile *file	 = new TFile(rootpath.Data(),"RECREATE");  

  file->Close();
  return 0;

}

