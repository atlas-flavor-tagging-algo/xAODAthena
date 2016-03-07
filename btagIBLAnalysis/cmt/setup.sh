# echo "setup btagIBLAnalysis btagIBLAnalysis-00-00-00 in /afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/x86_64-slc6-gcc48-opt/20.7.3/CMT/v1r25p20140131; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtbtagIBLAnalysistempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtbtagIBLAnalysistempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe setup -sh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena  -no_cleanup $* >${cmtbtagIBLAnalysistempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe setup -sh -pack=btagIBLAnalysis -version=btagIBLAnalysis-00-00-00 -path=/afs/cern.ch/user/d/dguest/afswork/athena/tagging/marie-setup/marie/xAODAthena  -no_cleanup $* >${cmtbtagIBLAnalysistempfile}"
  cmtsetupstatus=2
  /bin/rm -f ${cmtbtagIBLAnalysistempfile}
  unset cmtbtagIBLAnalysistempfile
  return $cmtsetupstatus
fi
cmtsetupstatus=0
. ${cmtbtagIBLAnalysistempfile}
if test $? != 0 ; then
  cmtsetupstatus=2
fi
/bin/rm -f ${cmtbtagIBLAnalysistempfile}
unset cmtbtagIBLAnalysistempfile
return $cmtsetupstatus

