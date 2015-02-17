void ssd()
{
  TCanvas *raw = new TCanvas("raw","raw",1200,1200);
  raw->Divide(1,2);
  raw->cd(1);
  ENrawtree->Draw("ENvme_v792_2[8]");
  raw->cd(2);
  ENrawtree->Draw("ENvme_v792_2[12]");
  
  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->Divide(1,2);
  sort->cd(1);
  ENsorttree->Draw("F2SSD");
  sort->cd(2);
  ENsorttree->Draw("F3SSD");
}
