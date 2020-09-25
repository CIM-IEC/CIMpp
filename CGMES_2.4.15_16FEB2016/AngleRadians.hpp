#ifndef AngleRadians_H
#define AngleRadians_H

#include <string>
#include <istream>

#include "BaseClass.hpp"

namespace CIMPP
{
	class AngleRadians : public BaseClass
	{
	
	public:
		AngleRadians();
		virtual ~AngleRadians();
		AngleRadians(long double value);
		static const BaseClassDefiner declare();
		AngleRadians& operator=(long double &rop);
		AngleRadians& operator+=(const AngleRadians& rhs);
		AngleRadians& operator-=(const AngleRadians& rhs);
		AngleRadians& operator*=(const AngleRadians& rhs);
		AngleRadians& operator/=(const AngleRadians& rhs);
		friend std::istream& operator>>(std::istream& lop, AngleRadians& rop);
		operator long double();
	
		long double value = 0.0;
		bool initialized = false;
	
		static const char debugName[];
		virtual const char* debugString();
		
		static void addConstructToMap(std::unordered_map<std::string, BaseClass* (*)()>& factory_map);
		static void addPrimitiveAssignFnsToMap(std::unordered_map<std::string, assign_function>&);
		static void addClassAssignFnsToMap(std::unordered_map<std::string, class_assign_function>&);
	};
}
#endif
