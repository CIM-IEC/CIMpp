///////////////////////////////////////////////////////////
//  PFVArType2Common1.h
//  Implementation of the Class PFVArType2Common1
//  Original author: pcha006
///////////////////////////////////////////////////////////

#ifndef PFVARTYPE2COMMON1_H
#define PFVARTYPE2COMMON1_H

#include "IEC61970/Base/Domain/Boolean.h"
#include "IEC61970/Base/Domain/PU.h"
#include "IEC61970/Dynamics/StandardModels/PFVArControllerType2Dynamics/PFVArControllerType2Dynamics.h"

namespace IEC61970
{
	namespace Dynamics
	{
		namespace StandardModels
		{
			namespace PFVArControllerType2Dynamics
			{
				/**
				 * Power factor / Reactive power regulator. This model represents the power factor
				 * or reactive power controller such as the Basler SCP-250. The controller
				 * measures power factor or reactive power (PU on generator rated power) and
				 * compares it with the operator's set point.
				 */
				class PFVArType2Common1 : public IEC61970::Dynamics::StandardModels::PFVArControllerType2Dynamics::PFVArControllerType2Dynamics
				{

				public:
					PFVArType2Common1();
					virtual ~PFVArType2Common1();
					/**
					 * Selector (J).
					 * true = control mode for reactive power
					 * false = control mode for power factor.
					 */
					IEC61970::Base::Domain::Boolean j;
					/**
					 * Reset gain (Ki).
					 */
					IEC61970::Base::Domain::PU ki;
					/**
					 * Proportional gain (Kp).
					 */
					IEC61970::Base::Domain::PU kp;
					/**
					 * Output limit (max).
					 */
					IEC61970::Base::Domain::PU max;
					/**
					 * Reference value of reactive power or power factor (Ref).
					 * The reference value is initialised by this model. This initialisation may
					 * override the value exchanged by this attribute to represent a plant operator's
					 * change of the reference setting.
					 */
					IEC61970::Base::Domain::PU ref;

				};

			}

		}

	}

}
#endif // PFVARTYPE2COMMON1_H
