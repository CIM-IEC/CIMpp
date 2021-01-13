///////////////////////////////////////////////////////////
//  VoltageLevel.h
//  Implementation of the Class VoltageLevel
///////////////////////////////////////////////////////////

#ifndef VOLTAGELEVEL_H
#define VOLTAGELEVEL_H

#include <list>

#include "IEC61970/Base/Domain/Voltage.h"
#include "IEC61970/Base/Core/EquipmentContainer.h"
#include "IEC61970/Base/Core/Bay.h"
#include "IEC61970/Base/Core/BaseVoltage.h"

namespace IEC61970
{
	namespace Base
	{
		namespace Core
		{
			/**
			 * A collection of equipment at one common system voltage forming a switchgear.
			 * The equipment typically consist of breakers, busbars, instrumentation, control,
			 * regulation and protection devices as well as assemblies of all these.
			 */
			class VoltageLevel : public IEC61970::Base::Core::EquipmentContainer
			{

			public:
				VoltageLevel();
				virtual ~VoltageLevel();
				/**
				 * The bus bar's high voltage limit
				 */
				IEC61970::Base::Domain::Voltage highVoltageLimit;
				/**
				 * The bus bar's low voltage limit
				 */
				IEC61970::Base::Domain::Voltage lowVoltageLimit;
				/**
				 * The bays within this voltage level.
				 */
				std::list<IEC61970::Base::Core::Bay*> Bays;
				/**
				 * The base voltage used for all equipment within the voltage level.
				 */
				IEC61970::Base::Core::BaseVoltage *BaseVoltage;

			};

		}

	}

}
#endif // VOLTAGELEVEL_H
