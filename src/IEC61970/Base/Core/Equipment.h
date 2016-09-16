///////////////////////////////////////////////////////////
//  Equipment.h
//  Implementation of the Class Equipment
//  Created on:      28-Jan-2016 12:44:16
///////////////////////////////////////////////////////////

#if !defined(EA_1296321D_F39F_4788_A80D_E31AE245F480__INCLUDED_)
#define EA_1296321D_F39F_4788_A80D_E31AE245F480__INCLUDED_

#include "IEC61970/Base/Domain/Boolean.h"
#include "IEC61970/Base/Core/PowerSystemResource.h"

namespace IEC61970
{
	namespace Base
	{
		namespace Core
		{
			/**
			 * The parts of a power system that are physical devices, electronic or mechanical.
			 */
			class Equipment : public IEC61970::Base::Core::PowerSystemResource
			{

			public:
				Equipment();
				virtual ~Equipment();
				/**
				 * The single instance of equipment represents multiple pieces of equipment that
				 * have been modeled together as an aggregate.  Examples would be power
				 * transformers or synchronous machines operating in parallel modeled as a single
				 * aggregate power transformer or aggregate synchronous machine.  This is not to
				 * be used to indicate equipment that is part of a group of interdependent
				 * equipment produced by a network production program.  
				 */
				IEC61970::Base::Domain::Boolean aggregate;
				/**
				 * If true, the equipment is in service.
				 */
				IEC61970::Base::Domain::Boolean inService;
				/**
				 * If true, the equipment is normally in service.
				 */
				IEC61970::Base::Domain::Boolean normallyInService;

			};

		}

	}

}
#endif // !defined(EA_1296321D_F39F_4788_A80D_E31AE245F480__INCLUDED_)