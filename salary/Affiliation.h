#pragma once
#include "PayCheck.h"

class Affiliation
{
public:
	Affiliation();
	virtual ~Affiliation();

	virtual float getAllFees(const PayCheck &payCheck) = 0;
};

