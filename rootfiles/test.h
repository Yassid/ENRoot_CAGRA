//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  2 11:12:19 2014 by ROOT version 5.34/07
// from TTree ENrawtree/ENrawtree
// found on file: e372_run0041.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           ENrawevt;
   Int_t           ENvme_v792_1[32];
   Int_t           ENvme_v792_2[32];
   Int_t           ENvme_madc[32];
   Int_t           ENvme_v1190_1[128][10];
   Int_t           ENvme_v1190_2[128][10];
   Int_t           ENvme_ts[2];

   // List of branches
   TBranch        *b_ENrawevt;   //!
   TBranch        *b_ENvme_v792_1;   //!
   TBranch        *b_ENvme_v792_2;   //!
   TBranch        *b_ENvme_madc;   //!
   TBranch        *b_ENvme_v1190_1;   //!
   TBranch        *b_ENvme_v1190_2;   //!
   TBranch        *b_ENvme_ts;   //!

   test(TTree *tree=0);
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef test_cxx
test::test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("e372_run0041.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("e372_run0041.root");
      }
      f->GetObject("ENrawtree",tree);

   }
   Init(tree);
}

test::~test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void test::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ENrawevt", &ENrawevt, &b_ENrawevt);
   fChain->SetBranchAddress("ENvme_v792_1", ENvme_v792_1, &b_ENvme_v792_1);
   fChain->SetBranchAddress("ENvme_v792_2", ENvme_v792_2, &b_ENvme_v792_2);
   fChain->SetBranchAddress("ENvme_madc", ENvme_madc, &b_ENvme_madc);
   fChain->SetBranchAddress("ENvme_v1190_1", ENvme_v1190_1, &b_ENvme_v1190_1);
   fChain->SetBranchAddress("ENvme_v1190_2", ENvme_v1190_2, &b_ENvme_v1190_2);
   fChain->SetBranchAddress("ENvme_ts", ENvme_ts, &b_ENvme_ts);
   Notify();
}

Bool_t test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef test_cxx
