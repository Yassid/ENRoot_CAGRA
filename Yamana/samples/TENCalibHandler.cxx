#include "TENCalibHandler.h"
#include "TENPPAC_Sort.h"
#include "TENPla_Sort.h"
#include "TENNaI_Sort.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


TENCalibHandler::TENCalibHandler(){}
TENCalibHandler::~TENCalibHandler(){}

Bool_t TENCalibHandler::BuildTree(TTree *tree){
  if(tree==NULL)return 0;
  return 1;
  
}
