# echo "setup btagIBLAnalysis btagIBLAnalysis-00-00-00 in /afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.7.3/CMT/v1r25p20140131
endif
source ${CMTROOT}/mgr/setup.csh
set cmtbtagIBLAnalysistempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtbtagIBLAnalysistempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena  -no_cleanup $* >${cmtbtagIBLAnalysistempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena  -no_cleanup $* >${cmtbtagIBLAnalysistempfile}"
  set cmtsetupstatus=2
  /bin/rm -f ${cmtbtagIBLAnalysistempfile}
  unset cmtbtagIBLAnalysistempfile
  exit $cmtsetupstatus
endif
set cmtsetupstatus=0
source ${cmtbtagIBLAnalysistempfile}
if ( $status != 0 ) then
  set cmtsetupstatus=2
endif
/bin/rm -f ${cmtbtagIBLAnalysistempfile}
unset cmtbtagIBLAnalysistempfile
exit $cmtsetupstatus

