void ppacf2()
{
  TCanvas *raw = new TCanvas("raw","raw",1200,1200);
  raw->Divide(3,3);
  raw->cd(1);
  ENrawtree->Draw("ENvme_v1190_1[0][0]");
  raw->cd(2);
  ENrawtree->Draw("ENvme_v1190_1[1][0]");
  raw->cd(3);
  ENrawtree->Draw("ENvme_v1190_1[2][0]");
  raw->cd(4);
  ENrawtree->Draw("ENvme_v1190_1[3][0]");
  raw->cd(5);
  ENrawtree->Draw("ENvme_v1190_1[4][0]");
  raw->cd(6);
  ENrawtree->Draw("ENvme_v1190_1[5][0]");
  raw->cd(7);
  ENrawtree->Draw("ENvme_v1190_1[6][0]");
  raw->cd(8);
  ENrawtree->Draw("ENvme_v1190_1[7][0]");
  raw->cd(9);
  ENrawtree->Draw("ENvme_v1190_1[8][0]");
  raw->cd(10);
  ENrawtree->Draw("ENvme_v1190_1[9][0]");
  

  
  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->Divide(3,3);
  sort->cd(1);
  ENsorttree->Draw("F2UPPAC[0]");
  sort->cd(2);
  ENsorttree->Draw("F2UPPAC[1]");
  sort->cd(3);
  ENsorttree->Draw("F2UPPAC[2]");
  sort->cd(4);
  ENsorttree->Draw("F2UPPAC[3]");
  sort->cd(5);
  ENsorttree->Draw("F2UPPAC[4]");
  sort->cd(6);
  ENsorttree->Draw("F2DPPAC[0]");
  sort->cd(7);
  ENsorttree->Draw("F2DPPAC[1]");
  sort->cd(8);
  ENsorttree->Draw("F2DPPAC[2]");
  sort->cd(9);
  ENsorttree->Draw("F2DPPAC[3]");
  sort->cd(10);
  ENsorttree->Draw("F2DPPAC[4]");
  
}
