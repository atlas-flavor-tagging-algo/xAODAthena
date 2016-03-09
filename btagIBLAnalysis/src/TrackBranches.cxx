#include "TrackBranches.hh"
#include "TrackBranchBuffer.hh"


#include "xAODTracking/TrackParticle.h"
#include "TTree.h"

#include <string>

TrackBranches::TrackBranches():
  m_branches(new TrackBranchBuffer)
{
  m_branches->dummy = new std::vector<std::vector<float> >;
}

TrackBranches::~TrackBranches()
{
  delete m_branches->dummy;

  delete m_branches;
}

void TrackBranches::set_tree(TTree& output_tree,
                             const std::string& prefix) const {
#define ADD_SIMPLE(nm) \
  output_tree.Branch((prefix + #nm).c_str(), &m_branches->nm)
  // basic kinematics
  ADD_SIMPLE(dummy);
#undef ADD_SIMPLE
}

void TrackBranches::fill(const TrackBranches::Tracks& tracks) {
  std::vector<float> dummy;

  for (const auto* track: tracks) {
    dummy.push_back(track->pt());
  }
  m_branches->dummy->push_back(std::move(dummy));
}

void TrackBranches::clear() {
  m_branches->dummy->clear();
}
