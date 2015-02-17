#ifndef F2UPPAC_CAL_H
#define F2UPPAC_CAL_H

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

class F2UPPAC_Cal{
 private:
 public:
  F2UPPAC_Cal();
  ~F2UPPAC_Cal();  
  
  void SetPosition(int X,int Y,int L,int R);
  double GetX_Time();
  double GetY_Time();
  double GetX_Position();
  double GetY_Position();

  double F2U_XLParam_ns;
  double F2U_XRParam_ns;
  double F2U_YDParam_ns;
  double F2U_YUParam_ns;

  double F2UPPAC_Xns;  
  double F2UPPAC_Yns;  
  double F2UPPAC_Xmm;  
  double F2UPPAC_Ymm;  
  

};
#endif
