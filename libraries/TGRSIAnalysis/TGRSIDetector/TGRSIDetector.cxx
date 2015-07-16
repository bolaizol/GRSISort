

#include "TGRSIDetector.h"
#include "TGRSIDetectorHit.h"
#include <TClass.h>

ClassImp(TGRSIDetector)

////////////////////////////////////////////////////////////////
//                                                            //
// TGRSIDetector                                              //
//                                                            //
// This is an abstract class that contains the basic info     //
// about a detector. This is where the hits are built and
// the data is filled.
//                                                            //
////////////////////////////////////////////////////////////////

TGRSIDetector::TGRSIDetector():TObject(){
   //Default constructor.
#if MAJOR_ROOT_VERSION < 6
   Class()->IgnoreTObjectStreamer(kTRUE);
#endif
}

TGRSIDetector::TGRSIDetector(const TGRSIDetector& rhs) {
   //Default Copy constructor.
  //Class()->IgnoreTObjectStreamer(kTRUE);
   ((TGRSIDetector&)rhs).Copy(*this);
}

TGRSIDetector::~TGRSIDetector()	{
//Default Destructor.
}


void TGRSIDetector::AddHit(TGRSIDetectorHit *hit,Option_t *opt) {
   // hit->SetParent(this); 
  PushBackHit(hit);
  return;
}

void TGRSIDetector::Copy(TGRSIDetector &rhs) const {
   TObject::Copy((TObject&)rhs);
}

void TGRSIDetector::Print(Option_t *opt) const {
// Default print statement for TGRSIDetector. Currently does
// nothing
}

void TGRSIDetector::Clear(Option_t *opt) {
// Default clear statement for TGRSIDetector. Currently does
// nothing
}



