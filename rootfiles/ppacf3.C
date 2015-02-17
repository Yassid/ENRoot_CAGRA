void ppacf3()
{
  TCanvas *raw = new TCanvas("raw","raw",1200,1200);
  raw->Divide(3,3);
  raw->cd(1);
  ENrawtree->Draw("ENvme_v1190_1[16][0]");
  raw->cd(2);
  ENrawtree->Draw("ENvme_v1190_1[17][0]");
  raw->cd(3);
  ENrawtree->Draw("ENvme_v1190_1[18][0]");
  raw->cd(4);
  ENrawtree->Draw("ENvme_v1190_1[19][0]");
  raw->cd(5);
  ENrawtree->Draw("ENvme_v1190_1[20][0]");
  raw->cd(6);
  ENrawtree->Draw("ENvme_v1190_1[21][0]");
  raw->cd(7);
  ENrawtree->Draw("ENvme_v1190_1[22][0]");
  raw->cd(8);
  ENrawtree->Draw("ENvme_v1190_1[23][0]");
  raw->cd(9);
  ENrawtree->Draw("ENvme_v1190_1[24][0]");
  raw->cd(10);
  ENrawtree->Draw("ENvme_v1190_1[25][0]");
  

  
  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->Divide(3,3);
  sort->cd(1);
  ENsorttree->Draw("F3UPPAC[0]");
  sort->cd(2);
  ENsorttree->Draw("F3UPPAC[1]");
  sort->cd(3);
  ENsorttree->Draw("F3UPPAC[2]");
  sort->cd(4);
  ENsorttree->Draw("F3UPPAC[3]");
  sort->cd(5);
  ENsorttree->Draw("F3UPPAC[4]");
  sort->cd(6);
  ENsorttree->Draw("F3DPPAC[0]");
  sort->cd(7);
  ENsorttree->Draw("F3DPPAC[1]");
  sort->cd(8);
  ENsorttree->Draw("F3DPPAC[2]");
  sort->cd(9);
  ENsorttree->Draw("F3DPPAC[3]");
  sort->cd(10);
  ENsorttree->Draw("F3DPPAC[4]");
  
}
