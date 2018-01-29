#pragma once
#include "PayCheck.h"

class PayMethod
{
public:
	PayMethod();
	virtual ~PayMethod();

	virtual void pay(const PayCheck &payCheck) = 0;
};

