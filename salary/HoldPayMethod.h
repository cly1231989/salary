#pragma once
#include "PayMethod.h"
class HoldPayMethod :
	public PayMethod
{
public:
	HoldPayMethod();
	virtual ~HoldPayMethod();

	// Inherited via PayMethod
	virtual void pay(const PayCheck & payCheck) override;
};

