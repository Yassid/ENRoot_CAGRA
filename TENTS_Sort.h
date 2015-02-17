#ifndef TENTS_SORT_H
#define TENTS_SORT_H

#include <TH1.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TSystem.h>
#include <vector>
#include "TArtEventStore.hh"
#include "segidlist.h"

using namespace std;

class TENTS_Sort{
 private:
 public:
  TENTS_Sort();
  ~TENTS_Sort();
  Bool_t GetENTree(TTree *tree,TTree *sorttree);  
  Bool_t BuildSortTree(TTree *tree);   // TMP FUNCTION
  int ENvme_ts[32];
  
  int TimeStamp;
  int EvNum;

};
#endif
