#include "TENUnpack.h"

TENUnpack::TENUnpack(){
  nevt   = 0;
  estore = new TArtEventStore(); 
}

TENUnpack::~TENUnpack()
{}

bool TENUnpack::Open(const char *filename)
{
   if(estore==0) estore	= new TArtEventStore();
   bool flag		= 0;
   flag			= estore->Open(filename);
   rawevent		= estore->GetRawEventObject();
   return flag;
}
