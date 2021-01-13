///////////////////////////////////////////////////////////
//  DiscreteValue.h
//  Implementation of the Class DiscreteValue
///////////////////////////////////////////////////////////

#ifndef DISCRETEVALUE_H
#define DISCRETEVALUE_H

#include "IEC61970/Base/Domain/Integer.h"
#include "IEC61970/Base/Meas/Command.h"
#include "IEC61970/Base/Meas/MeasurementValue.h"

namespace IEC61970
{
	namespace Base
	{
		namespace Meas
		{
			/**
			 * DiscreteValue represents a discrete MeasurementValue.
			 */
			class DiscreteValue : public IEC61970::Base::Meas::MeasurementValue
			{

			public:
				DiscreteValue();
				virtual ~DiscreteValue();
				/**
				 * The value to supervise.
				 */
				IEC61970::Base::Domain::Integer value;
				/**
				 * The Control variable associated with the MeasurementValue.
				 */
				IEC61970::Base::Meas::Command *Command;

			};

		}

	}

}
#endif // DISCRETEVALUE_H
