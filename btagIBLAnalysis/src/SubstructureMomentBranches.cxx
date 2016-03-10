#include "SubstructureMomentBranches.hh"
#include "SubstructureMomentBranchBuffer.hh"

#include "xAODJet/Jet.h"
#include "AthContainers/exceptions.h"
#include "TTree.h"

#include <string>
#include <stdexcept>

SubstructureMomentBranches::SubstructureMomentBranches():
  m_branches(new SubstructureMomentBranchBuffer)
{
  m_branches->Tau21 = new std::vector<float>;
  m_branches->C1 = new std::vector<float>;
  m_branches->C2 = new std::vector<float>;
  m_branches->C1_Beta2 = new std::vector<float>;
  m_branches->C2_Beta2 = new std::vector<float>;
  m_branches->D2 = new std::vector<float>;
  m_branches->D2_Beta2 = new std::vector<float>;
}

SubstructureMomentBranches::~SubstructureMomentBranches()
{
  delete m_branches->Tau21;
  delete m_branches->C1;
  delete m_branches->C2;
  delete m_branches->C1_Beta2;
  delete m_branches->C2_Beta2;
  delete m_branches->D2;
  delete m_branches->D2_Beta2;

  delete m_branches;
}

void SubstructureMomentBranches::set_tree(TTree& output_tree) const {
  std::string prefix = "jet_substructure_moment_";
#define ADD_SIMPLE(nm) \
  output_tree.Branch((prefix + #nm).c_str(), &m_branches->nm)
  // basic kinematics
  ADD_SIMPLE(Tau21);
  ADD_SIMPLE(C1);
  ADD_SIMPLE(C2);
  ADD_SIMPLE(C1_Beta2);
  ADD_SIMPLE(C2_Beta2);
  ADD_SIMPLE(D2);
  ADD_SIMPLE(D2_Beta2);
#undef ADD_SIMPLE
}

void SubstructureMomentBranches::fill(const xAOD::Jet& jet) {
  try {
#define PUSH_FLOAT(nm) m_branches->nm->push_back(jet.auxdata<float>(#nm))
    PUSH_FLOAT(Tau21);
    PUSH_FLOAT(C1);
    PUSH_FLOAT(C2);
    PUSH_FLOAT(C1_Beta2);
    PUSH_FLOAT(C2_Beta2);
    PUSH_FLOAT(D2);
    PUSH_FLOAT(D2_Beta2);
#undef PUSH_BACK
  } catch (SG::ExcBadAuxVar& exc) {
    std::string problem = "Error filling branches in " __FILE__ " ";
    problem.append(exc.what());
    throw std::runtime_error(problem);
  }
}

void SubstructureMomentBranches::clear() {
  m_branches->Tau21->clear();
  m_branches->C1->clear();
  m_branches->C2->clear();
  m_branches->C1_Beta2->clear();
  m_branches->C2_Beta2->clear();
  m_branches->D2->clear();
  m_branches->D2_Beta2->clear();
}
