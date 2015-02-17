#ifndef TENSORT_H
#define TENSORT_H

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

class TENSort{
 private:
 public:
  TENSort();
  ~TENSort();
   Bool_t GetENSortTree(TTree *rawtree,TTree *sorttree);
   int ENvme_v792_1[32];
   int ENvme_v792_2[32];
   int ENvme_v1190_1[128][10];
   int ENvme_madc[32];

   // 20150205 timestamp checker
   int ENts;
   
};
#endif
