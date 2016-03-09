#ifndef TRACK_BRANCH_BUFFER_HH
#define TRACK_BRANCH_BUFFER_HH

#include <vector>
#include <map>
#include <utility>

struct TrackBranchBuffer {
  // map of covariance branches
  std::map< std::pair<int, int>,  std::vector<std::vector<float> >*> cov;
};

#endif
