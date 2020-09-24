#include <sstream>
#include "WindTurbineType3or4Dynamics.hpp"
#include "WindTurbineType3or4IEC.hpp"

#include "WindContCurrLimIEC.hpp"
#include "WindContQIEC.hpp"
#include "WindProtectionIEC.hpp"

using namespace CIMPP;

WindTurbineType3or4IEC::WindTurbineType3or4IEC() {};

WindTurbineType3or4IEC::~WindTurbineType3or4IEC() {};


bool assign_WindContCurrLimIEC_WindTurbineType3or4IEC(BaseClass*, BaseClass*);
bool assign_WindTurbineType3or4IEC_WindContCurrLimIEC(BaseClass* BaseClass_ptr1, BaseClass* BaseClass_ptr2) {
	if(WindTurbineType3or4IEC* element = dynamic_cast<WindTurbineType3or4IEC*>(BaseClass_ptr1)) {
                element->WindContCurrLimIEC = dynamic_cast<WindContCurrLimIEC*>(BaseClass_ptr2);
                if(element->WindContCurrLimIEC != nullptr)
                        return assign_WindContCurrLimIEC_WindTurbineType3or4IEC(BaseClass_ptr2, BaseClass_ptr1);
        }
        return false;
}

bool assign_WindContQIEC_WindTurbineType3or4IEC(BaseClass*, BaseClass*);
bool assign_WindTurbineType3or4IEC_WIndContQIEC(BaseClass* BaseClass_ptr1, BaseClass* BaseClass_ptr2) {
	if(WindTurbineType3or4IEC* element = dynamic_cast<WindTurbineType3or4IEC*>(BaseClass_ptr1)) {
                element->WIndContQIEC = dynamic_cast<WindContQIEC*>(BaseClass_ptr2);
                if(element->WIndContQIEC != nullptr)
                        return assign_WindContQIEC_WindTurbineType3or4IEC(BaseClass_ptr2, BaseClass_ptr1);
        }
        return false;
}

bool assign_WindProtectionIEC_WindTurbineType3or4IEC(BaseClass*, BaseClass*);
bool assign_WindTurbineType3or4IEC_WindProtectionIEC(BaseClass* BaseClass_ptr1, BaseClass* BaseClass_ptr2) {
	if(WindTurbineType3or4IEC* element = dynamic_cast<WindTurbineType3or4IEC*>(BaseClass_ptr1)) {
                element->WindProtectionIEC = dynamic_cast<WindProtectionIEC*>(BaseClass_ptr2);
                if(element->WindProtectionIEC != nullptr)
                        return assign_WindProtectionIEC_WindTurbineType3or4IEC(BaseClass_ptr2, BaseClass_ptr1);
        }
        return false;
}





namespace CIMPP {
	BaseClass* WindTurbineType3or4IEC_factory() {
		return new WindTurbineType3or4IEC;
	}
}

void WindTurbineType3or4IEC::addConstructToMap(std::unordered_map<std::string, BaseClass* (*)()>& factory_map) {
	factory_map.insert(std::make_pair(std::string("cim:WindTurbineType3or4IEC"), &WindTurbineType3or4IEC_factory));
}

void WindTurbineType3or4IEC::addPrimitiveAssignFnsToMap(std::unordered_map<std::string, assign_function>& assign_map) {
			}

void WindTurbineType3or4IEC::addClassAssignFnsToMap(std::unordered_map<std::string, class_assign_function>& assign_map) {
	assign_map.insert(std::make_pair(std::string("cim:WindTurbineType3or4IEC.WindContCurrLimIEC"), &assign_WindTurbineType3or4IEC_WindContCurrLimIEC));
	assign_map.insert(std::make_pair(std::string("cim:WindTurbineType3or4IEC.WIndContQIEC"), &assign_WindTurbineType3or4IEC_WIndContQIEC));
	assign_map.insert(std::make_pair(std::string("cim:WindTurbineType3or4IEC.WindProtectionIEC"), &assign_WindTurbineType3or4IEC_WindProtectionIEC));
}

const char WindTurbineType3or4IEC::debugName[] = "WindTurbineType3or4IEC";
const char* WindTurbineType3or4IEC::debugString()
{
	return WindTurbineType3or4IEC::debugName;
}

const BaseClassDefiner WindTurbineType3or4IEC::declare()
{
	return BaseClassDefiner(WindTurbineType3or4IEC::addConstructToMap, WindTurbineType3or4IEC::addPrimitiveAssignFnsToMap, WindTurbineType3or4IEC::addClassAssignFnsToMap, WindTurbineType3or4IEC::debugName);
}


