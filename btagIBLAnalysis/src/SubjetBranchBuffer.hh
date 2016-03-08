#ifndef SUBJET_BRANCH_BUFFER_HH
#define SUBJET_BRANCH_BUFFER_HH

struct SubjetBranchBuffer
{
  std::vector<std::vector<float> >* pt;
  std::vector<std::vector<float> >* eta;
  std::vector<std::vector<float> >* phi;
  std::vector<std::vector<float> >* m;
  std::vector<std::vector<int> >* ntrk;
  std::vector<std::vector<float> >* mv2c20;
};

#endif
