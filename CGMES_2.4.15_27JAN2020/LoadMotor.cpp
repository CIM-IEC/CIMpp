#include <sstream>
#include "IdentifiedObject.hpp"
#include "LoadMotor.hpp"

#include "LoadAggregate.hpp"
#include "Simple_Float.hpp"
#include "Simple_Float.hpp"
#include "PU.hpp"
#include "PU.hpp"
#include "PU.hpp"
#include "PU.hpp"
#include "Seconds.hpp"
#include "Seconds.hpp"
#include "Seconds.hpp"
#include "Simple_Float.hpp"
#include "PU.hpp"
#include "Seconds.hpp"
#include "Seconds.hpp"

using namespace CIMPP;

LoadMotor::LoadMotor(): LoadAggregate(nullptr) {};

LoadMotor::~LoadMotor() {};


bool assign_LoadAggregate_LoadMotor(BaseClass*, BaseClass*);
bool assign_LoadMotor_LoadAggregate(BaseClass* BaseClass_ptr1, BaseClass* BaseClass_ptr2) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                element->LoadAggregate = dynamic_cast<LoadAggregate*>(BaseClass_ptr2);
                if(element->LoadAggregate != nullptr)
                        return assign_LoadAggregate_LoadMotor(BaseClass_ptr2, BaseClass_ptr1);
        }
        return false;
}
















bool assign_LoadMotor_pfrac(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->pfrac;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_lfac(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->lfac;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_ls(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->ls;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_lp(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->lp;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_lpp(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->lpp;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_ra(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->ra;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_tpo(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->tpo;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_tppo(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->tppo;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_h(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->h;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_d(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->d;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_vt(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->vt;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_tv(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->tv;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

bool assign_LoadMotor_tbkr(std::stringstream &buffer, BaseClass* BaseClass_ptr1) {
	if(LoadMotor* element = dynamic_cast<LoadMotor*>(BaseClass_ptr1)) {
                buffer >> element->tbkr;
                if(buffer.fail())
                        return false;
                else
                        return true;
        }
        else
                return false;
}

namespace CIMPP {
	BaseClass* LoadMotor_factory() {
		return new LoadMotor;
	}
}

void LoadMotor::addConstructToMap(std::unordered_map<std::string, BaseClass* (*)()>& factory_map) {
	factory_map.insert(std::make_pair(std::string("cim:LoadMotor"), &LoadMotor_factory));
}

void LoadMotor::addPrimitiveAssignFnsToMap(std::unordered_map<std::string, assign_function>& assign_map) {
		assign_map.insert(std::make_pair(std::string("cim:LoadMotor.pfrac"), &assign_LoadMotor_pfrac));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.lfac"), &assign_LoadMotor_lfac));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.ls"), &assign_LoadMotor_ls));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.lp"), &assign_LoadMotor_lp));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.lpp"), &assign_LoadMotor_lpp));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.ra"), &assign_LoadMotor_ra));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.tpo"), &assign_LoadMotor_tpo));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.tppo"), &assign_LoadMotor_tppo));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.h"), &assign_LoadMotor_h));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.d"), &assign_LoadMotor_d));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.vt"), &assign_LoadMotor_vt));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.tv"), &assign_LoadMotor_tv));
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.tbkr"), &assign_LoadMotor_tbkr));
}

void LoadMotor::addClassAssignFnsToMap(std::unordered_map<std::string, class_assign_function>& assign_map) {
	assign_map.insert(std::make_pair(std::string("cim:LoadMotor.LoadAggregate"), &assign_LoadMotor_LoadAggregate));
													}

const char LoadMotor::debugName[] = "LoadMotor";
const char* LoadMotor::debugString()
{
	return LoadMotor::debugName;
}

const BaseClassDefiner LoadMotor::declare()
{
	return BaseClassDefiner(LoadMotor::addConstructToMap, LoadMotor::addPrimitiveAssignFnsToMap, LoadMotor::addClassAssignFnsToMap, LoadMotor::debugName);
}


