#pragma once
#include "PayCheck.h"

class PayClassification
{
public:
	PayClassification();
	virtual ~PayClassification();

	virtual float payday(PayCheck &payCheck) = 0;
};

