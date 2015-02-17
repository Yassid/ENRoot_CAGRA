void set_F2Par()
{
   TArtF2Param *fp = (TArtF2Param*) go4->GetParameter("F2Param","TArtF2Param");
   if(fp==0) return;

   // set values here-----------
   fp->frP1    = 200;
   fp->frP2    = 200;
   fp->fbHisto = kTRUE;

   fp->fArr.Set(4);
   fp->fArr[0] = 34;
   fp->fArr[1] = 2345;
   fp->fArr[2] = 3456;
   fp->fArr[3] = 4567;
   // F2U PPAC
       fp->fF2UPPAC_ch2ns_XL = 0.09765805 ;	 
       fp->fF2UPPAC_ch2ns_XR = 0.09765732 ;	 
       fp->fF2UPPAC_ch2ns_YD = 0.09765736 ;	 
       fp->fF2UPPAC_ch2ns_YU = 0.09765785 ;

       fp->fF2UPPAC_ns2mm_X = 0.63419;	 
       fp->fF2UPPAC_ns2mm_Y = 0.62479;	 

       fp->fF2UPPAC_inoffset_X = -2.8068;	 
       fp->fF2UPPAC_inoffset_Y = 0.63758;

       fp->fF2UPPAC_outoffset_X = -0.1521;	 
       fp->fF2UPPAC_outoffset_Y = 1.55;

       fp->fF2UPPAC_geomoffset_X = 0;	 
       fp->fF2UPPAC_geomoffset_Y = 0;

       fp->fF2UPPAC_offset_X = fp->fF2UPPAC_inoffset_X + fp->fF2UPPAC_outoffset_X + fp->fF2UPPAC_geomoffset_X;	 
       fp->fF2UPPAC_offset_Y = fp->fF2UPPAC_inoffset_Y + fp->fF2UPPAC_outoffset_Y + fp->fF2UPPAC_geomoffset_Y;
  // F2D PPAC
       fp->fF2DPPAC_ch2ns_XL = 0.09765771;	 
       fp->fF2DPPAC_ch2ns_XR = 0.09765819;	 
       fp->fF2DPPAC_ch2ns_YD = 0.09765804;	 
       fp->fF2DPPAC_ch2ns_YU = 0.09765901;

       fp->fF2DPPAC_ns2mm_X = 0.62691;	 
       fp->fF2DPPAC_ns2mm_Y = 0.62147;	 

       fp->fF2DPPAC_inoffset_X = 0.36249;	 
       fp->fF2DPPAC_inoffset_Y = 0.41813;

       fp->fF2DPPAC_outoffset_X = -0.4831;	 
       fp->fF2DPPAC_outoffset_Y = 0.63034;
       fp->fF2DPPAC_geomoffset_X = 0;	 
       fp->fF2DPPAC_geomoffset_Y = 0;  
     
       fp->fF2DPPAC_offset_X = fp->fF2DPPAC_inoffset_X + fp->fF2DPPAC_outoffset_X + fp->fF2DPPAC_geomoffset_X;	 
       fp->fF2DPPAC_offset_Y = fp->fF2DPPAC_inoffset_Y + fp->fF2DPPAC_outoffset_Y + fp->fF2DPPAC_geomoffset_Y;




   //   TETSUYA CHANGE 20140529
   //   fp->fF2UPPAC_e390_offset[0]= -1.7438+3.93 - 1.64; //f2U X
   //   fp->fF2UPPAC_e390_offset[1]= 0.5954;//f2U Y
   
   //   fp->fF2DPPAC_e390_offset[0]= -1.3177 + 4.635 -3.68; //f2D X
   //   fp->fF2DPPAC_e390_offset[1]= -0.38158;//f2D Y
   
   fp->zpos[0]= 0; // F2 Upstream PPAC
   fp->zpos[1]= 482; // F2 Downstream PPAC
   fp->zpos[2]= 88; // F2 Plastic Scintillator 
   fp->zpos[3]= 630;  //F2 Gate valve
   fp->zpos[4]= 755;  // F2 Viewer
   fp->zpos[5]= 1059; // F2 Entrance of Scattering chamber
   fp->zpos[6]= 1619; // F2 Target position
   fp->zpos[7]= 2179; //  F2 Scattering chambe
}
