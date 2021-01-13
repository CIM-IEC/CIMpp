///////////////////////////////////////////////////////////
//  SteamTurbine.h
//  Implementation of the Class SteamTurbine
///////////////////////////////////////////////////////////

#ifndef STEAMTURBINE_H
#define STEAMTURBINE_H

#include "IEC61970/Base/Domain/Seconds.h"
#include "IEC61970/Base/Domain/Float.h"
#include "IEC61970/Base/Generation/GenerationTrainingSimulation/PrimeMover.h"

namespace IEC61970
{
	namespace Base
	{
		namespace Generation
		{
			namespace GenerationTrainingSimulation
			{
				/**
				 * Steam turbine.
				 */
				class SteamTurbine : public IEC61970::Base::Generation::GenerationTrainingSimulation::PrimeMover
				{

				public:
					SteamTurbine();
					virtual ~SteamTurbine();
					/**
					 * Crossover time constant.
					 */
					IEC61970::Base::Domain::Seconds crossoverTC;
					/**
					 * First reheater time constant.
					 */
					IEC61970::Base::Domain::Seconds reheater1TC;
					/**
					 * Second reheater time constant.
					 */
					IEC61970::Base::Domain::Seconds reheater2TC;
					/**
					 * Fraction of power from shaft 1 high pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft1PowerHP;
					/**
					 * Fraction of power from shaft 1 intermediate pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft1PowerIP;
					/**
					 * Fraction of power from shaft 1 first low pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft1PowerLP1;
					/**
					 * Fraction of power from shaft 1 second low pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft1PowerLP2;
					/**
					 * Fraction of power from shaft 2 high pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft2PowerHP;
					/**
					 * Fraction of power from shaft 2 intermediate pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft2PowerIP;
					/**
					 * Fraction of power from shaft 2 first low pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft2PowerLP1;
					/**
					 * Fraction of power from shaft 2 second low pressure turbine output.
					 */
					IEC61970::Base::Domain::Float shaft2PowerLP2;
					/**
					 * Steam chest time constant.
					 */
					IEC61970::Base::Domain::Seconds steamChestTC;

				};

			}

		}

	}

}
#endif // STEAMTURBINE_H
