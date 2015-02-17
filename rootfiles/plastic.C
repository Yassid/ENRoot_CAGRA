void plastic()
{
  TCanvas *raw = new TCanvas("raw","raw",1200,1200);
  raw->Divide(3,3);
  raw->cd(1);
  ENrawtree->Draw("ENvme_v792_1[0]");
  raw->cd(2);
  ENrawtree->Draw("ENvme_v792_1[1]");
  raw->cd(3);
  ENrawtree->Draw("ENvme_v792_1[2]");
  raw->cd(4);
  ENrawtree->Draw("ENvme_v1190_1[13][0]");
  raw->cd(5);
  ENrawtree->Draw("ENvme_v1190_1[26][0]");
  raw->cd(6);
  ENrawtree->Draw("ENvme_v1190_1[28][0]");
  

  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->Divide(3,3);
  sort->cd(1);
  ENsorttree->Draw("F2Plastic_Q");
  sort->cd(2);
  ENsorttree->Draw("F3Plastic_LQ");
  sort->cd(3);
  ENsorttree->Draw("F3Plastic_RQ");
  sort->cd(4);
  ENsorttree->Draw("F2Plastic_T");
  sort->cd(5);
  ENsorttree->Draw("F3Plastic_LT");
  sort->cd(6);
  ENsorttree->Draw("F3Plastic_RT");

}
