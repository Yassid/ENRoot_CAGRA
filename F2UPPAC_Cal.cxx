#include "F2UPPAC_Cal.h"

F2UPPAC_Cal::F2UPPAC_Cal(){}
F2UPPAC_Cal::~F2UPPAC_Cal(){}

void   F2UPPAC_Cal::SetPosition(int Left,int Right,int Down,int Up){
  F2U_XLParam_ns = 0.09765805 ;	 
  F2U_XRParam_ns = 0.09765732 ;	 
  F2U_YDParam_ns = 0.09765736 ;	 
  F2U_YUParam_ns = 0.09765785 ;

  F2UPPAC_Xns = F2U_XLParam_ns*Left-F2U_XRParam_ns*Right;
  F2UPPAC_Yns = F2U_YDParam_ns*Down-F2U_YUParam_ns*Up   ;
  F2UPPAC_Xmm = F2U_XLParam_ns*Left-F2U_XRParam_ns*Right;
  F2UPPAC_Ymm = F2U_YDParam_ns*Down-F2U_YUParam_ns*Up   ;
  
}

double F2UPPAC_Cal::GetX_Time(){
  return F2UPPAC_Xns;
}

double F2UPPAC_Cal::GetY_Time(){
  return F2UPPAC_Yns;
}

double F2UPPAC_Cal::GetX_Position(){
  return F2UPPAC_Xmm;
}

double F2UPPAC_Cal::GetY_Position(){
  return F2UPPAC_Ymm;
}

