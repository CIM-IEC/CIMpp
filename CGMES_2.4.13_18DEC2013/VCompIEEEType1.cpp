#include <sstream>
#include "VoltageCompensatorDynamics.hpp"
#include "VCompIEEEType1.hpp"

#include "PU.hpp"
#include "PU.hpp"
#include "Seconds.hpp"

using namespace CIMPP;

VCompIEEEType1::VCompIEEEType1() {};

VCompIEEEType1::~VCompIEEEType1() {};






bool assign_VCompIEEEType1_rc(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(VCompIEEEType1* element = dynamic_cast<VCompIEEEType1*>(BaseClass_ptr1)) {
                buffer >> element->rc;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_VCompIEEEType1_xc(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(VCompIEEEType1* element = dynamic_cast<VCompIEEEType1*>(BaseClass_ptr1)) {
                buffer >> element->xc;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_VCompIEEEType1_tr(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(VCompIEEEType1* element = dynamic_cast<VCompIEEEType1*>(BaseClass_ptr1)) {
                buffer >> element->tr;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

namespace CIMPP {
	BaseClass* VCompIEEEType1_factory() {
		return new VCompIEEEType1;
	}
}

void VCompIEEEType1::addConstructToMap(std::unordered_map<std::string, BaseClass* (*)()>& factory_map) {
	factory_map.insert(std::make_pair(std::string("cim:VCompIEEEType1"), &VCompIEEEType1_factory));
}

void VCompIEEEType1::addPrimitiveAssignFnsToMap(std::unordered_map<std::string, assign_function>& assign_map) {
	assign_map.insert(std::make_pair(std::string("cim:VCompIEEEType1.rc"), &assign_VCompIEEEType1_rc));
	assign_map.insert(std::make_pair(std::string("cim:VCompIEEEType1.xc"), &assign_VCompIEEEType1_xc));
	assign_map.insert(std::make_pair(std::string("cim:VCompIEEEType1.tr"), &assign_VCompIEEEType1_tr));
}

void VCompIEEEType1::addClassAssignFnsToMap(std::unordered_map<std::string, class_assign_function>& assign_map) {
			}

const char VCompIEEEType1::debugName[] = "VCompIEEEType1";
const char* VCompIEEEType1::debugString()
{
	return VCompIEEEType1::debugName;
}

const BaseClassDefiner VCompIEEEType1::declare()
{
	return BaseClassDefiner(VCompIEEEType1::addConstructToMap, VCompIEEEType1::addPrimitiveAssignFnsToMap, VCompIEEEType1::addClassAssignFnsToMap, VCompIEEEType1::debugName);
}


