// /******************************************************************
// /***                     ENRoot                                 ***
// /***  Dedicated framework to analyze RCNP EN Course Experiments ***
// /***  Developers: Y. Ayyad (yassid.ayyad@rcnp.osaka-u.ac.jp)    ***
// /***              T. Yamamoto (tetsuya@rcnp.osaka-u.ac.jp)      ***
// /******************************************************************/


#include "TENUnpackf.h"
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
    cout<<"!!!!!!!!!!!!   Input param is not good   !!!!!!!!!!!!"<<endl;
    cout<<"If you use same name of input file and output file."<<endl;
    cout<<"    ex) ./ENMain inputfilename [ENTER]"<<endl;
    cout<<"If you change ..."<<endl;
    cout<<"    ex) ./ENMain inputfilename  outputfilename [ENTER]"<<endl;
    return -1;
  }
  
  TString	rawpath	 = "../ridffiles/";  
  TString	rootpath = "./";
  //  TString	rootpath = "../rootfiles/";
  TString       ridfext  = ".ridf";
  TString       rootext  = ".root";
  char		filename[36];
  string        ridffilename;  
  string        rootfilename;  
  
  ridffilename = rawpath + fins.str() + ridfext;
  rootfilename = rootpath + fouts.str() + rootext;
  
  char *ridffile = new char[ridffilename.size()+1];
  ridffile[ridffilename.size()]=0;
  memcpy(ridffile,ridffilename.c_str(),ridffilename.size());
  
  //  cout<<"ENRoot Analyzing data file: "<<filename<<endl;
  cout<<"ENRoot Analyzing data file: "<<ridffilename.c_str()<<endl;
  gSystem->Load("libanacore.so");
  gSystem->Load("libXMLParser.so");
  
  // PREPARE INPUT FILE NAME   
  TFile *file	    = new TFile(rootfilename.c_str(),"RECREATE");  
  TENUnpack        *unpack = new TENUnpack();
  TTree *ENrawtree	 = new TTree("ENrawtree","ENrawtree"); // rawdata-tree
  unpack->Open(ridffilename.c_str());  
  unpack->ENUnpackVME(ENrawtree);
  //  unpack->BuildTree(ENrawtree);
  ENrawtree->Write();
  file->Close();
  return 0;

}
