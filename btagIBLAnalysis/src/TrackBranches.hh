#ifndef TRACK_BRANCHES_HH
#define TRACK_BRANCHES_HH

class TTree;

#include "xAODTracking/TrackParticle.h"
#include "xAODTracking/TrackParticleContainer.h"

// namespace xAOD {
//   class TrackParticleContainer;
// }

#include <vector>
#include <string>

// branch buffers are stored as an external class to cut down on
// (re)compile time
struct TrackBranchBuffer;

class TrackBranches
{
public:
  typedef std::vector<ElementLink<xAOD::TrackParticleContainer > > Tracks;
  // might want to add a prefix to the constructor for the tree branches
  TrackBranches();
  ~TrackBranches();

  // disable copying and assignment
  TrackBranches& operator=(TrackBranches) = delete;
  TrackBranches(const TrackBranches&) = delete;

  void set_tree(TTree& output_tree, const std::string& prefix) const;
  void fill(const Tracks& tracks);
  void clear();
private:
  TrackBranchBuffer* m_branches;
};

#endif // TRACK_BRANCHES_HH
