///////////////////////////////////////////////////////////
//  SeriesCompensator.h
//  Implementation of the Class SeriesCompensator
///////////////////////////////////////////////////////////

#ifndef SERIESCOMPENSATOR_H
#define SERIESCOMPENSATOR_H

#include "IEC61970/Base/Domain/Resistance.h"
#include "IEC61970/Base/Domain/Boolean.h"
#include "IEC61970/Base/Domain/CurrentFlow.h"
#include "IEC61970/Base/Domain/Voltage.h"
#include "IEC61970/Base/Domain/Reactance.h"
#include "IEC61970/Base/Core/ConductingEquipment.h"

namespace IEC61970
{
	namespace Base
	{
		namespace Wires
		{
			/**
			 * A Series Compensator is a series capacitor or reactor or an AC transmission
			 * line without charging susceptance.  It is a two terminal device.
			 */
			class SeriesCompensator : public IEC61970::Base::Core::ConductingEquipment
			{

			public:
				SeriesCompensator();
				virtual ~SeriesCompensator();
				/**
				 * Positive sequence resistance.
				 */
				IEC61970::Base::Domain::Resistance r;
				/**
				 * Zero sequence resistance.
				 */
				IEC61970::Base::Domain::Resistance r0;
				/**
				 * Describe if a metal oxide varistor (mov) for over voltage protection is
				 * configured at the series compensator.
				 */
				IEC61970::Base::Domain::Boolean varistorPresent;
				/**
				 * The maximum current the varistor is designed to handle at specified duration.
				 */
				IEC61970::Base::Domain::CurrentFlow varistorRatedCurrent;
				/**
				 * The dc voltage at which the varistor start conducting.
				 */
				IEC61970::Base::Domain::Voltage varistorVoltageThreshold;
				/**
				 * Positive sequence reactance.
				 */
				IEC61970::Base::Domain::Reactance x;
				/**
				 * Zero sequence reactance.
				 */
				IEC61970::Base::Domain::Reactance x0;

			};

		}

	}

}
#endif // SERIESCOMPENSATOR_H
