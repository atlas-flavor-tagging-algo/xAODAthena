#Mon Mar  7 18:02:35 2016"""Automatically generated. DO NOT EDIT please"""
from GaudiKernel.GaudiHandles import *
from GaudiKernel.Proxy.Configurable import *

class btagIBLAnalysisAlg( ConfigurableAlgorithm ) :
  __slots__ = { 
    'OutputLevel' : 0, # int
    'Enable' : True, # bool
    'ErrorMax' : 1, # int
    'ErrorCount' : 0, # int
    'AuditAlgorithms' : False, # bool
    'AuditInitialize' : False, # bool
    'AuditReinitialize' : False, # bool
    'AuditRestart' : False, # bool
    'AuditExecute' : False, # bool
    'AuditFinalize' : False, # bool
    'AuditBeginRun' : False, # bool
    'AuditEndRun' : False, # bool
    'AuditStart' : False, # bool
    'AuditStop' : False, # bool
    'MonitorService' : 'MonitorSvc', # str
    'RegisterForContextService' : False, # bool
    'EvtStore' : ServiceHandle('StoreGateSvc'), # GaudiHandle
    'DetStore' : ServiceHandle('StoreGateSvc/DetectorStore'), # GaudiHandle
    'UserStore' : ServiceHandle('UserDataSvc/UserDataSvc'), # GaudiHandle
    'THistSvc' : ServiceHandle('THistSvc/THistSvc'), # GaudiHandle
    'RootStreamName' : '/', # str
    'RootDirName' : '', # str
    'HistNamePrefix' : '', # str
    'HistNamePostfix' : '', # str
    'HistTitlePrefix' : '', # str
    'HistTitlePostfix' : '', # str
    'Stream' : 'BTAGSTREAM', # str
    'JetCleaningTool' : PrivateToolHandle('JetCleaningTool/JetCleaningTool'), # GaudiHandle
    'JetCalibrationTool' : PublicToolHandle(''), # GaudiHandle
    'InDetTrackSelectionTool' : PublicToolHandle(''), # GaudiHandle
    'TrackVertexAssociationTool' : PublicToolHandle(''), # GaudiHandle
    'TrackToVertexIPEstimator' : PublicToolHandle('Trk::ITrackToVertexIPEstimator'), # GaudiHandle
    'JVTtool' : PublicToolHandle(''), # GaudiHandle
    'EssentialInfo' : True, # bool
    'ReduceInfo' : False, # bool
    'Rel20' : False, # bool
    'DoMSV' : False, # bool
    'doSMT' : False, # bool
    'CalibrateJets' : True, # bool
    'CleanJets' : True, # bool
    'GRLname' : '', # str
    'JetCollectionName' : 'AntiKt4LCTopoJets', # str
    'JetPtCut' : 20000.0, # float
    'TriggerLogic' : '', # str
  }
  _propertyDocDct = { 
    'HistTitlePrefix' : """ The prefix for the histogram THx title """,
    'DetStore' : """ Handle to a StoreGateSvc/DetectorStore instance: it will be used to retrieve data during the course of the job """,
    'RegisterForContextService' : """ The flag to enforce the registration for Algorithm Context Service """,
    'RootStreamName' : """ Name of the output ROOT stream (file) that the THistSvc uses """,
    'HistNamePostfix' : """ The postfix for the histogram THx name """,
    'UserStore' : """ Handle to a UserDataSvc/UserDataSvc instance: it will be used to retrieve user data during the course of the job """,
    'HistTitlePostfix' : """ The postfix for the histogram THx title """,
    'EvtStore' : """ Handle to a StoreGateSvc instance: it will be used to retrieve data during the course of the job """,
    'THistSvc' : """ Handle to a THistSvc instance: it will be used to write ROOT objects to ROOT files """,
    'HistNamePrefix' : """ The prefix for the histogram THx name """,
    'RootDirName' : """ Name of the ROOT directory inside the ROOT file where the histograms will go """,
  }
  def __init__(self, name = Configurable.DefaultName, **kwargs):
      super(btagIBLAnalysisAlg, self).__init__(name)
      for n,v in kwargs.items():
         setattr(self, n, v)
  def getDlls( self ):
      return 'btagIBLAnalysis'
  def getType( self ):
      return 'btagIBLAnalysisAlg'
  pass # class btagIBLAnalysisAlg
