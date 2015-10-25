
#include "TSiLi.h"

ClassImp(TSiLi)

TSiLi::TSiLi() : data(0)  {  }

TSiLi::~TSiLi()  {
  if(data) delete data;   
}

void TSiLi::Clear(Option_t *opt)  {
  if(data) data->Clear();
  sili_hits.clear();
}

void TSiLi::Print(Option_t *opt) const  {  
  printf("===============\n");
  printf("not yet written\n");
  printf("===============\n");
}

void TSiLi::FillData(TFragment *frag,TChannel *chan, MNEMONIC *mnem) {
  if(!data) data = new TSiLiData();
  data->SetSiLi(frag,chan,mnem);
}


void TSiLi::BuildHits(TDetectorData *data,Option_t *opt)  {
  TSiLiData *sdata = (TSiLiData*)data;
  if(!sdata)
    sdata = this->data;
  if(!sdata)
    return;

  TSiLiHit hit;

  for(UInt_t i=0;i<sdata->GetMultiplicity();i++)     { 
	  hit.SetSegment(sdata->GetSegment(i));
     TVector3 tmppos = GetPosition(hit.GetSegment());
     hit.SetPosition(tmppos);
     TFragment tmp = sdata->GetFragment(i);
     hit.SetVariables(tmp);
     hit.SetWavefit(tmp);
  
     sili_hits.push_back(hit);
  }

}

TVector3 TSiLi::GetPosition(int seg)  {
  TVector3 position;
  position.SetXYZ(0,0,-1);
  return position;
}

TSiLiHit * TSiLi::GetSiLiHit(const int& i)   {  
   try{
      return &sili_hits.at(i);   
   }
   catch (const std::out_of_range& oor){
      std::cerr << ClassName() << " is out of range: " << oor.what() << std::endl;
      throw grsi::exit_exception(1);
   }
   return 0;
}  
