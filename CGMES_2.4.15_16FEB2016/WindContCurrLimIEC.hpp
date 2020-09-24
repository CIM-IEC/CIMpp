#ifndef WindContCurrLimIEC_H
#define WindContCurrLimIEC_H

#include "IdentifiedObject.hpp"
#include <list>
#include "Boolean.hpp"
#include "Float.hpp"


#include "PU.hpp"
#include "Boolean.hpp"
#include "Seconds.hpp"

namespace CIMPP {


class WindTurbineType3or4IEC;
class WindDynamicsLookupTable;
	/*
	Current limitation model.  The current limitation model combines the physical limits.  Reference: IEC Standard 61400-27-1 Section 6.6.5.7.
	*/
	class WindContCurrLimIEC: public IdentifiedObject
	{

	public:
					CIMPP::PU imax; 	/* Maximum continuous current at the wind turbine terminals (). It is type dependent parameter. Default: nullptr */
					CIMPP::PU imaxdip; 	/* Maximum current during voltage dip at the wind turbine terminals (). It is project dependent parameter. Default: nullptr */
					CIMPP::Boolean mdfslim; 	/* Limitation of type 3 stator current  ():  - false=0: total current limitation,  - true=1: stator current limitation).  It is type dependent parameter. Default: false */
					CIMPP::Boolean mqpri; 	/* Prioritisation of q control during LVRT (): - true = 1: reactive power priority, - false = 0: active power priority.  It is project dependent parameter. Default: false */
					CIMPP::Seconds tufilt; 	/* Voltage measurement filter time constant (). It is type dependent parameter. Default: nullptr */
					CIMPP::WindTurbineType3or4IEC* WindTurbineType3or4IEC; 	/* Wind turbine type 3 or 4 model with which this wind control current limitation model is associated. Default: 0 */
					std::list<CIMPP::WindDynamicsLookupTable*> WindDynamicsLookupTable; 	/* The current control limitation model with which this wind dynamics lookup table is associated. Default: 0 */
				
		static const char debugName[];
		virtual const char* debugString();
		
		/* constructor initialising all attributes to null */
		WindContCurrLimIEC();
		virtual ~WindContCurrLimIEC();
	
		static void addConstructToMap(std::unordered_map<std::string, BaseClass* (*)()>& factory_map);
		static void addPrimitiveAssignFnsToMap(std::unordered_map<std::string, assign_function>&);
		static void addClassAssignFnsToMap(std::unordered_map<std::string, class_assign_function>&);
		static const BaseClassDefiner declare();

	};

	BaseClass* WindContCurrLimIEC_factory();
}
#endif
