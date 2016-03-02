# echo "cleanup btagIBLAnalysis btagIBLAnalysis-00-00-00 in /afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.7.3/CMT/v1r25p20140131; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtbtagIBLAnalysistempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtbtagIBLAnalysistempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena  $* >${cmtbtagIBLAnalysistempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/work/d/dguest/athena/tagging/marie-setup/marie/xAODAthena  $* >${cmtbtagIBLAnalysistempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmtbtagIBLAnalysistempfile}
  unset cmtbtagIBLAnalysistempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmtbtagIBLAnalysistempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmtbtagIBLAnalysistempfile}
unset cmtbtagIBLAnalysistempfile
return $cmtcleanupstatus

