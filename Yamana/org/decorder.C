#include "r2root.h"

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
  
  //  TString	rootpath = "../../rootfiles/";
  //  TString	rawpath	 = "../../ridffiles/";

  TString	rootpath = "../rootfiles/";
  TString	rawpath	 = "../ridffiles/";
  char		filename[36];

  //  sprintf(filename,"e372_run%04d.ridf",runnum);
  sprintf(filename,"CAGRA_%04d.ridf",runnum);
  //  sprintf(filename,"cal_F2%04d.ridf",runnum);
  rawpath += filename;
  
  cout<<"analyzing data file: "<<filename<<endl;
  
  gSystem->Load("libanacore.so");

  //  sprintf(filename,"e372_run%04d.root",runnum);
  sprintf(filename,"CAGRA_%04d.root",runnum);
  rootpath += filename;
  
  TFile *file	 = new TFile(rootpath.Data(),"RECREATE");
  TTree *daq	 = new TTree("daq","daq");
  r2root	*r2r = new r2root();
  r2r->Open(rawpath.Data());

  if(argc==2)   r2r->BuildEvent(daq);
  if(argc==3)   r2r->BuildEvent(daq,maxnevt);
  daq->Write();
  file->Close();
  return 0;

}

