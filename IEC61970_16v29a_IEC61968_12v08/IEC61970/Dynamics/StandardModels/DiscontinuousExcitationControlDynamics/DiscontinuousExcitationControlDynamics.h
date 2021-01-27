///////////////////////////////////////////////////////////
//  DiscontinuousExcitationControlDynamics.h
//  Implementation of the Class DiscontinuousExcitationControlDynamics
//  Original author: ppbr003
///////////////////////////////////////////////////////////

#ifndef DISCONTINUOUSEXCITATIONCONTROLDYNAMICS_H
#define DISCONTINUOUSEXCITATIONCONTROLDYNAMICS_H

#include "IEC61970/Dynamics/StandardModels/DynamicsFunctionBlock.h"
#include "IEC61970/Dynamics/StandardModels/ExcitationSystemDynamics/ExcitationSystemDynamics.h"
#include "IEC61970/Dynamics/StandardInterconnections/RemoteInputSignal.h"

namespace IEC61970
{
	namespace Dynamics
	{
		namespace StandardModels
		{
			namespace DiscontinuousExcitationControlDynamics
			{
				/**
				 * Discontinuous excitation control function block whose behaviour is described by
				 * reference to a standard model <font color="#0f0f0f">or by definition of a user-
				 * defined model</font>.
				 */
				class DiscontinuousExcitationControlDynamics : public IEC61970::Dynamics::StandardModels::DynamicsFunctionBlock
				{

				public:
					DiscontinuousExcitationControlDynamics();
					virtual ~DiscontinuousExcitationControlDynamics();
					/**
					 * Excitation system model with which this discontinuous excitation control model
					 * is associated.
					 */
					IEC61970::Dynamics::StandardModels::ExcitationSystemDynamics::ExcitationSystemDynamics *ExcitationSystemDynamics;
					/**
					 * Remote input signal used by this discontinuous excitation control system model.
					 */
					IEC61970::Dynamics::StandardInterconnections::RemoteInputSignal *RemoteInputSignal;

				};

			}

		}

	}

}
#endif // DISCONTINUOUSEXCITATIONCONTROLDYNAMICS_H
