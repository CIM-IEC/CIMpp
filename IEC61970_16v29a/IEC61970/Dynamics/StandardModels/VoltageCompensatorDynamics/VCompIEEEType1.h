///////////////////////////////////////////////////////////
//  VCompIEEEType1.h
//  Implementation of the Class VCompIEEEType1
//  Original author: tsaxton
///////////////////////////////////////////////////////////

#ifndef VCOMPIEEETYPE1_H
#define VCOMPIEEETYPE1_H

#include "IEC61970/Base/Domain/PU.h"
#include "IEC61970/Base/Domain/Seconds.h"
#include "IEC61970/Dynamics/StandardModels/VoltageCompensatorDynamics/VoltageCompensatorDynamics.h"

namespace IEC61970
{
	namespace Dynamics
	{
		namespace StandardModels
		{
			namespace VoltageCompensatorDynamics
			{
				/**
				 * <font color="#0f0f0f">The class represents the terminal voltage transducer and
				 * the load compensator as defined in the IEEE Std 421.5-2005, Section 4. This
				 * model is common to all excitation system models described in the IEEE Standard.
				 * </font>
				 * 
				 * Reference: IEEE Standard 421.5-2005 Section 4. 
				 */
				class VCompIEEEType1 : public IEC61970::Dynamics::StandardModels::VoltageCompensatorDynamics::VoltageCompensatorDynamics
				{

				public:
					VCompIEEEType1();
					virtual ~VCompIEEEType1();
					/**
					 * <font color="#0f0f0f">Resistive component of compensation of a generator (Rc).
					 * </font>
					 */
					IEC61970::Base::Domain::PU rc;
					/**
					 * <font color="#0f0f0f">Time constant which is used for the combined voltage
					 * sensing and compensation signal (Tr).</font>
					 */
					IEC61970::Base::Domain::Seconds tr;
					/**
					 * <font color="#0f0f0f">Reactive component of compensation of a generator (Xc).
					 * </font>
					 */
					IEC61970::Base::Domain::PU xc;

				};

			}

		}

	}

}
#endif // VCOMPIEEETYPE1_H
