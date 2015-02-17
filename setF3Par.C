void set_F3Par()
{
   TArtF3Param *fp = (TArtF3Param*) go4->GetParameter("F3Param","TArtF3Param");
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
       fp->fF3UPPAC_ch2ns_XL = 0.09765805;	 
       fp->fF3UPPAC_ch2ns_XR = 0.09765732 ;	 
       fp->fF3UPPAC_ch2ns_YD = 0.09765736 ;	 
       fp->fF3UPPAC_ch2ns_YU = 0.09765785 ;

       fp->fF3UPPAC_ns2mm_X = 0.63419;	 
       fp->fF3UPPAC_ns2mm_Y = 0.62479;	 

       fp->fF3UPPAC_inoffset_X = -2.8068;	 
       fp->fF3UPPAC_inoffset_Y = 0.63758;

       fp->fF3UPPAC_outoffset_X = 0;	 
       fp->fF3UPPAC_outoffset_Y = 0;

       fp->fF3UPPAC_geomoffset_X = 0;	 
       fp->fF3UPPAC_geomoffset_Y = 0;

       fp->fF3UPPAC_offset_X = fp->fF3UPPAC_inoffset_X + fp->fF3UPPAC_outoffset_X + fp->fF3UPPAC_geomoffset_X;	 
       fp->fF3UPPAC_offset_Y = fp->fF3UPPAC_inoffset_Y + fp->fF3UPPAC_outoffset_Y + fp->fF3UPPAC_geomoffset_Y;
  // F2D PPAC
       fp->fF3DPPAC_ch2ns_XL = 0.09765771;	 
       fp->fF3DPPAC_ch2ns_XR = 0.09765819;	 
       fp->fF3DPPAC_ch2ns_YD = 0.09765804;	 
       fp->fF3DPPAC_ch2ns_YU = 0.09765901;

       fp->fF3DPPAC_ns2mm_X = 0.62691;	 
       fp->fF3DPPAC_ns2mm_Y = 0.62147;	 

       fp->fF3DPPAC_inoffset_X = 0.36249;	 
       fp->fF3DPPAC_inoffset_Y = 0.41813;

       fp->fF3DPPAC_outoffset_X = 0;	 
       fp->fF3DPPAC_outoffset_Y = 0;
       fp->fF3DPPAC_geomoffset_X = 0;	 
       fp->fF3DPPAC_geomoffset_Y = 0;  
     
       fp->fF3DPPAC_offset_X = fp->fF3DPPAC_inoffset_X + fp->fF3DPPAC_outoffset_X + fp->fF3DPPAC_geomoffset_X;	 
       fp->fF3DPPAC_offset_Y = fp->fF3DPPAC_inoffset_Y + fp->fF3DPPAC_outoffset_Y + fp->fF3DPPAC_geomoffset_Y;
   
   fp->zpos[0]= 0.; // F3 Upstream PPAC
   fp->zpos[1]= 500.; // F3 Downstream PPAC
   fp->zpos[2]= 850;   // F3 Veto  
   fp->zpos[3]= 910;  //F3 Triger
   fp->zpos[4]= 956;  // F3 Target
   fp->zpos[5]= 1031; // F3 Entrance MS chamber
   fp->zpos[6]= 1601; // F3 Exit MS
   fp->zpos[7]= 1606]; //  NaI
   fp->zpos[8]= 5459; // Hodoscope
}
