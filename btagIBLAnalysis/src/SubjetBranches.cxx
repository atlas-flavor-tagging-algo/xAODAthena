#include "SubjetBranches.hh"
#include "SubjetBranchBuffer.hh"

#include "xAODJet/Jet.h"
#include "TTree.h"

#include <string>

SubjetBranches::SubjetBranches():
  m_branches(new SubjetBranchBuffer)
{
  m_branches->pt = new std::vector<std::vector<float> >;
  m_branches->eta = new std::vector<std::vector<float> >;
  m_branches->phi = new std::vector<std::vector<float> >;
  m_branches->mass = new std::vector<std::vector<float> >;

  m_branches->ntrk = new std::vector<std::vector<int> >;
  m_branches->mv2c20 = new std::vector<std::vector<float> >;
}

SubjetBranches::~SubjetBranches()
{
  delete m_branches->pt;
  delete m_branches->eta;
  delete m_branches->phi;
  delete m_branches->mass;

  delete m_branches->ntrk;
  delete m_branches->mv2c20;

  delete m_branches;
}

void SubjetBranches::set_tree(TTree& output_tree,
                              const std::string& prefix) const {
#define ADD_SIMPLE(nm) \
  output_tree.Branch((prefix + #nm).c_str(), &m_branches->nm)
  // basic kinematics
  ADD_SIMPLE(pt);
  ADD_SIMPLE(eta);
  ADD_SIMPLE(phi);
  ADD_SIMPLE(mass);

  ADD_SIMPLE(ntrk);
  ADD_SIMPLE(mv2c20);
#undef ADD_SIMPLE
}

void SubjetBranches::fill(const std::vector<const xAOD::Jet*>& subjets) {
  std::vector<float> pt;
  std::vector<float> eta;
  std::vector<float> phi;
  std::vector<float> mass;
  std::vector<int> ntrk;
  std::vector<float> mv2c20;

  for (const auto* jet: subjets) {
    pt.push_back(jet->pt());
    eta.push_back(jet->eta());
    phi.push_back(jet->phi());
    mass.push_back(jet->m());
    ntrk.push_back(jet->numConstituents());
    const xAOD::BTagging *btag = jet->btagging();
    mv2c20.push_back(btag->auxdata<double>("MV2c20_discriminant"));
  }
#define PUSH(var) m_branches->var->push_back(std::move(var))
  PUSH(pt);
  PUSH(eta);
  PUSH(phi);
  PUSH(mass);
  PUSH(ntrk);
  PUSH(mv2c20);
#undef PUSH
}

void SubjetBranches::clear() {
  m_branches->pt->clear();
  m_branches->eta->clear();
  m_branches->phi->clear();
  m_branches->mass->clear();

  m_branches->ntrk->clear();
  m_branches->mv2c20->clear();
}
