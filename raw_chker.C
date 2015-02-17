void raw_chker()
{
  TCanvas *raw = new TCanvas("raw","raw",1600,1200);
  raw->divide(4,4);
  raw->cd(1);
  ENrawtree->Draw("ENvme_v792_1");
  raw->cd(2);
  ENrawtree->Draw("ENvme_v792_2");
  raw->cd(3);
  ENrawtree->Draw("ENvme_madc");
  raw->cd(4);
  ENrawtree->Draw("ENvme_v1190_1");
  raw->cd(5);
  ENrawtree->Draw("ENvme_v1190_2");

  
  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->divide(4,4);
  sort->cd(1);
  ENsorttree->Draw("F2UPPAC");
  sort->cd(2);
  ENsorttree->Draw("F2DPPAC");
  sort->cd(3);
  ENsorttree->Draw("F3UPPAC");
  sort->cd(4);
  ENsorttree->Draw("F3DPPAC");
  sort->cd(5);
  ENsorttree->Draw("F3NaI_H");
  sort->cd(6);
  ENsorttree->Draw("F3NaI_L");
  sort->cd(7);
  ENsorttree->Draw("F3MUSIC_E");
  sort->cd(6);
  ENsorttree->Draw("F3MUSIC_T");

}
