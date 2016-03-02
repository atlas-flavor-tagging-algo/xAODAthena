# echo "cleanup btagIBLAnalysis btagIBLAnalysis-00-00-00 in /afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.7.3/CMT/v1r25p20140131
endif
source ${CMTROOT}/mgr/setup.csh
set cmtbtagIBLAnalysistempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtbtagIBLAnalysistempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena  $* >${cmtbtagIBLAnalysistempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena  $* >${cmtbtagIBLAnalysistempfile}"
  set cmtcleanupstatus=2
  /bin/rm -f ${cmtbtagIBLAnalysistempfile}
  unset cmtbtagIBLAnalysistempfile
  exit $cmtcleanupstatus
endif
set cmtcleanupstatus=0
source ${cmtbtagIBLAnalysistempfile}
if ( $status != 0 ) then
  set cmtcleanupstatus=2
endif
/bin/rm -f ${cmtbtagIBLAnalysistempfile}
unset cmtbtagIBLAnalysistempfile
exit $cmtcleanupstatus

