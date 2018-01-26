#pragma once
#include "Affiliation.h"
class NoAffiliation :
	public Affiliation
{
public:
	NoAffiliation();
	virtual ~NoAffiliation();

	// Inherited via Affiliation
	virtual float getAllFees() override;
};

