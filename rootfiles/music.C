void music()
{
  TCanvas *raw = new TCanvas("raw","raw",1200,1200);
  raw->Divide(3,3);
  raw->cd(1);
  ENrawtree->Draw("ENvme_madc[0]");
  raw->cd(2);
  ENrawtree->Draw("ENvme_madc[1]");
  raw->cd(3);
  ENrawtree->Draw("ENvme_madc[2]");
  raw->cd(4);
  ENrawtree->Draw("ENvme_madc[3]");
  raw->cd(5);
  ENrawtree->Draw("ENvme_madc[4]");
  raw->cd(6);
  ENrawtree->Draw("ENvme_madc[5]");
  raw->cd(7);
  ENrawtree->Draw("ENvme_madc[6]");
  raw->cd(8);
  ENrawtree->Draw("ENvme_madc[7]");

  
  TCanvas *sort = new TCanvas("sort","sort",1600,1200);
  sort->Divide(3,3);
  sort->cd(1);
  ENsorttree->Draw("F3MUSIC_E[0]");
  sort->cd(2);
  ENsorttree->Draw("F3MUSIC_E[1]");
  sort->cd(3);
  ENsorttree->Draw("F3MUSIC_E[2]");
  sort->cd(4);
  ENsorttree->Draw("F3MUSIC_E[3]");
  sort->cd(5);
  ENsorttree->Draw("F3MUSIC_E[4]");
  sort->cd(6);
  ENsorttree->Draw("F3MUSIC_E[5]");
  sort->cd(7);
  ENsorttree->Draw("F3MUSIC_E[6]");
  sort->cd(8);
  ENsorttree->Draw("F3MUSIC_E[7]");  
}
