///////////////////////////////////////////////////////////
//  AngleDegrees.cpp
//  Implementation of the Class AngleDegrees
///////////////////////////////////////////////////////////

#include "AngleDegrees.h"

using IEC61970::Base::Domain::AngleDegrees;


AngleDegrees::AngleDegrees(){

}



AngleDegrees::~AngleDegrees(){

}


const IEC61970::Base::Domain::UnitMultiplier AngleDegrees::multiplier = IEC61970::Base::Domain::UnitMultiplier::none;
const IEC61970::Base::Domain::UnitSymbol AngleDegrees::unit = IEC61970::Base::Domain::UnitSymbol::deg;
