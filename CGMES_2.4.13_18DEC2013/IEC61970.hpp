#ifndef IEC61970_H
#define IEC61970_H
#include "ACDCConverter.hpp"
#include "ACDCConverterDCTerminal.hpp"
#include "ACDCTerminal.hpp"
#include "ACLineSegment.hpp"
#include "Accumulator.hpp"
#include "AccumulatorLimit.hpp"
#include "AccumulatorLimitSet.hpp"
#include "AccumulatorReset.hpp"
#include "AccumulatorValue.hpp"
#include "ActivePower.hpp"
#include "ActivePowerLimit.hpp"
#include "ActivePowerPerFrequency.hpp"
#include "Analog.hpp"
#include "AnalogControl.hpp"
#include "AnalogLimit.hpp"
#include "AnalogLimitSet.hpp"
#include "AnalogValue.hpp"
#include "AngleDegrees.hpp"
#include "AngleRadians.hpp"
#include "ApparentPower.hpp"
#include "ApparentPowerLimit.hpp"
#include "Area.hpp"
#include "AsynchronousMachine.hpp"
#include "AsynchronousMachineDynamics.hpp"
#include "AsynchronousMachineEquivalentCircuit.hpp"
#include "AsynchronousMachineTimeConstantReactance.hpp"
#include "AsynchronousMachineUserDefined.hpp"
#include "BaseVoltage.hpp"
#include "BasicIntervalSchedule.hpp"
#include "Bay.hpp"
#include "Breaker.hpp"
#include "BusNameMarker.hpp"
#include "BusbarSection.hpp"
#include "Capacitance.hpp"
#include "CapacitancePerLength.hpp"
#include "Command.hpp"
#include "Conductance.hpp"
#include "ConductingEquipment.hpp"
#include "Conductor.hpp"
#include "ConformLoad.hpp"
#include "ConformLoadGroup.hpp"
#include "ConformLoadSchedule.hpp"
#include "ConnectivityNode.hpp"
#include "ConnectivityNodeContainer.hpp"
#include "Connector.hpp"
#include "Control.hpp"
#include "ControlArea.hpp"
#include "ControlAreaGeneratingUnit.hpp"
#include "CoordinateSystem.hpp"
#include "CsConverter.hpp"
#include "CurrentFlow.hpp"
#include "CurrentLimit.hpp"
#include "Curve.hpp"
#include "CurveData.hpp"
#include "DCBaseTerminal.hpp"
#include "DCBreaker.hpp"
#include "DCBusbar.hpp"
#include "DCChopper.hpp"
#include "DCConductingEquipment.hpp"
#include "DCConverterUnit.hpp"
#include "DCDisconnector.hpp"
#include "DCEquipmentContainer.hpp"
#include "DCGround.hpp"
#include "DCLine.hpp"
#include "DCLineSegment.hpp"
#include "DCNode.hpp"
#include "DCSeriesDevice.hpp"
#include "DCShunt.hpp"
#include "DCSwitch.hpp"
#include "DCTerminal.hpp"
#include "DCTopologicalIsland.hpp"
#include "DCTopologicalNode.hpp"
#include "DateTime.hpp"
#include "DayType.hpp"
#include "Decimal.hpp"
#include "Diagram.hpp"
#include "DiagramLayoutVersion.hpp"
#include "DiagramObject.hpp"
#include "DiagramObjectGluePoint.hpp"
#include "DiagramObjectPoint.hpp"
#include "DiagramObjectStyle.hpp"
#include "DiagramStyle.hpp"
#include "DiscExcContIEEEDEC1A.hpp"
#include "DiscExcContIEEEDEC2A.hpp"
#include "DiscExcContIEEEDEC3A.hpp"
#include "Disconnector.hpp"
#include "DiscontinuousExcitationControlDynamics.hpp"
#include "DiscontinuousExcitationControlUserDefined.hpp"
#include "Discrete.hpp"
#include "DiscreteValue.hpp"
#include "DynamicsFunctionBlock.hpp"
#include "DynamicsVersion.hpp"
#include "EarthFaultCompensator.hpp"
#include "EnergyArea.hpp"
#include "EnergyConsumer.hpp"
#include "EnergySchedulingType.hpp"
#include "EnergySource.hpp"
#include "Equipment.hpp"
#include "EquipmentBoundaryVersion.hpp"
#include "EquipmentContainer.hpp"
#include "EquipmentVersion.hpp"
#include "EquivalentBranch.hpp"
#include "EquivalentEquipment.hpp"
#include "EquivalentInjection.hpp"
#include "EquivalentNetwork.hpp"
#include "EquivalentShunt.hpp"
#include "ExcAC1A.hpp"
#include "ExcAC2A.hpp"
#include "ExcAC3A.hpp"
#include "ExcAC4A.hpp"
#include "ExcAC5A.hpp"
#include "ExcAC6A.hpp"
#include "ExcAC8B.hpp"
#include "ExcANS.hpp"
#include "ExcAVR1.hpp"
#include "ExcAVR2.hpp"
#include "ExcAVR3.hpp"
#include "ExcAVR4.hpp"
#include "ExcAVR5.hpp"
#include "ExcAVR7.hpp"
#include "ExcBBC.hpp"
#include "ExcCZ.hpp"
#include "ExcDC1A.hpp"
#include "ExcDC2A.hpp"
#include "ExcDC3A.hpp"
#include "ExcDC3A1.hpp"
#include "ExcELIN1.hpp"
#include "ExcELIN2.hpp"
#include "ExcHU.hpp"
#include "ExcIEEEAC1A.hpp"
#include "ExcIEEEAC2A.hpp"
#include "ExcIEEEAC3A.hpp"
#include "ExcIEEEAC4A.hpp"
#include "ExcIEEEAC5A.hpp"
#include "ExcIEEEAC6A.hpp"
#include "ExcIEEEAC7B.hpp"
#include "ExcIEEEAC8B.hpp"
#include "ExcIEEEDC1A.hpp"
#include "ExcIEEEDC2A.hpp"
#include "ExcIEEEDC3A.hpp"
#include "ExcIEEEDC4B.hpp"
#include "ExcIEEEST1A.hpp"
#include "ExcIEEEST2A.hpp"
#include "ExcIEEEST3A.hpp"
#include "ExcIEEEST4B.hpp"
#include "ExcIEEEST5B.hpp"
#include "ExcIEEEST6B.hpp"
#include "ExcIEEEST7B.hpp"
#include "ExcOEX3T.hpp"
#include "ExcPIC.hpp"
#include "ExcREXS.hpp"
#include "ExcSCRX.hpp"
#include "ExcSEXS.hpp"
#include "ExcSK.hpp"
#include "ExcST1A.hpp"
#include "ExcST2A.hpp"
#include "ExcST3A.hpp"
#include "ExcST4B.hpp"
#include "ExcST6B.hpp"
#include "ExcST7B.hpp"
#include "ExcitationSystemDynamics.hpp"
#include "ExcitationSystemUserDefined.hpp"
#include "ExternalNetworkInjection.hpp"
#include "Float.hpp"
#include "FossilFuel.hpp"
#include "Frequency.hpp"
#include "GenICompensationForGenJ.hpp"
#include "GeneratingUnit.hpp"
#include "GeographicalLocationVersion.hpp"
#include "GeographicalRegion.hpp"
#include "GovCT1.hpp"
#include "GovCT2.hpp"
#include "GovGAST.hpp"
#include "GovGAST1.hpp"
#include "GovGAST2.hpp"
#include "GovGAST3.hpp"
#include "GovGAST4.hpp"
#include "GovGASTWD.hpp"
#include "GovHydro1.hpp"
#include "GovHydro2.hpp"
#include "GovHydro3.hpp"
#include "GovHydro4.hpp"
#include "GovHydroDD.hpp"
#include "GovHydroFrancis.hpp"
#include "GovHydroIEEE0.hpp"
#include "GovHydroIEEE2.hpp"
#include "GovHydroPID.hpp"
#include "GovHydroPID2.hpp"
#include "GovHydroPelton.hpp"
#include "GovHydroR.hpp"
#include "GovHydroWEH.hpp"
#include "GovHydroWPID.hpp"
#include "GovSteam0.hpp"
#include "GovSteam1.hpp"
#include "GovSteam2.hpp"
#include "GovSteamCC.hpp"
#include "GovSteamEU.hpp"
#include "GovSteamFV2.hpp"
#include "GovSteamFV3.hpp"
#include "GovSteamFV4.hpp"
#include "GovSteamIEEE1.hpp"
#include "GovSteamSGO.hpp"
#include "GrossToNetActivePowerCurve.hpp"
#include "Ground.hpp"
#include "GroundDisconnector.hpp"
#include "GroundingImpedance.hpp"
#include "HydroGeneratingUnit.hpp"
#include "HydroPowerPlant.hpp"
#include "HydroPump.hpp"
#include "IdentifiedObject.hpp"
#include "Inductance.hpp"
#include "InductancePerLength.hpp"
#include "Junction.hpp"
#include "Length.hpp"
#include "Limit.hpp"
#include "LimitSet.hpp"
#include "Line.hpp"
#include "LinearShuntCompensator.hpp"
#include "LoadAggregate.hpp"
#include "LoadArea.hpp"
#include "LoadBreakSwitch.hpp"
#include "LoadComposite.hpp"
#include "LoadDynamics.hpp"
#include "LoadGenericNonLinear.hpp"
#include "LoadGroup.hpp"
#include "LoadMotor.hpp"
#include "LoadResponseCharacteristic.hpp"
#include "LoadStatic.hpp"
#include "LoadUserDefined.hpp"
#include "Location.hpp"
#include "Measurement.hpp"
#include "MeasurementValue.hpp"
#include "MeasurementValueQuality.hpp"
#include "MeasurementValueSource.hpp"
#include "MechLoad1.hpp"
#include "MechanicalLoadDynamics.hpp"
#include "MechanicalLoadUserDefined.hpp"
#include "Money.hpp"
#include "MonthDay.hpp"
#include "MutualCoupling.hpp"
#include "NonConformLoad.hpp"
#include "NonConformLoadGroup.hpp"
#include "NonConformLoadSchedule.hpp"
#include "NonlinearShuntCompensator.hpp"
#include "NonlinearShuntCompensatorPoint.hpp"
#include "NuclearGeneratingUnit.hpp"
#include "OperationalLimit.hpp"
#include "OperationalLimitSet.hpp"
#include "OperationalLimitType.hpp"
#include "OverexcLim2.hpp"
#include "OverexcLimIEEE.hpp"
#include "OverexcLimX1.hpp"
#include "OverexcLimX2.hpp"
#include "OverexcitationLimiterDynamics.hpp"
#include "OverexcitationLimiterUserDefined.hpp"
#include "PFVArControllerType1Dynamics.hpp"
#include "PFVArControllerType1UserDefined.hpp"
#include "PFVArControllerType2Dynamics.hpp"
#include "PFVArControllerType2UserDefined.hpp"
#include "PFVArType1IEEEPFController.hpp"
#include "PFVArType1IEEEVArController.hpp"
#include "PFVArType2Common1.hpp"
#include "PFVArType2IEEEPFController.hpp"
#include "PFVArType2IEEEVArController.hpp"
#include "PU.hpp"
#include "PerCent.hpp"
#include "PerLengthDCLineParameter.hpp"
#include "PetersenCoil.hpp"
#include "PhaseTapChanger.hpp"
#include "PhaseTapChangerAsymmetrical.hpp"
#include "PhaseTapChangerLinear.hpp"
#include "PhaseTapChangerNonLinear.hpp"
#include "PhaseTapChangerSymmetrical.hpp"
#include "PhaseTapChangerTable.hpp"
#include "PhaseTapChangerTablePoint.hpp"
#include "PhaseTapChangerTabular.hpp"
#include "PositionPoint.hpp"
#include "PowerSystemResource.hpp"
#include "PowerSystemStabilizerDynamics.hpp"
#include "PowerSystemStabilizerUserDefined.hpp"
#include "PowerTransformer.hpp"
#include "PowerTransformerEnd.hpp"
#include "ProprietaryParameterDynamics.hpp"
#include "ProtectedSwitch.hpp"
#include "Pss1.hpp"
#include "Pss1A.hpp"
#include "Pss2B.hpp"
#include "Pss2ST.hpp"
#include "Pss5.hpp"
#include "PssELIN2.hpp"
#include "PssIEEE1A.hpp"
#include "PssIEEE2B.hpp"
#include "PssIEEE3B.hpp"
#include "PssIEEE4B.hpp"
#include "PssPTIST1.hpp"
#include "PssPTIST3.hpp"
#include "PssSB4.hpp"
#include "PssSH.hpp"
#include "PssSK.hpp"
#include "PssWECC.hpp"
#include "Quality61850.hpp"
#include "RaiseLowerCommand.hpp"
#include "RatioTapChanger.hpp"
#include "RatioTapChangerTable.hpp"
#include "RatioTapChangerTablePoint.hpp"
#include "Reactance.hpp"
#include "ReactiveCapabilityCurve.hpp"
#include "ReactivePower.hpp"
#include "RegularIntervalSchedule.hpp"
#include "RegularTimePoint.hpp"
#include "RegulatingCondEq.hpp"
#include "RegulatingControl.hpp"
#include "RegulationSchedule.hpp"
#include "RemoteInputSignal.hpp"
#include "ReportingGroup.hpp"
#include "Resistance.hpp"
#include "ResistancePerLength.hpp"
#include "RotatingMachine.hpp"
#include "RotatingMachineDynamics.hpp"
#include "RotationSpeed.hpp"
#include "Season.hpp"
#include "SeasonDayTypeSchedule.hpp"
#include "Seconds.hpp"
#include "SeriesCompensator.hpp"
#include "SetPoint.hpp"
#include "ShuntCompensator.hpp"
#include "Simple_Float.hpp"
#include "SolarGeneratingUnit.hpp"
#include "StateVariablesVersion.hpp"
#include "StaticVarCompensator.hpp"
#include "StationSupply.hpp"
#include "SteadyStateHypothesisVersion.hpp"
#include "StringMeasurement.hpp"
#include "StringMeasurementValue.hpp"
#include "SubGeographicalRegion.hpp"
#include "SubLoadArea.hpp"
#include "Substation.hpp"
#include "Susceptance.hpp"
#include "SvInjection.hpp"
#include "SvPowerFlow.hpp"
#include "SvShuntCompensatorSections.hpp"
#include "SvStatus.hpp"
#include "SvTapStep.hpp"
#include "SvVoltage.hpp"
#include "Switch.hpp"
#include "SwitchSchedule.hpp"
#include "SynchronousMachine.hpp"
#include "SynchronousMachineDetailed.hpp"
#include "SynchronousMachineDynamics.hpp"
#include "SynchronousMachineEquivalentCircuit.hpp"
#include "SynchronousMachineSimplified.hpp"
#include "SynchronousMachineTimeConstantReactance.hpp"
#include "SynchronousMachineUserDefined.hpp"
#include "TapChanger.hpp"
#include "TapChangerControl.hpp"
#include "TapChangerTablePoint.hpp"
#include "TapSchedule.hpp"
#include "Temperature.hpp"
#include "Terminal.hpp"
#include "TextDiagramObject.hpp"
#include "ThermalGeneratingUnit.hpp"
#include "TieFlow.hpp"
#include "TopologicalIsland.hpp"
#include "TopologicalNode.hpp"
#include "TopologyBoundaryVersion.hpp"
#include "TopologyVersion.hpp"
#include "TransformerEnd.hpp"
#include "TurbLCFB1.hpp"
#include "TurbineGovernorDynamics.hpp"
#include "TurbineGovernorUserDefined.hpp"
#include "TurbineLoadControllerDynamics.hpp"
#include "TurbineLoadControllerUserDefined.hpp"
#include "UnderexcLim2Simplified.hpp"
#include "UnderexcLimIEEE1.hpp"
#include "UnderexcLimIEEE2.hpp"
#include "UnderexcLimX1.hpp"
#include "UnderexcLimX2.hpp"
#include "UnderexcitationLimiterDynamics.hpp"
#include "UnderexcitationLimiterUserDefined.hpp"
#include "VAdjIEEE.hpp"
#include "VCompIEEEType1.hpp"
#include "VCompIEEEType2.hpp"
#include "ValueAliasSet.hpp"
#include "ValueToAlias.hpp"
#include "VisibilityLayer.hpp"
#include "Voltage.hpp"
#include "VoltageAdjusterDynamics.hpp"
#include "VoltageAdjusterUserDefined.hpp"
#include "VoltageCompensatorDynamics.hpp"
#include "VoltageCompensatorUserDefined.hpp"
#include "VoltageLevel.hpp"
#include "VoltageLimit.hpp"
#include "VoltagePerReactivePower.hpp"
#include "VolumeFlowRate.hpp"
#include "VsCapabilityCurve.hpp"
#include "VsConverter.hpp"
#include "WindAeroConstIEC.hpp"
#include "WindAeroLinearIEC.hpp"
#include "WindContCurrLimIEC.hpp"
#include "WindContPType3IEC.hpp"
#include "WindContPType4aIEC.hpp"
#include "WindContPType4bIEC.hpp"
#include "WindContPitchAngleIEC.hpp"
#include "WindContQIEC.hpp"
#include "WindContRotorRIEC.hpp"
#include "WindDynamicsLookupTable.hpp"
#include "WindGenTurbineType1IEC.hpp"
#include "WindGenTurbineType2IEC.hpp"
#include "WindGenTurbineType3IEC.hpp"
#include "WindGenTurbineType3aIEC.hpp"
#include "WindGenTurbineType3bIEC.hpp"
#include "WindGenType4IEC.hpp"
#include "WindGeneratingUnit.hpp"
#include "WindMechIEC.hpp"
#include "WindPitchContEmulIEC.hpp"
#include "WindPlantDynamics.hpp"
#include "WindPlantFreqPcontrolIEC.hpp"
#include "WindPlantIEC.hpp"
#include "WindPlantReactiveControlIEC.hpp"
#include "WindPlantUserDefined.hpp"
#include "WindProtectionIEC.hpp"
#include "WindTurbineType1or2Dynamics.hpp"
#include "WindTurbineType1or2IEC.hpp"
#include "WindTurbineType3or4Dynamics.hpp"
#include "WindTurbineType3or4IEC.hpp"
#include "WindTurbineType4aIEC.hpp"
#include "WindTurbineType4bIEC.hpp"
#include "WindType1or2UserDefined.hpp"
#include "WindType3or4UserDefined.hpp"
#include "UnknownType.hpp"
#endif