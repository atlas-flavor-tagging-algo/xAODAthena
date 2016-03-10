#ifndef SUBSTRUCTUREMOMENT_BRANCH_BUFFER_HH
#define SUBSTRUCTUREMOMENT_BRANCH_BUFFER_HH

#include <vector>

struct SubstructureMomentBranchBuffer {
  std::vector<float>* Tau21;
  std::vector<float>* C1;
  std::vector<float>* C2;
  std::vector<float>* C1_Beta2;
  std::vector<float>* C2_Beta2;
  std::vector<float>* D2;
  std::vector<float>* D2_Beta2;
};

#endif // SUBSTRUCTUREMOMENT_BRANCH_BUFFER_HH
