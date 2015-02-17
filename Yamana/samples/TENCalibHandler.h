#ifndef TENCALIBHANDLER_H
#define TENCALIBHANDLER_H

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

class TENPPAC_Sort;
class TENPla_Sort;
class TENNaI_Sort;

class TENCalibHandler
{
 private:
 public: 
  int ENcalevt;
  
  TENCalibHandler();  
  ~TENCalibHandler();  
  Bool_t BuildTree(TTree *tree);  
};
  
#endif
