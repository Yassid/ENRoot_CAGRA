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


int ENMain(Char_t *filename)
{
  
  stringstream fname;
  fname<<filename;
  string	rootpath = "./rootfile/"; // For TString friend operator must be constructed Yassid
  string	rawpath	 = "./ridffile/";
  string       ridfext  = ".ridf";
  string       rootext  = ".root";

  string       ridffilename = rawpath  + fname.str() + ridfext;
  string       rootfilename = rootpath + fname.str() + rootext;
  
  char      *ridffile=new char[ridffilename.size()+1];
  ridffile[ridffilename.size()]=0;
  memcpy(ridffile,ridffilename.c_str(),ridffilename.size());

  cout<<"ENROOT : Analyzing data file: "<<ridffilename<<endl;

  gSystem->Load("libanacore.so");  gSystem->Load("libXMLParser.so");
  //gROOT->ProcessLine(".include $TARTSYS/include/");
  

   TFile *file	 = new TFile(rootfilename.c_str(),"RECREATE");
  //TTree *daq	 = new TTree("daq","daq");
  //r2root	*r2r = new r2root();
  //r2r->Open(rawpath.Data());

   //  TArtEventStore *estore = new TArtEventStore();
   //  estore->Open(ridffile);

  //daq->Write();
   file->Close();
  return 0;

}
